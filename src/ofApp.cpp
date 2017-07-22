#include "ofApp.h"

//z方向からだと綺麗
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    //ofSetBackgroundAuto(false);
    ofSetVerticalSync(true);
    ofSetCircleResolution(150);
    soundStream.printDeviceList();
    int bufferSize = 256;
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    bufferCounter	= 0;
    drawCounter		= 0;
    smoothedVol     = 0.0;
    scaledVol		= 0.0;
    r=50;
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    //camera.setPosition(ofVec3f(300,0,0));
}

//--------------------------------------------------------------
void ofApp::update(){
   for(int i=0;i<num;i=i+1){
    mayachan[i].update();
   }
    //scale the vol up to a 0-1 range
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
    //record the volume into an array
    volHistory.push_back( scaledVol );
    //if we are bigger the the size we want to record - lets drop the oldest value
    if( volHistory.size() >= 400 ){
        volHistory.erase(volHistory.begin(), volHistory.begin()+1);
    }
   }
//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    camera.begin();
    for(int i=0;i<num;i=i+1){
        ofSetColor(255,0,200);
        mayachan[i].draw();
           }
    if(scaledVol >0.07){
        ofSetColor(ofRandom(255), ofRandom(255),255);
    }
    else{
    ofSetColor(255);
    }
    ofNoFill();
    ofDrawSphere(0, 0,0, scaledVol * 1600.0f);
    camera.end();
}

void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    float curVol = 0.0;
    int numCounted = 0;
    //go through each sample and calculate the root mean square which is a rough way to calculate volume
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        right[i]	= input[i*2+1]*0.5;
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    //get the mean of rms :)
    curVol /= (float)numCounted;
    //get the root of rms :)
    curVol = sqrt( curVol );
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
