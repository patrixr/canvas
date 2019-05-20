//
//  CollisionPool.cpp
//  canvas
//
//  Created by Patrick R on 5/5/2019.
//

#include "CollisionPool.h"

//--------------------------------------------------------------
CollisionPool::CollisionPool(ofRectangle bounds) : qtree(bounds) {}

//--------------------------------------------------------------
CollisionPool::CollisionPool(ofRectangle bounds, const list<Drawable*> & objects) : CollisionPool(bounds) {
    add(objects);
}

//--------------------------------------------------------------
void CollisionPool::add(const list<Drawable*> & objects) {
    auto it = objects.begin();
    while (it != objects.end()) {
        add(*it);
        ++it;
    }
}

//--------------------------------------------------------------
void CollisionPool::add(Drawable *obj) {
    if (!obj->collideable()) {
        return;
    }
    qtree.add(obj);
}

//--------------------------------------------------------------
void CollisionPool::computeCollisions(Drawable *obj) {
    list<Drawable*>   others;

    qtree.populateCollidables(others, obj);
    
    auto it = others.begin();
    while (it != others.end()) {
        if (!obj->isAlive()) {
            return;
        }
        if ((*it)->isAlive()) {
            obj->processCollision(*it);
        }
        ++it;
    }
}
