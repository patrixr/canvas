//
//  Drawable.cpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#include "Drawable.h"

Drawable::Drawable(float x, float y, float w, float h) : geometry(x,y,w,h) {
    // noop
};

Drawable::Drawable(float x, float y) : Drawable(x,y, 0, 0) {
    
};

Drawable::Drawable() : Drawable(0, 0) {
    
};

const ofVec2f Drawable::getPosition() const {
    return geometry.getPosition();
};

const ofRectangle & Drawable::getGeometry() const {
    return geometry;
};

void Drawable::draw() {
#if DEBUG_SHOW_HITBOXES
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofDrawRectangle(geometry);
    ofSetColor(255, 255, 255);
#endif
};

void Drawable::update(int elapsed) {};
