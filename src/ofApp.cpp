#include "ofApp.h"


inline string randomString(int size){
    const string randomWord = "abcdefghijklmnopqrstuvwxyz1234567890!?#/$%&|*+-_{}[]~¥=()";
    int rand = 46;
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
    font.load("/System/Library/Fonts/Helvetica.ttc", 60, true, true, true);
    font.setLineHeight(24);
    font.setLetterSpacing(1.0);
    
    //shader settings
    shader.load("shader.vert", "shader.frag");
    textBox = font.getStringBoundingBox(input, pos3.x - textBoxMargin, pos3.y - textBoxMargin);
    textBox.setWidth(textBox.getWidth() + textBoxMargin*2);
    textBox.setHeight(textBox.getHeight() + textBoxMargin*2);
    ypos = textBox.getHeight();
    
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
    
    
    //random effect
    font.drawString(output, pos1.x, pos1.y);
    
    
    //typing box effect
    ofRectangle b = ofRectangle(pos2.x + font.stringWidth(input.substr(0, number)) + margin, pos2.y, typingBox.x, typingBox.y);
    if(number == 0 || number == input.size()){
        b.setWidth(0);
        b.setHeight(0);
    }else{
        b.setWidth(typingBox.x);
        b.setHeight(typingBox.y);
    }
    ofDrawRectangle(b);
    font.drawString(input.substr(0, number), pos2.x, pos2.y);
    
    
    //typing text effect
    ofPushStyle();
    ofRectangle t = ofRectangle(pos3.x + font.stringWidth(input.substr(0, number)) + margin, pos3.y, typingText.x, typingText.y);
    if(number == input.size()){
        t.setWidth(0);
        t.setHeight(0);
    }else{
        t.setWidth(typingText.x);
        t.setHeight(typingText.y);
    }
    ofSetColor(255, 255 * cos(10 * ofGetElapsedTimef()));
    ofDrawRectangle(t);
    ofPopStyle();
    font.drawString(input.substr(0, number), pos3.x, pos3.y);
    
    
    //popup effect
    shader.begin();
    ofSetColor(255);
    shader.setUniform1f("u_animation", ypos);
    shader.setUniform1f("u_textbox_height", textBox.getHeight());
    font.drawStringAsShapes(input, pos4.x, pos4.y);
    shader.end();
    
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
        ypos = textBox.getHeight();
    }
}

void ofApp::startTweening(){
    timeline().apply(&number).then<choreograph::RampTo>(int(input.size()), 2.0f, choreograph::EaseInQuart());
    timeline().apply(&ypos).then<choreograph::RampTo>(0.0f, 2.0f, choreograph::EaseInOutQuart());
}
