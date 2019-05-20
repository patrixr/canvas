//
//  Orientable.cpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#include "Orientable.h"

Orientable::Orientable() : orientation(0, 0) {}

//--------------------------------------------------------------
const ofVec2f & Orientable::getOrientation() const {
    return orientation;
}

//--------------------------------------------------------------
const float Orientable::getOrientationX() const {
    return getOrientation().x;
}

//--------------------------------------------------------------
const float Orientable::getOrientationY() const {
    return getOrientation().y;
}

//--------------------------------------------------------------
float Orientable::setOrientation(float x, float y) {
    orientation.set(x, y);
}

//--------------------------------------------------------------
float Orientable::setOrientation(ofVec2f v) {
    setOrientation(v.x, v.y);
}

//--------------------------------------------------------------
float Orientable::getRotation() const {
    ofVec2f down(0, - 1);
    return - getOrientation().angle(down);
}
