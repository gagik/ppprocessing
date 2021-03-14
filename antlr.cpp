#include <iostream>

#include "antlr4-runtime.h"
#include "libs/ProcessingLexer.h"
#include "libs/ProcessingParser.h"
#include "ImageVisitor.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char* argv[]) {
    std::ifstream stream;
    stream.open("input.pde");
    
    ANTLRInputStream input(stream);
    ProcessingLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ProcessingParser parser(&tokens);    
    
    ProcessingParser::SketchContext* tree = parser.sketch();

    ImageVisitor visitor;
    cout << "Started\n";
    Scene scene = visitor.visitFile(tree);
    scene.draw();	

    return 0;
}