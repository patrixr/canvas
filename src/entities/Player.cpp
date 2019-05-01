//
//  Player.cpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#include <math.h>
#include "Player.h"

#define SHIP_WIDTH 100

Player::Player(float x, float y) : Moveable(x, y), Orientable()
{
    image.load("ship.png");
    
    float ratio = SHIP_WIDTH / image.getWidth();
    image.resize(SHIP_WIDTH, ratio * image.getHeight());
    geometry.setWidth(image.getWidth());
    geometry.setHeight(image.getHeight());
}

void Player::draw() {
    Drawable::draw();
    
    ofPushMatrix();
    ofTranslate(geometry.x + geometry.width / 2, geometry.y + geometry.height / 2);
    ofRotateZDeg(getRotation());

    ofPushMatrix();
    image.draw( - geometry.width / 2,  - geometry.height / 2);
    ofPopMatrix();
    ofPopMatrix();
}

void Player::update(int elapsed) {
    Moveable::update(elapsed);
    // noop
}
