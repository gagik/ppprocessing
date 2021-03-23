#include "ofApp.h"

//--------------------------------------------------------------

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(ofColor::black);
    for (auto element : scene->getSetup()) {
        if (element.getAction() == Action::Draw) {
           vector<string> args = element.getArguments();
           string shape = args.at(0);
           if (shape.compare("circle") == 0) {
               ofDrawCircle(stoi(args.at(1)),stoi(args.at(2)), stoi(args.at(3)));
           }
           else if (shape.compare("ellipse") == 0) {
               ofDrawEllipse(stoi(args.at(1)),stoi(args.at(2)), stoi(args.at(3)), stoi(args.at(4)));
           }
           else {
               break;
           }
        } else {
            cout<<element.getAction();
        }
    }
    // ofDrawCircle(1500,1500,100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
