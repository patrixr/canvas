//
//  AuraBuilder.hpp
//  canvas
//
//  Created by Patrick R on 7/5/2019.
//

#ifndef AuraBuilder_hpp
#define AuraBuilder_hpp

#include <stdio.h>
#include "Aura.h"

class Aura;

class AuraBuilder {
    
private:
    Aura    *instance;
    
public:
    AuraBuilder();
    AuraBuilder & withExpansionRate(float rate);
    AuraBuilder & withNoColor();
    AuraBuilder & withColor(ofColor c);
    AuraBuilder & withRadius(float r);
    AuraBuilder & withIntensity(float intensity);
    AuraBuilder & withPosition(float x, float y);
    Aura * get();
};

#endif /* AuraBuilder_hpp */
