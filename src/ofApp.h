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
    
    std::string input  = "Hello World";
    std::string output = ""; //output = input + randomString(n)
    
    glm::vec2 pos1 = {100, 100};
    glm::vec2 pos2 = {100, 200};
    glm::vec2 pos3 = {100, 300};
    
    glm::vec2 typingBox = {30, -45};
    
    ofShader shader;
    ofRectangle textBox;
    

    bool s = false;
    choreograph::Timeline&     timeline(){ return *timeline_;}
    choreograph::Output<int>   number;
    choreograph::Output<float>   ypos;
};
