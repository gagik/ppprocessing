#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    ifstream stream;
    stream.open("input.pde");
    
    ANTLRInputStream input(stream);
    ProcessingLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ProcessingParser parser(&tokens);    
    
    ProcessingParser::SketchContext* tree = parser.sketch();
    scene = visitor.visitFile(tree);

    ofSetFrameRate(60);
    ofBackground(255);

    struct stat file_stat;
    int err = stat("input.pde", &file_stat);
    if (err != 0) {
        cout << err;
        return;
    }
    mTime = file_stat.st_mtime;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    struct stat file_stat;
    int err = stat("input.pde", &file_stat);
    if (err != 0) {
        cout << err;
        return;
    }
    if (file_stat.st_mtime > mTime) {
        ifstream stream;
        // if (!shouldSwitch) {
        stream.open("input.pde");
        // } else {
        //     stream.open("another.pde");
        // }
        // shouldSwitch = !shouldSwitch;

        ANTLRInputStream input(stream);
        ProcessingLexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        ProcessingParser parser(&tokens);    
        
        ProcessingParser::SketchContext* tree = parser.sketch();
        scene = visitor.visitFile(tree);
        stream.close();
    }
    mTime = file_stat.st_mtime;

    ofSetColor(ofColor::black);
    for (auto element : scene->getSetup()) {
        if (element.getAction() == Action::Draw) {
           vector<string> args = element.getArguments();
           string shapeFunction = args.at(0);
           if (shapeFunction.compare("circle") == 0) {
               ofDrawCircle(stoi(args.at(1)),stoi(args.at(2)), stoi(args.at(3)));
           }
           else if (shapeFunction.compare("ellipse") == 0) {
               ofDrawEllipse(stoi(args.at(1)),stoi(args.at(2)), stoi(args.at(3)), stoi(args.at(4)));
           }
            else if (shapeFunction.compare("rect") == 0) {
               ofDrawRectangle(stoi(args.at(1)),stoi(args.at(2)), stoi(args.at(3)), stoi(args.at(4)));
           }
           else {
               break;
           }
        } else if (element.getAction() == Action::Color) {
           vector<string> args = element.getArguments();
           string colorFunction = args.at(0);
           if (colorFunction.compare("fill") == 0) {
                ofSetHexColor(stoi(args.at(1), 0, 16));
                ofFill();
           }
        } else {
            cout<<"fake"<<element.getAction();
        }
    }
    // ofDrawCircle(1500,1500,100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    // shouldSwitch = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
