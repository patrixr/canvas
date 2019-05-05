//
//  Bullet.hpp
//  canvas
//
//  Created by Patrick R on 1/5/2019.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>
#include "constants.h"
#include "ofMain.h"
#include "Moveable.h"
#include "Orientable.h"


class Bullet : public Moveable, public Orientable {
    
public:
    
    Bullet(float x, float y, float vx, float vy);
    Bullet(float x, float y, ofVec2f v);
    Bullet(ofVec2f pos, ofVec2f v);
    
    void    draw() override;
};


#endif /* Bullet_hpp */
