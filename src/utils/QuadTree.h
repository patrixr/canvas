//
//  EntityPool.hpp
//  canvas
//
//  Created by Patrick R on 5/5/2019.
//

#ifndef EntityPool_hpp
#define EntityPool_hpp

#include <vector>
#include <list>
#include <stdio.h>
#include "ofMain.h"
#include "Drawable.h"
#include "SmartPtr.h"

typedef list<Drawable*> Drawables;

class QuadTree {

private:
    
    //  ---------
    //  | 0 | 1 |
    //  ---------
    //  | 2 | 3 |
    //  ---------
    vector<QuadTree*>       nodes;
    Drawables               objects;
    ofRectangle             bounds;
    int                     level;
    float                   middleX;
    float                   middleY;
    
public:
    
    QuadTree(ofRectangle bounds, int level = 0);
    ~QuadTree();
    
    void        add(Drawable *obj);
    void        clear();
    void        populateCollidables(Drawables & objectsOut, const Drawable * obj);
    
private:
    
    QuadTree *  getNode(const Drawable * d) const;
    QuadTree *  getNode(const Drawable & d) const;
    void        split();
    bool        tryPlaceInNode(Drawable * d);
    bool        hasChildren() const;
    bool        fitsTopSide(const Drawable & d) const;
    bool        fitsBottomSide(const Drawable & d) const;
    bool        fitsLeftSide(const Drawable & d) const;
    bool        fitsRightSide(const Drawable & d) const;
    void        moveObjectsToChildren();
};

#endif /* EntityPool_hpp */
