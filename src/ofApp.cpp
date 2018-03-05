#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 255, 255);
    ofSetFrameRate(30);
    ofSetBackgroundAuto(true);
    
    receiver.setup(SERVER_PORT);
    moji = "";
    isPrintOut = true;
    font.loadFont("font/w0.ttc", 50);

    ofColor initColor = ofColor(0, 0, 0, 255);
    ofColor minColor = ofColor(0, 0, 0, 255);
    ofColor maxColor = ofColor(255,255,255,255);
    
    gui.setup();
    gui.add(drawWidth.setup("draw width", ofGetWidth()*.5, ofGetWidth()*.5, ofGetWidth()*.5 + 200));
    gui.add(drawHeight.setup("draw height", 200, 0, 400));
    gui.add(fontSize.setup("font size", 40, 10, 200));
    gui.add(printWidth.setup("print width", 200, fontSize, 400));
    gui.add(printHeigth.setup("print height", 200, 49, 300));
    gui.add(printOnOff.setup("print on/off", false));
    gui.add(drawColor.setup("color", initColor, minColor, maxColor));
}

//--------------------------------------------------------------
void ofApp::update(){
    while (receiver.hasWaitingMessages()) {
        ofxOscMessage message;
        receiver.getNextMessage(message);
        if (message.getAddress() == "/moji") {
            if (message.getNumArgs() < 2) continue;
            
            mojiType = message.getArgAsInt(0);
            switch (mojiType) {
                case 0:
                    // 普通に文字
                    moji = message.getArgAsString(1);
                    if (message.getNumArgs() > 2) {
                        drawColor = ofColor(message.getArgAsInt(2), message.getArgAsInt(3), message.getArgAsInt(4));
                    }
                    break;
                case 1:
                    // 画像の場合(来るかどうか)
                    break;
                default :
                    break;
            }
            
            isNewData = true;
        }
    }

    // 印刷出力
    if (!isPrintOut) {
        ofImage getImage, printImage;
        
        printImage.allocate(ofGetWindowWidth(), ofGetWindowHeight(), OF_IMAGE_COLOR);
        getImage.setImageType(OF_IMAGE_COLOR);
        getImage.grabScreen(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
        printImage.cropFrom(getImage, drawWidth, drawHeight - fontSize - font.getLineHeight(), printWidth, printHeigth);
        printImage.rotate90(1);
        printImage.save(FILE_SAVE_PATH);
        
        // print out!!
        if (printOnOff)
            system("lp -o landscape -o fit-to-page -o media=Custom.89x127mm /Users/niisato/Desktop/drawmoji/drawmoji.png");

        isPrintOut = true;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(drawColor);
    if (mojiType == 0) {
        
        font.drawString(moji, drawWidth, drawHeight);
        if (isNewData) {
            isPrintOut = false;
            isNewData = false;
        }
        
        ofSetColor(0, 0, 0);
        ofNoFill();
        ofDrawRectangle(drawWidth - 1, drawHeight - fontSize - font.getLineHeight() - 1, printWidth + 2, printHeigth + 2);
    }
    
    if (showMenu) {
        ofSetColor(0, 0, 0);
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch (key) {
        case 'h':
            showMenu = !showMenu;
            break;
        case 'r':
            // reload font size
            font.loadFont("font/w0.ttc", fontSize);
            break;
        case 's':
            // reload font size
            ofImage myImage;
            myImage.grabScreen(drawWidth, drawHeight, printWidth, printHeigth);
            myImage.save(FILE_SAVE_PATH, OF_IMAGE_QUALITY_BEST);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
