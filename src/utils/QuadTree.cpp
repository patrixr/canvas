//
//  EntityPool.cpp
//  canvas
//
//  Created by Patrick R on 5/5/2019.
//

#include "QuadTree.h"

#define MAX_LEVELS 4
#define MAX_OBJECTS 10

//--------------------------------------------------------------
QuadTree::QuadTree(ofRectangle bounds, int level) : nodes(4), level(level), bounds(bounds) {
    middleX = bounds.getX() + (bounds.getWidth() / 2);
    middleY = bounds.getY() + (bounds.getHeight() / 2);
}

//--------------------------------------------------------------
QuadTree::~QuadTree() {
    if (hasChildren()) {
        delete(nodes[0]);
        delete(nodes[1]);
        delete(nodes[2]);
        delete(nodes[3]);
    }
}

//--------------------------------------------------------------
bool QuadTree::tryPlaceInNode(Drawable *obj) {
    if (hasChildren()) {
        QuadTree *node = getNode(obj);
        if (node != NULL) {
            node->add(obj);
            return true;
        }
    }
    return false;
}

//--------------------------------------------------------------
void QuadTree::add(Drawable *obj) {
    if (!hasChildren() && objects.size() == MAX_OBJECTS && level < MAX_LEVELS) {
        split();
        moveObjectsToChildren();
    }
    
    if (!tryPlaceInNode(obj)) {
        objects.push_back(obj);
    }
}

//--------------------------------------------------------------
void QuadTree::clear() {
    if (hasChildren()) {
        for (uint i = 0; i < 4; ++i) {
            nodes[i]->clear();
        }
    }
    objects.clear();
}

//--------------------------------------------------------------
QuadTree *  QuadTree::getNode(const Drawable * d) const {
    return getNode(*d);
}

//--------------------------------------------------------------
QuadTree *  QuadTree::getNode(const Drawable & d) const {
    if (!hasChildren()) {
        return NULL;
    }
    
    // An object can be placed in a subdivision only if it fits entirely in it
    if (fitsLeftSide(d)) {
        if (fitsTopSide(d)) {
            return nodes[0];
        }
        else if (fitsBottomSide(d)) {
            return nodes[2];
        }
    }
    else if (fitsRightSide(d)) {
        if (fitsTopSide(d)) {
            return nodes[1];
        }
        else if (fitsBottomSide(d)) {
            return nodes[3];
        }
    }
    return NULL;
}

//--------------------------------------------------------------
bool QuadTree::fitsTopSide(const Drawable & d) const {
    return (d.getY() < middleY && d.getY() + d.getHeight() < middleY);
}

//--------------------------------------------------------------
bool QuadTree::fitsBottomSide(const Drawable & d) const {
    return (d.getY() > middleY);
}

//--------------------------------------------------------------
bool QuadTree::fitsLeftSide(const Drawable & d) const {
    return (d.getX() < middleX && d.getX() + d.getWidth() < middleX);
}

//--------------------------------------------------------------
bool QuadTree::fitsRightSide(const Drawable & d) const {
    return (d.getX() > middleX);
}

//--------------------------------------------------------------
void QuadTree::populateCollidables(Drawables & objectsOut, const Drawable * obj) {
    QuadTree *node = getNode(obj);
    
    if (node) {
        // obj fits entirely in a subdivision
        node->populateCollidables(objectsOut, obj);
    } else if (hasChildren()) {
        for (uint i = 0; i < 4; ++i) {
            nodes[i]->populateCollidables(objectsOut, obj);
        }
    }
    
    Drawables::iterator it = objects.begin();
    while (it != objects.end()) {
        if (*it != obj) {
            objectsOut.push_back(*it);
        }
        ++it;
    }
}

//--------------------------------------------------------------
void QuadTree::split() {
    if (hasChildren()) {
        return; // already split
    }
    
    int subWidth = (int)(bounds.getWidth() / 2);
    int subHeight = (int)(bounds.getHeight() / 2);
    int x = (int)bounds.getX();
    int y = (int)bounds.getY();
    
    nodes[0] = new QuadTree(ofRectangle(x + subWidth, y, subWidth, subHeight), level + 1);
    nodes[1] = new QuadTree(ofRectangle(x, y, subWidth, subHeight), level + 1);
    nodes[2] = new QuadTree(ofRectangle(x, y + subHeight, subWidth, subHeight), level + 1);
    nodes[3] = new QuadTree(ofRectangle(x + subWidth, y + subHeight, subWidth, subHeight), level + 1);
}

//--------------------------------------------------------------
void QuadTree::moveObjectsToChildren() {
    objects.remove_if([this](Drawable *d) { return tryPlaceInNode(d); });
}

//--------------------------------------------------------------
bool        QuadTree::hasChildren() const {
    return nodes[0] != NULL;
}

