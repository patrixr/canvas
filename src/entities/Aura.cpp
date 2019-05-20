//
//  Aura.cpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#include "Aura.h"

//--------------------------------------------------------------
Aura::Aura(ofColor color, uint radius, float x, float y)
    : Drawable(x, y), color(color), radius(radius), intensity(2), expansionRate(0) {}

//--------------------------------------------------------------
Aura::Aura(ofColor col, uint radius, Drawable *parent)
    : Drawable(parent), color(col), radius(radius), intensity(2), expansionRate(0) {}

//--------------------------------------------------------------
Aura::Aura(ofColor col, Drawable *parent) : Aura(color, 100, parent) {}

//--------------------------------------------------------------
Aura::Aura(uint radius, Drawable *parent) : Drawable(parent), intensity(2), radius(radius), expansionRate(0), noColor(true) {}

//--------------------------------------------------------------
Aura::Aura() : Drawable(), intensity(2), radius(1), expansionRate(0), noColor(true) {}

//--------------------------------------------------------------
void Aura::setColor(ofColor c) {
    noColor = false;
    color = c;
}

//--------------------------------------------------------------
void Aura::setNoColor() {
    noColor = true;
}

//--------------------------------------------------------------
const ofColor & Aura::getColor() const {
    return color;
}

//--------------------------------------------------------------
void Aura::setExpansionRate(unsigned int rate) {
    expansionRate = rate;
}

//--------------------------------------------------------------
void Aura::setRadius(unsigned int r) {
    radius = r;
}

//--------------------------------------------------------------
float Aura::getRadius() const {
    return radius;
}

//--------------------------------------------------------------
void Aura::setIntensity(uint val) {
    intensity = val;
}

//--------------------------------------------------------------
void Aura::draw() {
#if DEBUG_SHOW_HITBOXES
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofDrawCircle(getPosition(), radius);
    ofSetColor(255, 255, 255);
#endif
}

//--------------------------------------------------------------
void Aura::update(int elapsed) {
    
    radius += expansionRate;
    
    if (parent != NULL) {
        const ofRectangle & parentRect = parent->getGeometry();
        geometry.setPosition(
            parentRect.x + parentRect.width / 2,
            parentRect.y + parentRect.height / 2
         );
    }
    
    Canvas & canvas = Game::getCurrentGame().getCanvas();
    
    ofVec2f pos = canvas.getRelativePos(*this);
    uint tileSize = canvas.getTileSize();
    uint noOfTiles = radius / tileSize;
    
    int y = pos.y - noOfTiles - 1;
    
    while (y <= pos.y + noOfTiles) {
        int len = (noOfTiles - abs(y - pos.y));
        int x = pos.x - len - 1;
        
        while (x <= pos.x + len) {
            if (!noColor) {
                canvas.setColor(x, y, color);
            }
            canvas.increaseBrightness(x, y, intensity);
            ++x;
        }
        ++y;
    }

    Drawable::update(elapsed);
}
