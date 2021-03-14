#include <string>
#include "antlr4-runtime.h"
#include "libs/SceneBaseVisitor.h"
#include "Scene.h"
#include "ProcessingParser.h"


class  ImageVisitor : SceneBaseVisitor {
public:    
    antlrcpp::Any visitFile(ProcessingParser::SketchContext *ctx);

	antlrcpp::Any visitAction(ProcessingParser::ApiFunctionContext *ctx);	

	antlrcpp::Any visitShape(ProcessingParser::DrawShapeContext *ctx);
};

