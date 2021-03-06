//
//  Boxes.cpp
//  canvas
//
//  Created by Patrick R on 4/5/2019.
//

#include "Box.h"

//--------------------------------------------------------------
Box::Box(float x, float y) : Drawable(x, y, BOX_SIZE, BOX_SIZE) {
    setType(TYPE_TERRAIN);
    color = Palette::getNextColor();
}

//--------------------------------------------------------------
void Box::draw() {
    Drawable::draw();
    
    ofSetColor(color);
    ofFill();
    ofDrawRectangle(getGeometry());
    ofSetColor(255);
}

void Box::onCollision(const Drawable &other) {
    if (other.isOfType(TYPE_BULLET) || other.isOfType(TYPE_EXPLOSION)) {
        alive = false;
        GameEvents::explode(this, color);
    }
}
