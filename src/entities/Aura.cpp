//
//  Aura.cpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#include "Aura.h"

#define DEFAULT_RADIUS 100;

Aura::Aura(ofColor col, Canvas *canvas, Drawable *parent) : Drawable(), parent(parent), canvas(canvas), color(col)
{
    intensity = 1;
    expansionRate = 0;
    radius = DEFAULT_RADIUS;
}

Aura::Aura(ofColor color, Canvas *canvas) : Aura(color, canvas, NULL) {}

void Aura::setColor(ofColor c) {
    color = c;
}

void Aura::setExpansionRate(unsigned int rate) {
    expansionRate = rate;
}

void Aura::setRadius(unsigned int r) {
    radius = r;
}

void Aura::setIntensity(uint val) {
    intensity = val;
}

void Aura::draw() {
#if DEBUG_SHOW_HITBOXES
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofDrawCircle(getPosition(), radius);
    ofSetColor(255, 255, 255);
#endif
}

void Aura::update(int elapsed) {
    if (parent != NULL) {
        const ofRectangle & parentRect = parent->getGeometry();
        geometry.setPosition(
            parentRect.x + parentRect.width / 2,
            parentRect.y + parentRect.height / 2
         );
    }
    
    ofVec2f pos = canvas->getRelativePos(*this);
    uint tileSize = canvas->getTileSize();
    uint noOfTiles = radius / tileSize;
    
    int y = pos.y - noOfTiles - 1;
    
    while (y <= pos.y + noOfTiles) {
        int len = (noOfTiles - abs(y - pos.y));
        int x = pos.x - len - 1;
        
        while (x <= pos.x + len) {
            canvas->setColor(x, y, color);
            canvas->increaseBrightness(x, y, 1);
            ++x;
        }
        ++y;
    }

    Drawable::update(elapsed);
}
