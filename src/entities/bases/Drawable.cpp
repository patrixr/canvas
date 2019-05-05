//
//  Drawable.cpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#include "Drawable.h"

//--------------------------------------------------------------
Drawable::Drawable(float x, float y, float w, float h, Drawable *parent)
    : geometry(x,y,w,h), parent(parent), alive(true), ttl(-1) {};

//--------------------------------------------------------------
Drawable::Drawable(float x, float y, Drawable *parent) : Drawable(x,y, 0, 0, parent) {};

//--------------------------------------------------------------
Drawable::Drawable(Drawable *parent) : Drawable(0, 0, parent) {};

//--------------------------------------------------------------
Drawable::~Drawable() {
    while (children.size()) {
        delete children.back();
        children.pop_back();
    }
}

//--------------------------------------------------------------
void Drawable::addChild(Drawable *obj) {
    obj->setParent(this);
    children.push_back(obj);
}

//--------------------------------------------------------------
void Drawable::setParent(Drawable *p) {
    parent = p;
}

//--------------------------------------------------------------
const ofVec2f Drawable::getPosition() const {
    return geometry.getPosition();
};

//--------------------------------------------------------------
const ofRectangle & Drawable::getGeometry() const {
    return geometry;
};

//--------------------------------------------------------------
float Drawable::getX() const {
    return geometry.x;
}

//--------------------------------------------------------------
float Drawable::getY() const {
    return geometry.y;
}

//--------------------------------------------------------------
float Drawable::getWidth() const {
    return geometry.width;
}

//--------------------------------------------------------------
float Drawable::getHeight() const {
    return geometry.height;
}

//--------------------------------------------------------------
void Drawable::draw() {
#if DEBUG_SHOW_HITBOXES
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofDrawRectangle(geometry);
    ofSetColor(255, 255, 255);
#endif

    for (uint i = 0; i < children.size(); ++i) {
        children[i]->draw();
    }
};

//--------------------------------------------------------------
void Drawable::update(int elapsed) {
    if (alive && ttl > 0) {
        ttl -= elapsed;
        alive = ttl > 0;
    }

    for (uint i = 0; i < children.size(); ++i) {
        children[i]->update(elapsed);
    }
};

//--------------------------------------------------------------
uint Drawable::getType() const {
    return 0;
}

//--------------------------------------------------------------
int Drawable::getTTL() const {
    return ttl;
}

//--------------------------------------------------------------
void Drawable::setTTL(int val) {
    ttl = val;
}

//--------------------------------------------------------------
bool Drawable::isAlive() const {
    return alive;
}

//--------------------------------------------------------------
bool Drawable::intersects(const Drawable & other) const {
    return intersects(&other);
}

//--------------------------------------------------------------
bool Drawable::intersects(const Drawable * other) const {
    return getGeometry().intersects(other->getGeometry());
}

//--------------------------------------------------------------
void Drawable::processCollision(Drawable * other) {
    processCollision(*other);
}

//--------------------------------------------------------------
void Drawable::processCollision(Drawable & other) {
    if (intersects(other)) {
        onCollision(other);
    }
}

//--------------------------------------------------------------
void Drawable::onCollision(const Drawable &other) {}

//--------------------------------------------------------------
bool Drawable::collideable() const {
    return true;
}
