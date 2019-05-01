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
#include "constants.h"

class Aura : public Drawable {
    
private:
    
    Canvas          *canvas;
    Drawable        *parent;
    ofColor         color;
    uint            expansionRate;
    uint            radius;
    uint            intensity;
    
public:
    
    Aura(ofColor color, Canvas *canvas);
    Aura(ofColor color, Canvas *canvas, Drawable *parent);

    void setColor(ofColor c);
    void setExpansionRate(unsigned int rate);
    void setRadius(unsigned int r);
    void setIntensity(uint val);
    void update(int elapsed) override;
    void draw() override;
};

#endif /* Aura_hpp */
