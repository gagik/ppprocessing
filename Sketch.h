#ifndef SKETCH_INCLUDED
#define SKETCH_INCLUDED
#include "ofMain.h"
#include <vector>
#include <string>

using namespace std;

class Sketch {
    public:
        Sketch(string name, bool shouldGenerate);
        // generic functions based on number of arguments
        void drawThree(string funcName, string a, string b, string c);
        void drawFour(string funcName, string a, string b, string c, string d);

    private:
        // generateMode determines whether the
        // the Sketch object should be saving ran
        // functions in a stringbuilder
        bool generateMode;
        // name of the file to save as .cpp
        string projectName;
};

#endif