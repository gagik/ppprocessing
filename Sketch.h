#ifndef SKETCH_INCLUDED
#define SKETCH_INCLUDED
#include "ofMain.h"
#include <vector>
#include <string>

using namespace std;
typedef void (*fourFloat)(float, float,float,float);
typedef void (*threeFloat)(float, float, float);
typedef void (*oneInt)(float);

class Sketch {
    public:
        Sketch(string name, bool shouldGenerate);
        // generic functions based on number of arguments
        void drawThree(string funcName, string a, string b, string c);
        void drawFour(string funcName, string a, string b, string c, string d);
        void drawOne(string funcName, string a);
    private:
        // generateMode determines whether the
        // the Sketch object should be saving ran
        // functions in a stringbuilder
        bool generateMode;
        // name of the file to save as .cpp
        string projectName;
        // current strokeColor
        int strokeColor;
        map<string, fourFloat> fourFunc;
        map<string, threeFloat> threeFunc;
        map<string, oneInt> oneFunc;
};

#endif