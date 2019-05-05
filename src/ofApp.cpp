#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    Game::newGame();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (Game::isRunning()) {
        Game::getCurrentGame().update();
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    if (Game::isRunning()) {
        Game::getCurrentGame().draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (Game::isRunning()) {
        Game::getCurrentGame().keyPressed(key);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (Game::isRunning()) {
        Game::getCurrentGame().keyReleased(key);
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    if (Game::isRunning()) {
        Game::getCurrentGame().mouseMoved(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if (Game::isRunning()) {
        Game::getCurrentGame().mouseDragged(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (Game::isRunning()) {
        Game::getCurrentGame().mousePressed(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if (Game::isRunning()) {
        Game::getCurrentGame().mouseReleased(x, y, button);
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    if (Game::isRunning()) {
        Game::getCurrentGame().mouseEntered(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    if (Game::isRunning()) {
        Game::getCurrentGame().mouseExited(x, y);
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    if (Game::isRunning()) {
        Game::getCurrentGame().windowResized(w, h);
    }
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    if (Game::isRunning()) {
        Game::getCurrentGame().gotMessage(msg);
    }
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    if (Game::isRunning()) {
        Game::getCurrentGame().dragEvent(dragInfo);
    }
}
