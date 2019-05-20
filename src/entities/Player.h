//
//  Player.hpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "AuraBuilder.h"
#include "ofMain.h"
#include "Bullet.h"
#include "constants.h"
#include "entities.h"
#include "bases/Moveable.h"
#include "traits/Orientable.h"
#include "GameEvents.h"

class GameEvents;
class Aura;

class Player : public Moveable, public Orientable {
    
private:
    
    Aura            *aura;
    ofImage         image;
    int             shootTick;
    bool            mustShoot;
    
public:
    Player(float x, float y);
    
    void    draw() override;
    void    update(int elapsed) override;
    void    setAuraColor(ofColor c);
    void    shoot();
};

#endif /* Player_hpp */
