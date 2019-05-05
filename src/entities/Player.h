//
//  Player.hpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Bullet.h"
#include "GameEvents.h"
#include "constants.h"
#include "bases/Moveable.h"
#include "traits/Orientable.h"
#include "Aura.h"

class Aura;

class Player : public Moveable, public Orientable {
    
private:
    
    Aura            *aura;
    ofImage         image;
    int             shootTick;
    
    bool isShooting() const;
    
public:
    Player(float x, float y);
    
    void    draw() override;
    void    update(int elapsed) override;
};

#endif /* Player_hpp */
