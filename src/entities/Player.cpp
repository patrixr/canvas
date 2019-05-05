//
//  Player.cpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#include <math.h>
#include "Player.h"

//--------------------------------------------------------------
Player::Player(float x, float y) : Moveable(x, y), Orientable()
{
    image.load("ship.png");
    
    float ratio = SHIP_WIDTH / image.getWidth();
    image.resize(SHIP_WIDTH, ratio * image.getHeight());
    geometry.setWidth(image.getWidth());
    geometry.setHeight(image.getHeight());
    shootTick = 0;
    
    aura = new Aura(ofColor::teal, PLAYER_AURA_SIZE);
    addChild(aura);
}

//--------------------------------------------------------------
void Player::draw() {
    Moveable::draw();
    
    ofPushMatrix();
    ofTranslate(geometry.x + geometry.width / 2, geometry.y + geometry.height / 2);
    ofRotateZDeg(getRotation());

    ofPushMatrix();
    image.draw( - geometry.width / 2,  - geometry.height / 2);
    ofPopMatrix();
    ofPopMatrix();
}

//--------------------------------------------------------------
bool Player::isShooting() const {
    return getOrientationX() != 0 || getOrientationY() != 0;
}

//--------------------------------------------------------------
void Player::update(int elapsed) {
    Moveable::update(elapsed);
    
    if (isShooting() && shootTick >= 100) {
        Bullet *b = new Bullet(
           getX() + getWidth() / 2 - BULLET_WIDTH / 2 + getOrientationX() * getWidth() / 2,
           getY() + getHeight() / 2 - BULLET_HEIGHT / 2 + getOrientationY() * getHeight() / 2,
           getOrientation()
        );
        b->setSpeed(speed * 2);
        b->addChild(new Aura(aura->getColor(), 100));
        b->setAreaBounds(this->boundaries, true);
        GameEvents::spawn(b);
        shootTick = 0;
    } else {
        shootTick += elapsed;
    }
}
