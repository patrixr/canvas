#pragma once

#include <vector>
#include "ofMain.h"
#include "Canvas.h"
#include "Player.h"
#include "Viewport.h"
#include "Controller.h"
#include "Aura.h"
#include "constants.h"

using namespace std;

typedef vector<Drawable*> ObjectList;

class ofApp : public ofBaseApp {
    
    private:
        Canvas              *canvas;
        Player              *player;
        Viewport            *viewport;
        Controller          *controller;
        ObjectList          objects;
    
    
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
		
};
