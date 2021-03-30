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

string ImageVisitor::getPosition(ProcessingParser::PositionContext *pos) {
	if(pos->DECIMAL_LITERAL()) {
		return pos->getText();
	} else {
		return to_string(ofGetFrameNum());
	}
}

void ImageVisitor::visitBlockStatement(ProcessingParser::BlockStatementContext *blockStatement) {
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
			sketch->drawThree(funcName, three->position(0)->getText(), 
			three->position(1)->getText(), three->position(2)->getText());
		} else if (draw -> drawFourDecimal()) {
			auto four = draw -> drawFourDecimal();
			string funcName = four->drawFourDecimalShape()->getText();
			sketch->drawFour(funcName, getPosition(four->position(0)), 
			getPosition(four->position(1)), getPosition(four->position(2)),
			getPosition(four->position(3)));
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