#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
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
    // for (auto element : scene->getDraw()) {
    //     if (element.getAction() == Action::Draw) {
    //        vector<string> args = element.getArguments();
    //        string shapeFunction = args.at(0);
    //        if (shapeFunction.compare("circle") == 0) {
    //            int x = stoi(args.at(1)), y = stoi(args.at(2)), r = stoi(args.at(3));
    //            ofDrawCircle(x, y, r);
    //            if(strokeColor != -1) {
    //                ofNoFill();
    //                ofDrawCircle(x, y, r);
    //            }
    //        } else if (shapeFunction.compare("ellipse") == 0) {
    //             int x = stoi(args.at(1)), y = stoi(args.at(2)), w = stoi(args.at(3)), h = stoi(args.at(4));
    //             ofDrawEllipse(x, y, w, h);
    //             if(strokeColor != -1) {
    //                ofNoFill();
    //                ofDrawEllipse(x, y, w, h);
    //             }
    //        } else if (shapeFunction.compare("rect") == 0) {
    //             int x = stoi(args.at(1)), y = stoi(args.at(2)), w = stoi(args.at(3)), h = stoi(args.at(4));
    //             ofDrawRectangle(x, y, w, h);
    //             if(strokeColor != -1) {
    //                ofNoFill();
    //                ofDrawRectangle(x, y, w, h);
    //             }
    //        }
    //        else {
    //            break;
    //        }
    //     } else if (element.getAction() == Action::Color) {
    //        vector<string> args = element.getArguments();
    //        string colorFunction = args.at(0);
    //        if (colorFunction.compare("fill") == 0) {
    //             ofSetHexColor(stoi(args.at(1), 0, 16));
    //             ofFill();
    //        } else if (colorFunction.compare("stroke") == 0) {
    //             strokeColor = stoi(args.at(1), 0, 16);
    //        }
    //     } else {
    //         cout<<"fake"<<element.getAction();
    //     }
    // }
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
