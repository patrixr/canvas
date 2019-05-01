//
//  Moveable.hpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#ifndef Moveable_hpp
#define Moveable_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Drawable.h"

class Moveable : public Drawable {
    
protected:
    
    ofVec2f     velocity;
    ofRectangle boundaries;
    float       speed;
    float       acceleration;
    bool        canLoop;
    
    bool    hasBounds();
    float   computeAxisPosition(float val, float addedValue, float min, float max);
    
public:
    
    Moveable(float x, float y, float w, float h);
    Moveable(float x, float y);
    Moveable();
    
    void setVelocityX(ofVec2f v);
    void setVelocity(float x, float y);
    void addVelocityX(float x);
    void addVelocityY(float y);
    void setSpeed(float speed);
    void setAreaBounds(ofRectangle bounds, bool enableLoop = false);
    
    void update(int elapsed) override;
    
};

#endif /* Moveable_hpp */
