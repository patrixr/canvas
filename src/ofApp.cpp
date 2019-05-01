#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    objects.clear();
    
    canvas = new Canvas(CANVAS_W, CANVAS_H, TILE_SIZE);
    player = new Player(250, 250);
    player->setSpeed(1);
    player->setAreaBounds(canvas->getGeometry(), true);
    viewport = new Viewport();
    viewport->follow(player);
    controller = new Controller(player);
    
    objects.push_back(canvas);
    objects.push_back(player);
    
    Aura *aura = new Aura(ofColor::teal, canvas, player);
    aura->setRadius(150);
    
    objects.push_back(aura);

    ofResetElapsedTimeCounter();
}

//--------------------------------------------------------------
void ofApp::update(){
    int dt = ofGetElapsedTimeMillis();
    
    for (int i = 0; i < objects.size(); ++i) {
        objects[i]->update(dt);
    }
    
    ofResetElapsedTimeCounter();
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void ofApp::draw() {
    viewport->begin();
    for (int i = 0; i < objects.size(); ++i) {
        objects[i]->draw();
    }
    viewport->end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    controller->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    controller->keyReleased(key);
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
