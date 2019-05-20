//
//  Explosion.hpp
//  canvas
//
//  Created by Patrick R on 7/5/2019.
//

#ifndef Explosion_hpp
#define Explosion_hpp

#include <stdio.h>
#include "ofMain.h"
#include "constants.h"
#include "Drawable.h"
#include "AuraBuilder.h"

class Aura;

class Explosion : public Drawable {
    
private:
    
    Aura    *aura;
    
public:
    Explosion(float x, float y, ofColor c);
    
    void update(int elaspsed) override;
};


#endif /* Explosion_hpp */
