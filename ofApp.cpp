#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    srand (time(NULL));
    ofSetFrameRate(60);
    ofBackground(255);
    
    struct stat file_stat;
    int err = stat("input.pde", &file_stat);
    if (err != 0) {
        cout << err;
        return;
    }
    
    mTime = file_stat.st_mtime;
    strokeColor = -1;

    updateFile();
}

void ofApp::updateFile(){
    ifstream stream;
    stream.open("input.pde");
    
    ANTLRInputStream input(stream);
    ProcessingLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ProcessingParser parser(&tokens);    
    
    ProcessingParser::SketchContext* tree = parser.sketch();
    visitor.visitFile(tree);
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
        updateFile();
    }
    mTime = file_stat.st_mtime;

    ofSetColor(ofColor::black);
    updateFile();
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
