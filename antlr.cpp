#include <iostream>

#include "ofMain.h"
#include "ofApp.h"

using namespace std;

int main(int argc, const char* argv[]) {
    ofSetupOpenGL(1024,768,OF_WINDOW);
    ofApp* app = new ofApp();
    ofRunApp(app);

    return 0;
}