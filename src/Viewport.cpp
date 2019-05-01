//
//  Viewport.cpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#include "Viewport.h"

#define DEFAULT_DISTANCE 700

Viewport::Viewport() : ofEasyCam() {
    setVFlip(true);
    follow(NULL, DEFAULT_DISTANCE);
}

void Viewport::follow(Drawable *obj, float distance) {
    this->object = obj;
    this->distance = distance;
}

void Viewport::follow(Drawable *obj) {
    follow(obj, DEFAULT_DISTANCE);
}

void Viewport::begin() {
    if (object != NULL) {
        const ofRectangle& geometry = object->getGeometry();
        setPosition(
            geometry.x + geometry.width / 2,
            geometry.y + geometry.height / 2,
            distance
        );
    }
    ofCamera::begin();
}
