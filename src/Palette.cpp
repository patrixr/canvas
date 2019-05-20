//
//  Palette.cpp
//  canvas
//
//  Created by Patrick R on 8/5/2019.
//

#include "Palette.h"

const vector<ofColor> Palette::Colors = {
    ofColor(129, 236, 236),
    ofColor(255, 234, 167),
    ofColor(250, 177, 160),
    ofColor(45, 52, 54),
    ofColor(162, 155, 254)
};

ofColor Palette::getNextColor() {
    static unsigned long i = 0;
    return Colors[i++ % Colors.size()];
}
