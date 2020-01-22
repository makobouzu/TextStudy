#include "ofApp.h"


inline string randomString(int size){
    const string randomWord = "abcdefghijklmnopqrstuvwxyz1234567890!?#/$%&|*+-_";
    int rand = 37;
    string randomText;
    for(auto i = 0; i < size; ++i){
        char randomSelect = randomWord[ofRandom(rand)];
        randomText.push_back(randomSelect);
    }
    return randomText;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    //text settings
    ofTrueTypeFont::setGlobalDpi(72);
    font.load("/System/Library/Fonts/Helvetica.ttc", 60);
    font.setLineHeight(24);
    font.setLetterSpacing(1.0);
    
    //timeline
    timeline_ = make_shared<choreograph::Timeline>();
}

//--------------------------------------------------------------
void ofApp::update(){
    timeline().step(ofGetLastFrameTime());
    if(s){
        output = input.substr(0, number) + randomString(int(input.size()) - number);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    font.drawString(output, 100, 100);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        s = true;
        startTweening();
    }
    
    if(key == 'z'){
        output = "";
        number = 0;
        s = false;
    }
}

void ofApp::startTweening(){
    timeline().apply(&number).then<choreograph::RampTo>(int(input.size()), 1.0f, choreograph::EaseOutQuad());
}
