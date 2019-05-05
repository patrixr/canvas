//
//  Moveable.cpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#include "Moveable.h"

//--------------------------------------------------------------
Moveable::Moveable(float x, float y, float w, float h) :
    Drawable(x,y,w,h),
    canLoop(false),
    speed(0),
    acceleration(0) {}

//--------------------------------------------------------------
Moveable::Moveable(float x, float y) : Moveable(x, y, 0, 0) {}

//--------------------------------------------------------------
Moveable::Moveable() : Moveable(0, 0, 0, 0) {}

//--------------------------------------------------------------
void Moveable::setVelocityX(ofVec2f v) {
    setVelocity(v.x, v.y);
}

//--------------------------------------------------------------
void Moveable::setVelocity(float x, float y) {
    if (x == 0 && y == 0) {
        acceleration = 0;
    }
    velocity.set(x, y);
}

//--------------------------------------------------------------
void Moveable::addVelocityX(float x) {
    setVelocity(velocity.x + x, velocity.y);
}

//--------------------------------------------------------------
void Moveable::addVelocityY(float y) {
    setVelocity(velocity.x, velocity.y + y);
}

//--------------------------------------------------------------
void Moveable::setSpeed(float s) {
    speed = s;
}

//--------------------------------------------------------------
bool Moveable::hasBounds() {
    return boundaries.width > 0 && boundaries.height > 0;
}

//--------------------------------------------------------------
void Moveable::setAreaBounds(ofRectangle bounds, bool enableLoop) {
    boundaries.set(bounds);
    canLoop = enableLoop;
}

//--------------------------------------------------------------
float Moveable::computeAxisPosition(float val, float addedValue, float min, float max) {
    float newVal = val + addedValue;
    
    if (!hasBounds()) {
        return newVal;
    }
    
    if (canLoop && newVal < min) {
        return max - (min - newVal);
    }
    else if (canLoop && newVal > max) {
        return min + (newVal - max);
    }
    else {
        return ofClamp(newVal, min, max);
    }
}

//--------------------------------------------------------------
void Moveable::update(int elapsed) {
    acceleration = ofClamp(acceleration + 0.05, 0, 1);
    
    float mv        = elapsed * speed * acceleration;
    float x         = geometry.x;
    float y         = geometry.y;
    
    if (velocity.x != 0) {
        float diff = velocity.x * mv;
        float min = boundaries.x;
        float max = boundaries.x + boundaries.width;
        x = computeAxisPosition(x, diff, min, max);
    }
    
    if (velocity.y != 0) {
        float diff = velocity.y * mv;
        float min = boundaries.y;
        float max = boundaries.y + boundaries.height;
        y = computeAxisPosition(y, diff, min, max);
    }
    
    geometry.setX(x);
    geometry.setY(y);
    
    Drawable::update(elapsed);
}

//--------------------------------------------------------------
void Moveable::draw() {
    Drawable::draw();
}
