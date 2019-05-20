//
//  Controller.cpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#include "Controller.h"

//--------------------------------------------------------------
Controller::Controller(Player *p) {
    this->player = p;
}

//--------------------------------------------------------------
bool Controller::isOrientationKey(int key) const {
    return (
        key == OF_KEY_UP ||
        key == OF_KEY_DOWN ||
        key == OF_KEY_RIGHT ||
        key == OF_KEY_LEFT
    );
}

//--------------------------------------------------------------
bool Controller::isMoveKey(int key) const {
    return (
        key == 'd' ||
        key == 'a' ||
        key == 's' ||
        key == 'w'
    );
}

//--------------------------------------------------------------
void Controller::update() {
    float vx = 0;
    float vy = 0;
    
    if (pressedKeys['w']) { vy -= 1; }
    if (pressedKeys['s']) { vy += 1; }
    if (pressedKeys['a']) { vx -= 1; }
    if (pressedKeys['d']) { vx += 1; }
    
    player->setVelocity(vx, vy);
    
    float ox = 0;
    float oy = 0;
    
    if (pressedKeys[OF_KEY_UP]) { oy -= 1; }
    if (pressedKeys[OF_KEY_DOWN]) { oy += 1; }
    if (pressedKeys[OF_KEY_LEFT]) { ox -= 1; }
    if (pressedKeys[OF_KEY_RIGHT]) { ox += 1; }
    
    if (ox != 0 || oy != 0) {
        player->shoot();
        player->setOrientation(ox, oy);
    }
}

//--------------------------------------------------------------
void Controller::keyPressed(int key) {
    pressedKeys[key] = true;
}

//--------------------------------------------------------------
void Controller::keyReleased(int key) {
    pressedKeys[key] = false;
}
