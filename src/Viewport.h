//
//  Viewport.hpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#ifndef Viewport_hpp
#define Viewport_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Drawable.h"

class Viewport : public ofEasyCam {
    
private:
    float distance;
    Drawable *object;
    
public:
    Viewport();
    
    void begin();
    void follow(Drawable *object, float distance);
    void follow(Drawable *object);
};

#endif /* Viewport_hpp */
