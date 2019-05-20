//
//  Palette.h
//  canvas
//
//  Created by Patrick R on 8/5/2019.
//

#ifndef Palette_h
#define Palette_h

#include <vector>
#include "ofMain.h"

using namespace std;

class Palette {
    
public:
    static const vector<ofColor> Colors;
    static ofColor getNextColor();
};

#endif /* Palette_h */
