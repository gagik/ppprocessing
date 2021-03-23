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
		if (draw -> CIRCLE()) {
			arguments.push_back("circle");
			arguments.push_back(draw->position(0)->getText());
			arguments.push_back(draw->position(1)->getText());
			arguments.push_back(draw->position(2)->getText());
		} else if (draw -> ELLIPSE()) {
			arguments.push_back("ellipse");
			arguments.push_back(draw->position(0)->getText());
			arguments.push_back(draw->position(1)->getText());
			arguments.push_back(draw->position(2)->getText());
			arguments.push_back(draw->position(3)->getText());
		}

		return Element(action, arguments);
	}

	return Element(action, arguments);
}

antlrcpp::Any ImageVisitor::visitShape(ProcessingParser::DrawShapeContext *ctx) {
	return ctx->getText();
}