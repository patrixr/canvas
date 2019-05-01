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
#include "constants.h"
#include "bases/Moveable.h"
#include "traits/Orientable.h"

class Player : public Moveable, public Orientable {
    
private:
    
    ofImage         image;
    
public:
    Player(float x, float y);
    
    void    draw() override;
    void    update(int elapsed) override;
};

#endif /* Player_hpp */
