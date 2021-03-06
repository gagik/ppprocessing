#include <string>
#include <cmath>
#include "ofMain.h"
#include "antlr4-runtime.h"
#include "libs/SceneBaseVisitor.h"
#include "ProcessingParser.h"
#include "Sketch.h"

class  ImageVisitor : SceneBaseVisitor {
public:
	ImageVisitor();
    void visitFile(ProcessingParser::SketchContext *ctx);
	string visitColor(ProcessingParser::ColorLiteralContext *ctx);
	void visitBlockStatement(ProcessingParser::BlockStatementContext *blockStatement);
	void visitAction(ProcessingParser::ApiFunctionContext *ctx);		
	string getExpression(ProcessingParser::ExpressionContext *pos);
	antlrcpp::Any visitShape(ProcessingParser::DrawShapeContext *ctx);
private:
	Sketch *sketch;
	map<string, string> memory;
};

