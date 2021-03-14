#include "ImageVisitor.h"

using namespace std;

antlrcpp::Any ImageVisitor::visitFile(ProcessingParser::SketchContext *ctx) {
    vector<Element> elements;
    ProcessingParser::StaticModeContext* sCtx = ctx->staticMode();
	cout << sCtx->blockStatement().size();
    for (auto blockStatement : sCtx->blockStatement()) {  
		for (auto expression : blockStatement->statement()->expression()) {    
			if (expression->apiFunction()) {
				antlrcpp::Any el = visitAction(expression->apiFunction());
				elements.push_back(el);		
			}
		}
    }    
        	
    antlrcpp::Any result = Scene("fun"/*ctx->name()->NAME()->getText()*/, elements);
    
	return result;
}

antlrcpp::Any ImageVisitor::visitAction(ProcessingParser::ApiFunctionContext *ctx) {
	Action action;
	
	if (ctx -> apiDraw()) {
		action = Draw;
		ProcessingParser::ApiDrawContext* draw = ctx -> apiDraw();
		Shape shape = visitShape(ctx-> apiDraw()->drawShape());
		cout << "stuff:";
		cout << draw->position(0)->getText();
		return Element(action, "big", "red", draw->position(0)->getText(), draw->position(1)->getText(), shape);
	}
	// if (ctx->DRAW()) {
	// 	action = Draw;
	// 	Shape shape = visitShape(ctx->shape());
	// 	return Element(action, ctx->size()->getText(), ctx->color()->getText(), ctx->position()->x->getText(), ctx->position()->y->getText(), shape);
	// }
	// else if (ctx->WRITE()) {
	// 	action = Write;
	// 	string text = ctx->STRING()->getText().substr(1, ctx->STRING()->getText().length() - 2);
	// 	return Element(action, ctx->size()->getText(), ctx->color()->getText(), ctx->position()->x->getText(), ctx->position()->y->getText(), text);
	// }
	// else
	// 	action = NoAction;

	return Element(action);
}

antlrcpp::Any ImageVisitor::visitShape(ProcessingParser::DrawShapeContext *ctx) {
	return Element::convertShape(ctx->getText());
}