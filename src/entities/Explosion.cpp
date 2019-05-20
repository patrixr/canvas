//
//  Explosion.cpp
//  canvas
//
//  Created by Patrick R on 7/5/2019.
//

#include "Explosion.h"


Explosion::Explosion(float x, float y, ofColor col) : Drawable(x, y, 1, 1) {
    aura = AuraBuilder()
        .withExpansionRate(ofRandom(80, 120))
        .withIntensity(ofRandom(30, 40))
        .withColor(col)
        .withPosition(x, y)
        .withRadius(1)
        .get();
    
    addChild(aura);
    setTTL(ofRandom(50, 200));
    setType(TYPE_FRIENDLY | TYPE_EXPLOSION);
}


void Explosion::update(int elapsed) {
    Drawable::update(elapsed);
    
    geometry.set(
        aura->getX() - aura->getRadius(),
        aura->getY() - aura->getRadius(),
        aura->getRadius() * 2,
        aura->getRadius() * 2
    );
}
