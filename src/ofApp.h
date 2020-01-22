#pragma once

#include "ofMain.h"
#include "ofxChoreograph.h"

class ofApp : public ofBaseApp{
    std::shared_ptr<choreograph::Timeline>    timeline_;
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void startTweening();
    
private:
    ofTrueTypeFont font;
    
    std::string input  = "hello world";
    std::string output = ""; //output = input + randomString(n)
    

    bool s = false;
    choreograph::Timeline&     timeline(){ return *timeline_;}
    choreograph::Output<int>   number;
};
