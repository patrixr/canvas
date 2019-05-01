//
//  Controller.hpp
//  canvas
//
//  Created by Patrick R on 28/4/2019.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <stdio.h>
#include "Player.h"
#include <map>

class Controller {
    
private:
    
    Player *player;
    std::map<int, bool> pressedKeys;
    
public:
    Controller(Player *p);
    void keyPressed(int key);
    void keyReleased(int key);
};

#endif /* Controller_hpp */