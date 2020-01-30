#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofGLFWWindowSettings settings;
    settings.setGLVersion(4, 0);
    ofCreateWindow(settings);
    ofRunApp(std::make_shared<ofApp>());
}
