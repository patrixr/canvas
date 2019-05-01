//
//  IDrawable.h
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#ifndef IDrawable_h
#define IDrawable_h

#include "ofMain.h"

class Drawable {

protected:
    
    ofRectangle geometry;
    
public:
    
    Drawable(float x, float y, float w, float h);
    
    Drawable(float x, float y);
    
    Drawable();
    
    const ofVec2f           getPosition() const;
    const ofRectangle &     getGeometry() const;
    virtual void            draw();
    virtual void            update(int elapsed);
};

#endif /* IDrawable_h */
