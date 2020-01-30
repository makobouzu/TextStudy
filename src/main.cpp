#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
    settings.setGLVersion(4, 0);
    settings.setSize(600, 600);
    ofCreateWindow(settings);
    ofRunApp(std::make_shared<ofApp>());
}
