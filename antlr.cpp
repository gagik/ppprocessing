#include <iostream>

#include "antlr4-runtime.h"
#include "libs/ProcessingLexer.h"
#include "libs/ProcessingParser.h"
#include "ImageVisitor.h"
#include "ofMain.h"
#include "ofApp.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("input.pde");
    // ofEndShape(true);
    
    ANTLRInputStream input(stream);
    ProcessingLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ProcessingParser parser(&tokens);    
    
    ProcessingParser::SketchContext* tree = parser.sketch();

    ImageVisitor visitor;
    Scene* scene = visitor.visitFile(tree);
    // scene.draw();	

    ofSetupOpenGL(1024,768,OF_WINDOW);
    ofApp* app = new ofApp();
    app->scene = scene;
    ofRunApp(app);

    return 0;
}