#include <string>
#include "antlr4-runtime.h"
#include "libs/SceneBaseVisitor.h"
#include "ProcessingParser.h"
#include "Scene.h"

class  ImageVisitor : SceneBaseVisitor {
public:    
    Scene* visitFile(ProcessingParser::SketchContext *ctx);
	string visitColor(ProcessingParser::ColorLiteralContext *ctx);
	antlrcpp::Any visitAction(ProcessingParser::ApiFunctionContext *ctx);	
	antlrcpp::Any visitShape(ProcessingParser::DrawShapeContext *ctx);
};

