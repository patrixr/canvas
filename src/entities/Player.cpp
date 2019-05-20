//
//  Player.cpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#include <math.h>
#include "Player.h"

//--------------------------------------------------------------
Player::Player(float x, float y) :
    Moveable(x, y),
    Orientable()
{
    setType(TYPE_PLAYER | TYPE_FRIENDLY);
    image.load("ship.png");
    
    float ratio = SHIP_WIDTH / image.getWidth();
    image.resize(SHIP_WIDTH, ratio * image.getHeight());
    geometry.setWidth(image.getWidth());
    geometry.setHeight(image.getHeight());
    shootTick = 0;
    
    aura = new Aura(ofColor::teal, PLAYER_AURA_SIZE);
    aura->setNoColor();
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
void Player::shoot() {
    mustShoot = true;
}


//--------------------------------------------------------------
void Player::update(int elapsed) {
    Moveable::update(elapsed);
    
    aura->setIntensity((abs(velocity.x) + abs(velocity.y)) * 10 );
    
    if (mustShoot && shootTick >= 100) {
        Bullet *b = new Bullet(
           getX() + getWidth() / 2 - BULLET_WIDTH / 2 + getOrientationX() * getWidth() / 2,
           getY() + getHeight() / 2 - BULLET_HEIGHT / 2 + getOrientationY() * getHeight() / 2,
           getOrientation()
        );
        b->setSpeed(speed * 2);
        b->addChild(
            AuraBuilder().withRadius(100).withIntensity(10).withNoColor().get()
        );
        b->setAreaBounds(this->boundaries, true);
        GameEvents::spawn(b);
        shootTick = 0;
        mustShoot = false;
    } else {
        shootTick += elapsed;
    }
}

//--------------------------------------------------------------
void Player::setAuraColor(ofColor c) {
    aura->setColor(c);
}
