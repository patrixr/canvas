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
    void addOrientationX(float x);
    void addOrientationY(float y);
};


#endif /* Orientable_h */
