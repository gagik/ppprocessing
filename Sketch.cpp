#include "Sketch.h"

using namespace std;

Sketch::Sketch(string name, bool shouldGenerate) {
    projectName = name;
    generateMode = shouldGenerate;
    strokeColor = -1;
    threeFunc["circle"] = ofDrawCircle;
    
    fourFunc["rect"] = ofDrawRectangle;
    fourFunc["ellipse"] = ofDrawEllipse;
    fourFunc["line"] = ofDrawLine;
};

void Sketch::drawFour(string funcName, string a, string b, string c, string d) {
    int x = stoi(a), y = stoi(b), w = stoi(c), h = stoi(d);
    fourFunc[funcName](x, y, w, h);
}

void Sketch::drawThree(string funcName, string a, string b, string c) {
    int x = stoi(a), y = stoi(b), r = stoi(c);
    threeFunc[funcName](x, y, r); 
}

void Sketch::drawOne(string funcName, string a) {
    if (funcName == "fill") {
        ofSetHexColor(stoi(a, 0, 16));
        ofFill();
    } else if (funcName == "stroke") {
        int strokeColor = stoi(a, 0, 16);
    }
}
