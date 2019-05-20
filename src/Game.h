//
//  Game.hpp
//  canvas
//
//  Created by Patrick R on 4/5/2019.
//

#ifndef Game_hpp
#define Game_hpp

#include <list>
#include "ofMain.h"
#include "Aura.h"
#include "GameEvents.h"
#include "Canvas.h"
#include "Player.h"
#include "Viewport.h"
#include "constants.h"
#include "CollisionPool.h"
#include "Box.h"
#include "Controller.h"

using namespace std;

typedef list<Drawable*> ObjectList;

class Player;
class Controller;
class GameEvents;
struct DrawableEventArgs;
class Aura;

class Game : public ofBaseApp {
    
private:
    static Game *instance;
    Game();
    ~Game();
    
private:
    Canvas              *canvas;
    Player              *player;
    Viewport            *viewport;
    Controller          *controller;
    ObjectList          objects;
    
    bool handleSpawn(DrawableEventArgs & args);
    
    
public:
    static void newGame();
    static void endGame();
    static bool isRunning();
    static Game & getCurrentGame();
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    Canvas & getCanvas();
    ofColor getMainColor() const;
};


#endif /* Game_hpp */
