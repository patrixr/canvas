//
//  Canvas.hpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#ifndef Canvas_hpp
#define Canvas_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Drawable.h"
#include "constants.h"

class Canvas : public Drawable {

private:

    ofImage     image;
    ofImage     baseColors;
    int         width;
    int         height;
    int         tileSize;
    
    void        reset();
    void        reset(ofImage & img);
    ofVec2f     overflownPos(int x, int y) const;
    
public:
    Canvas(int w, int h, int tileSize);
    
    void        draw() override;
    void        update(int elapsed) override;
    ofVec2f     getRelativePos(const Drawable & obj) const;
    void        setColor(int x, int y, ofColor col, float brightness = 50);
    ofColor     getColor(int x, int y) const;
    void        increaseBrightness(int x, int y, float val = 2);
    int         getTileSize() const;
};

#endif /* Canvas_hpp */
