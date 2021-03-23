#include "ImageVisitor.h"
using namespace std;

Scene* ImageVisitor::visitFile(ProcessingParser::SketchContext *ctx) {
    vector<Element> elements;
    ProcessingParser::StaticModeContext* sCtx = ctx->staticMode();
	cout << "Found " << sCtx->blockStatement().size() << " commands\n";
    for (auto blockStatement : sCtx->blockStatement()) {  
		for (auto expression : blockStatement->statement()->expression()) {    
			if (expression->apiFunction()) {
				antlrcpp::Any el = visitAction(expression->apiFunction());
				elements.push_back(el);		
			}
		}
    }    

    Scene* result = new Scene();
	result->setSetup(elements);

	// antlrcpp::Any r = result;
    
	return result;
}

antlrcpp::Any ImageVisitor::visitAction(ProcessingParser::ApiFunctionContext *ctx) {
	Action action;
	vector<string> arguments;
	
	if (ctx -> apiDraw()) {
		action = Draw;
		ProcessingParser::ApiDrawContext* draw = ctx -> apiDraw();
		// string shape = visitShape(ctx-> apiDraw()->drawShape());
		// arguments.push_back(shape);
		if (draw -> circleFunction()) {
			arguments.push_back("circle");
			auto circle = draw -> circleFunction();
			arguments.push_back(circle->position(0)->getText());
			arguments.push_back(circle->position(1)->getText());
			arguments.push_back(circle->position(2)->getText());
		} else if (draw -> drawFourDecimal()) {
			auto ellipse = draw -> drawFourDecimal();
			arguments.push_back(ellipse->drawFourDecimalShape()->getText());
			arguments.push_back(ellipse->position(0)->getText());
			arguments.push_back(ellipse->position(1)->getText());
			arguments.push_back(ellipse->position(2)->getText());
			arguments.push_back(ellipse->position(3)->getText());
		}

		return Element(action, arguments);
	} else if (ctx -> apiColor()) {
		action = Color;
		ProcessingParser::ApiColorContext* draw = ctx -> apiColor();
		// cout<<"Color function"<<draw->colorFunction()->getText();
		arguments.push_back(draw->colorFunction()->getText());
		arguments.push_back(visitColor(draw -> colorLiteral()));

		return Element(action, arguments);
	} else {
		cout<<"neither functions satisfied";
	}
	return Element(action, arguments);
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