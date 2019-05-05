//
//  Aura.hpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#ifndef Aura_hpp
#define Aura_hpp

#include <cstdlib>
#include <stdio.h>
#include "ofMain.h"
#include "Drawable.h"
#include "Canvas.h"
#include "Game.h"
#include "constants.h"

class Aura : public Drawable {
    
private:
    ofColor         color;
    uint            expansionRate;
    uint            radius;
    uint            intensity;
    
public:
    Aura(ofColor color, uint radius, Drawable *parent = NULL);
    Aura(ofColor color, Drawable *parent = NULL);

    void setColor(ofColor c);
    const ofColor & getColor() const;
    void setExpansionRate(unsigned int rate);
    void setRadius(unsigned int r);
    void setIntensity(uint val);
    void update(int elapsed) override;
    void draw() override;
};

#endif /* Aura_hpp */
