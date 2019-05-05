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
