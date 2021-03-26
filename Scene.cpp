#include "Scene.h"

using namespace std;

Element::Element(Action action, vector<string> args) {    
    _action = action;
    arguments = args; 
};

vector<string> Element::getArguments() {
    return arguments;
}

Action Element::getAction() {
    return _action;
}

Scene::Scene() {
};

void Scene::setSetup(vector<Element> elements) {
    setupElements = elements;
}

void Scene::setDraw(vector<Element> elements) {
    drawElements = elements;
}


vector<Element> Scene::getSetup() {
    return setupElements;
}
vector<Element> Scene::getDraw() {
    return drawElements;
}
