#ifndef SCENE_INCLUDED
#define SCENE_INCLUDED
#include <algorithm>
#include <vector>
#include <string>
#include "libs/CImg.h"

using namespace std;
using namespace cimg_library;

enum Action { 
    Draw, 
    Write, 
    NoAction,
    Color, 
};
enum Shape { Circle, Square, NoShape }; 
enum Scene_Size { Big, Medium, Small }; 
enum X_Position { Left, X_Center, Right };  
enum Y_Position { Top, Y_Center, Bottom };  

class Element {
    public:
		// Element(Action action, string size, string color, string x, string y, Shape shape);template<class T>
		Element(Action action, vector<string> arguments);
		// Element(Action action);
        
        Action      getAction();
        X_Position  getX();
        Y_Position  getY();
        Scene_Size  getSize();
        string      getText();
        Shape       getShape();
        vector<string> getArguments();

        static Shape convertShape(string shape);
    
    private:
        Action      _action;
        X_Position  _x_position;
        Y_Position  _y_position; 
        Scene_Size  _size;   
        string      _text;
        Shape       _shape;
        vector<string> arguments;
        
        Scene_Size convertSize(string size);
        void setPosition(string x, string y);
};

class Scene {
    public:
        Scene();   
        void draw();
        void setSetup (vector<Element> elements);
        void setDraw (vector<Element> elements);
        vector<Element> getSetup();
        vector<Element> getDraw();

    private:
        string              name;
        vector<Element>     drawElements;
        vector<Element>     setupElements;
        
        static const int    FONT_BIG = 53;
        static const int    FONT_MEDIUM = 23;
        static const int    FONT_SMALL = 13;
};

#endif