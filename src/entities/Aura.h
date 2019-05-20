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

class Game;
class GameEvents;

class Aura : public Drawable {
    
private:
    ofColor         color;
    uint            expansionRate;
    uint            radius;
    uint            intensity;
    bool            noColor;
    
    
public:
    Aura(ofColor color, uint radius, float x, float y);
    Aura(ofColor color, uint radius, Drawable *parent = NULL);
    Aura(ofColor color, Drawable *parent = NULL);
    Aura(uint radius, Drawable *parent = NULL);
    Aura();

    void setNoColor();
    void setColor(ofColor c);
    const ofColor & getColor() const;
    void setExpansionRate(unsigned int rate);
    void setRadius(unsigned int r);
    float getRadius() const;
    void setIntensity(uint val);
    void update(int elapsed) override;
    void draw() override;
};

#endif /* Aura_hpp */
