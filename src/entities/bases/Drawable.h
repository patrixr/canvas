//
//  IDrawable.h
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#ifndef IDrawable_h
#define IDrawable_h

#include <vector>
#include <string>
#include "ofMain.h"
#include "constants.h"

using namespace std;

class Drawable {

protected:
    
    ofRectangle         geometry;
    vector<Drawable*>   children;
    Drawable            *parent;
    int                 ttl;
    bool                alive;
    
public:
    
    Drawable(float x, float y, float w, float h, Drawable *parent = NULL);
    
    Drawable(float x, float y, Drawable *parent = NULL);
    
    Drawable(Drawable *parent = NULL);
    
    ~Drawable();
    
    const ofVec2f           getPosition() const;
    const ofRectangle &     getGeometry() const;
    float                   getX() const;
    float                   getY() const;
    float                   getWidth() const;
    float                   getHeight() const;
    void                    addChild(Drawable *obj);
    void                    setParent(Drawable *parent);
    int                     getTTL() const;
    void                    setTTL(int val);
    bool                    isAlive() const;
    bool                    intersects(const Drawable * other) const;
    bool                    intersects(const Drawable & other) const;
    void                    processCollision(Drawable * other);
    void                    processCollision(Drawable & other);
    virtual void            draw();
    virtual void            update(int elapsed);
    virtual uint            getType() const;
    virtual void            onCollision(const Drawable &other);
    virtual bool            collideable() const;
};

#endif /* IDrawable_h */
