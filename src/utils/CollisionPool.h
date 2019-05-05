//
//  CollisionPool.hpp
//  canvas
//
//  Created by Patrick R on 5/5/2019.
//

#ifndef CollisionPool_hpp
#define CollisionPool_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Drawable.h"
#include "QuadTree.h"

class CollisionPool {
    
    
private:
    
    QuadTree qtree;
    
public:
    
    CollisionPool(ofRectangle bounds);
    CollisionPool(ofRectangle bounds, const list<Drawable*> & objects);
    
    void add(const list<Drawable*> & objects);
    void add(Drawable *obj);
    void computeCollisions(Drawable *obj);
};

#endif /* CollisionPool_hpp */
