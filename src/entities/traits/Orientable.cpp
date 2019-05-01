//
//  Orientable.cpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#include "Orientable.h"

Orientable::Orientable() : orientation(0, 0) {}

float Orientable::getRotation() const {
    ofVec2f down(0, - 1);
    return - orientation.angle(down);
}

void Orientable::addOrientationX(float x) {
    orientation.set(orientation.x + x, orientation.y);
};

void Orientable::addOrientationY(float y) {
    orientation.set(orientation.x, orientation.y + y);
};
