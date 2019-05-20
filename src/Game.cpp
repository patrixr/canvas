//
//  Game.cpp
//  canvas
//
//  Created by Patrick R on 4/5/2019.
//

#include "Game.h"

/* Singleton implementation */

Game *Game::instance = NULL;

//--------------------------------------------------------------
void Game::newGame() {
    endGame();
    instance = new Game();
    instance->setup();
}

//--------------------------------------------------------------
void Game::endGame() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

//--------------------------------------------------------------
Game & Game::getCurrentGame() {
    return *instance;
}

//--------------------------------------------------------------
bool Game::isRunning() {
    return instance != NULL;
}

//--------------------------------------------------------------
Game::Game() : ofBaseApp() {}

//--------------------------------------------------------------
Game::~Game() {
    ofRemoveListener(GameEvents::EVT_SPAWN, this, &Game::handleSpawn);
    while (objects.size()) {
        delete objects.back();
        objects.pop_back();
    }
    delete viewport;
    delete controller;
}

//--------------------------------------------------------------
void Game::setup(){
    ofAddListener(GameEvents::EVT_SPAWN, this, &Game::handleSpawn);
    canvas = new Canvas(CANVAS_W, CANVAS_H, TILE_SIZE, getMainColor());
    player = new Player(250, 250);
    player->setSpeed(PLAYER_SPEED);
//    player-d>setAuraColor(getMainColor());
    player->setAreaBounds(canvas->getGeometry(), true);
    viewport = new Viewport();
    viewport->follow(player, CAMERA_DISTANCE);
    controller = new Controller(player);
    
    objects.push_back(canvas);
    objects.push_back(player);
    
    for (uint i = 0; i < BOX_COUNT; ++i) {
        objects.push_back(
            new Box(
                ofRandom(TILE_SIZE, canvas->getWidth() - TILE_SIZE),
                ofRandom(TILE_SIZE, canvas->getHeight() - TILE_SIZE)
            )
        );
    }
    
    ofResetElapsedTimeCounter();
}

//--------------------------------------------------------------
void Game::update(){
    int dt = ofGetElapsedTimeMillis();
    
    controller->update();
    
    auto it = objects.begin();
    CollisionPool pool(getCanvas().getGeometry());
    while (it != objects.end()) {
        if ((*it)->isAlive()) {
            (*it)->update(dt);
            pool.add(*it);
            ++it;
        } else {
            delete (*it);
            it = objects.erase(it);
        }
    }
    
    it = objects.begin();
    while (it != objects.end()) {
        pool.computeCollisions(*(it++));
    }
    
    ofResetElapsedTimeCounter();
    
    std::stringstream strm;
    strm << "fps: " << ofGetFrameRate();
    ofSetWindowTitle(strm.str());
}

//--------------------------------------------------------------
void Game::draw() {
    viewport->begin();
    ObjectList::iterator it = objects.begin();
    while (it != objects.end()) {
        (*it)->draw();
        ++it;
    }
    viewport->end();
}

//--------------------------------------------------------------
bool Game::handleSpawn(DrawableEventArgs & args) {
    objects.push_back(args.obj);
    return true;
}

//--------------------------------------------------------------
void Game::keyPressed(int key){
    controller->keyPressed(key);
}

//--------------------------------------------------------------
void Game::keyReleased(int key){
    controller->keyReleased(key);
}

//--------------------------------------------------------------
void Game::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void Game::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Game::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Game::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void Game::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void Game::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void Game::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void Game::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void Game::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
Canvas & Game::getCanvas() {
    return *canvas;
}

//--------------------------------------------------------------
ofColor Game::getMainColor() const {
    return ofColor::teal;
}
