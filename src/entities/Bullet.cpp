//
//  Bullet.cpp
//  canvas
//
//  Created by Patrick R on 1/5/2019.
//

#include "Bullet.h"


//--------------------------------------------------------------
Bullet::Bullet(float x, float y, float vx, float vy)
    : Moveable(x, y, BULLET_WIDTH, BULLET_HEIGHT) {
    
    if (vx == 0 && vy == 0) {
        vy = -1;
    }
        
    setVelocity(vx, vy);
    setOrientation(vx, vy);
    setSpeed(2);
    setTTL(2000);
}

//--------------------------------------------------------------
Bullet::Bullet(float x, float y, ofVec2f v) : Bullet(x, y, v.x, v.y) {}

//--------------------------------------------------------------
Bullet::Bullet(ofVec2f pos, ofVec2f v) : Bullet(pos.x, pos.y, v) {}

//--------------------------------------------------------------
void    Bullet::draw() {
    Drawable::draw();
    
    ofPushMatrix();
    ofTranslate(getX() + getWidth() / 2, getY() + getHeight() / 2);
    ofRotateZDeg(getRotation());
    
    ofPushMatrix();
    ofFill();
    ofSetColor(255);
    ofDrawRectangle( - getWidth() / 2,  - getHeight() / 2, getWidth(), getHeight());
    ofPopMatrix();
    ofPopMatrix();
}
