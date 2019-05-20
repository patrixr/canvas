//
//  Orientable.h
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#ifndef Orientable_h
#define Orientable_h

#include "ofMain.h"

class Orientable {
  
protected:
    ofVec2f orientation;
    
public:
    
    Orientable();
    
    float getRotation() const;
    const ofVec2f & getOrientation() const;
    const float getOrientationX() const;
    const float getOrientationY() const;
    float setOrientation(float x, float y);
    float setOrientation(ofVec2f v);
};


#endif /* Orientable_h */
