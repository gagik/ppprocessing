#include "Sketch.h"

using namespace std;

Sketch::Sketch(string name, bool shouldGenerate) {
    projectName = name;
    generateMode = shouldGenerate;
};

void Sketch::drawFour(string funcName, string a, string b, string c, string d) {
    int x = stoi(a), y = stoi(b), w = stoi(c), h = stoi(d);
    if(funcName == "rect") { 
        ofDrawRectangle(x,y,w,h); 
    }
    else if(funcName == "ellipse") { 
        ofDrawEllipse(x,y,w,h); 
    }
}

void Sketch::drawThree(string funcName, string a, string b, string c) {
    int x = stoi(a), y = stoi(b), r = stoi(c);
    if(funcName == "circle") { 
        ofDrawCircle(x, y, r);
    }
}