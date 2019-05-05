//
//  Boxes.hpp
//  canvas
//
//  Created by Patrick R on 4/5/2019.
//

#ifndef Boxes_hpp
#define Boxes_hpp

#include <stdio.h>
#include "ofMain.h"
#include "constants.h"
#include "Drawable.h"

class Box : public Drawable {
    
private:
    
    ofColor color;
    
public:
    Box(float x, float y);
    
    void draw() override;
    void onCollision(const Drawable &other) override;
};

#endif /* Boxes_hpp */
