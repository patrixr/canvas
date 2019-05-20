//
//  AuraBuilder.cpp
//  canvas
//
//  Created by Patrick R on 7/5/2019.
//

#include "AuraBuilder.h"

AuraBuilder::AuraBuilder() {
    instance = new Aura();
}

AuraBuilder & AuraBuilder::withExpansionRate(float rate) {
    instance->setExpansionRate(rate);
    return *this;
}

AuraBuilder & AuraBuilder::withNoColor() {
    instance->setNoColor();
    return *this;
}
AuraBuilder & AuraBuilder::withColor(ofColor c) {
    instance->setColor(c);
    return *this;
}
AuraBuilder & AuraBuilder::withRadius(float r) {
    instance->setRadius(r);
    return *this;
}

AuraBuilder & AuraBuilder::withIntensity(float intensity) {
    instance->setIntensity(intensity);
    return *this;
}

AuraBuilder & AuraBuilder::withPosition(float x, float y) {
    instance->setPosition(x, y);
    return *this;
}

Aura * AuraBuilder::get() {
    return instance;
}
