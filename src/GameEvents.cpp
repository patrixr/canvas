//
//  GameEvents.cpp
//  canvas
//
//  Created by Patrick R on 1/5/2019.
//

#include "GameEvents.h"

ofEvent<DrawableEventArgs> GameEvents::EVT_SPAWN = ofEvent<DrawableEventArgs>();

// -----------------------------------------------
void GameEvents::spawn(Drawable *obj) {
    DrawableEventArgs args;
    args.obj = obj;
    ofNotifyEvent(GameEvents::EVT_SPAWN, args);
}

// -----------------------------------------------
void GameEvents::explode(const Drawable *obj, ofColor c) {
    explode(*obj, c);
}

// -----------------------------------------------
void GameEvents::explode(const Drawable & obj, ofColor c) {
    Explosion *exp = new Explosion(obj.getX(), obj.getY(), c);
    spawn(exp);
}
