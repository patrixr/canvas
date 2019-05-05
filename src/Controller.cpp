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
void Controller::keyPressed(int key) {
    if (pressedKeys[key]) {
        return;
    }
    
    pressedKeys[key] = true;
    
    switch (key) {
        case 'd':
            player->addVelocityX(1);
            break;
        case 'a':
            player->addVelocityX(-1);
            break;
        case 'w':
            player->addVelocityY(-1);
            break;
        case 's':
            player->addVelocityY(1);
            break;
        case OF_KEY_UP:
            player->addOrientationY(-1);
            break;
        case OF_KEY_DOWN:
            player->addOrientationY(1);
            break;
        case OF_KEY_LEFT:
            player->addOrientationX(-1);
            break;
        case OF_KEY_RIGHT:
            player->addOrientationX(1);
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void Controller::keyReleased(int key) {
    if (!pressedKeys[key]) {
        return;
    }
    
    pressedKeys[key] = false;
    
    switch (key) {
        case 'd':
            player->addVelocityX(-1);
            break;
        case 'a':
            player->addVelocityX(1);
            break;
        case 'w':
            player->addVelocityY(1);
            break;
        case 's':
            player->addVelocityY(-1);
            break;
        case OF_KEY_UP:
            player->addOrientationY(1);
            break;
        case OF_KEY_DOWN:
            player->addOrientationY(-1);
            break;
        case OF_KEY_LEFT:
            player->addOrientationX(1);
            break;
        case OF_KEY_RIGHT:
            player->addOrientationX(-1);
            break;
        default:
            break;
    }
}
