#include "ImageVisitor.h"
using namespace std;
ImageVisitor::ImageVisitor() {
	sketch = new Sketch("test", false);
}

void ImageVisitor::visitFile(ProcessingParser::SketchContext *ctx) {
	if (ctx->activeMode()) {
		for (auto classBody : ctx->activeMode()->classBodyDeclaration()) { 
			if (classBody->memberDeclaration()) {
				auto method = classBody->memberDeclaration()->methodDeclaration();
				if (method) {
					string methodName = method->IDENTIFIER()->getText();
					ProcessingParser::BlockContext *methodBlock = method->methodBody()->block();
					if (methodName == "setup") {
						for (auto blockStatement : methodBlock->blockStatement()) {
							visitBlockStatement(blockStatement);
						}
					} else if (methodName == "draw") {
						for (auto blockStatement : methodBlock->blockStatement()) {
							visitBlockStatement(blockStatement);
						}
					}
				}
			}			
		} 
	} else if (ctx->staticMode()) {
		for (auto blockStatement : ctx->staticMode()->blockStatement()) {  
			visitBlockStatement(blockStatement);
		}   
	}
}

string ImageVisitor::getExpression(ProcessingParser::ExpressionContext *exp) {
	if(exp->mathFunction()) {
		auto math = exp->mathFunction();
		if (math->mathSinCos()) {
			if (math->mathSinCos()->SIN()) {
				return to_string(sin(stof(getExpression(math->mathSinCos()->expression()))));
			} else {
				return to_string(cos(stof(getExpression(math->mathSinCos()->expression()))));
			}
		}
	}
	else if(exp->MUL()) {
		return to_string(stof(getExpression(exp->expression(0))) * stof(getExpression(exp->expression(1))));
	}
	else if(exp->DIV()) {
		return to_string(stof(getExpression(exp->expression(0))) / stof(getExpression(exp->expression(1))));
	}
	else if(exp->SUBTRACT()) {
		return to_string(stof(getExpression(exp->expression(0))) - stof(getExpression(exp->expression(1))));
	}
	else if(exp->ADD()) {
		return to_string(stof(getExpression(exp->expression(0))) + stof(getExpression(exp->expression(1))));
	} 
	else if(exp->FRAMECOUNT()) {
		return to_string(ofGetFrameNum());
	} else if (exp->primary()->IDENTIFIER()) {
		return memory[exp->getText()];
	} else {
		return exp->getText();
	}
}

void ImageVisitor::visitBlockStatement(ProcessingParser::BlockStatementContext *blockStatement) {
	if (blockStatement->localVariableDefinition()) {
		string variableName = blockStatement->localVariableDefinition()->IDENTIFIER()->getText();
		float value = stof(getExpression(blockStatement->localVariableDefinition()->expression()));
		memory[variableName] = value;
		return;
	}
	
	for (auto expression : blockStatement->statement()->expression()) {  
		if (expression->apiFunction()) {
			visitAction(expression->apiFunction());
		}
	}
}

void ImageVisitor::visitAction(ProcessingParser::ApiFunctionContext *ctx) {
	vector<string> arguments;
	
	if (ctx -> apiDraw()) {
		ProcessingParser::ApiDrawContext* draw = ctx -> apiDraw();
		if (draw -> circleFunction()) {
			auto three = draw -> circleFunction();
			string funcName = "circle";
			sketch->drawThree(funcName, three->expression(0)->getText(), 
			three->expression(1)->getText(), three->expression(2)->getText());
		} else if (draw -> drawFourDecimal()) {
			auto four = draw -> drawFourDecimal();
			string funcName = four->drawFourDecimalShape()->getText();
			sketch->drawFour(funcName, getExpression(four->expression(0)), 
			getExpression(four->expression(1)), getExpression(four->expression(2)),
			getExpression(four->expression(3)));
		}
	} else if (ctx -> apiColor()) {
		ProcessingParser::ApiColorContext* draw = ctx -> apiColor();
		sketch->drawOne(draw->colorFunction()->getText(), visitColor(draw -> colorLiteral()));
	} else {
		cout<<"neither functions satisfied";
	}
}

string ImageVisitor::visitColor(ProcessingParser::ColorLiteralContext *ctx) {
	if (ctx->hexColorLiteral()) {
		return ctx->hexColorLiteral()->hexColorValue()->getText();
	}
	return "";
}


antlrcpp::Any ImageVisitor::visitShape(ProcessingParser::DrawShapeContext *ctx) {
	return ctx->getText();
}