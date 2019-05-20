//
//  Events.h
//  canvas
//
//  Created by Patrick R on 1/5/2019.
//

#pragma once

#include "ofMain.h"
#include "Drawable.h"
#include "Explosion.h"

class Explosion;
struct DrawableEventArgs : ofEventArgs {
    Drawable * obj;
};

class GameEvents {
public:
    static ofEvent<DrawableEventArgs> EVT_SPAWN;
    
    static void spawn(Drawable *obj);
    static void explode(const Drawable *obj, ofColor c);
    static void explode(const Drawable &obj, ofColor c);
};
