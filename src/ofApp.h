#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "ofxTrueTypeFontUC.h"
#include "ofxGui.h"

#define SERVER_PORT 8282
#define HOST "localhost"
#define FILE_SAVE_PATH "/Users/niisato/Desktop/drawmoji/drawmoji.png"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxTrueTypeFontUC font;
        ofxOscReceiver receiver;
        string moji;
        int mojiType;    // 0 : 文字データ, 1:画像データ
        bool isPrintOut = true;
        bool isNewData = false;
    
        ofxIntSlider drawHeight, drawWidth;
        ofxIntSlider fontSize;
        ofxIntSlider printWidth;
        ofxIntSlider printHeigth;
        ofxToggle printOnOff;
        ofxColorSlider drawColor;
        ofxPanel gui;
        bool showMenu = true;
};
