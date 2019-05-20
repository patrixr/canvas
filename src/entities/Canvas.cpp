//
//  Canvas.cpp
//  canvas
//
//  Created by Patrick R on 27/4/2019.
//

#include "Canvas.h"

//--------------------------------------------------------------
Canvas::Canvas(int w, int h, int tileSize, ofColor initialColor)
    : Drawable(0, 0, w * tileSize, h * tileSize), tileSize(tileSize), initialColor(initialColor)
{
    width = w;
    height = h;
    image.allocate(w, h, OF_IMAGE_COLOR);
    baseColors.allocate(w, h, OF_IMAGE_COLOR);
    image.getTexture().setTextureMinMagFilter(GL_NEAREST,GL_NEAREST);
    
    reset();
}


//--------------------------------------------------------------
void Canvas::draw() {
    ofPushMatrix();
    ofScale(tileSize);
    image.draw(geometry.getX(), geometry.getY());
    ofPopMatrix();
}

//--------------------------------------------------------------
void Canvas::update(int elapsed) {
    image.update();
}

//--------------------------------------------------------------
ofVec2f Canvas::overflownPos(int x, int y) const {
    if (x < 0) {
        x = width + x;
    }
    else if (x >= width) {
        x -= width;
    }
    if (y < 0) {
        y = height + y;
    }
    else if (x >= width) {
        y -= height;
    }
    return ofVec2f(x, y);
}

//--------------------------------------------------------------
void Canvas::setColor(int x, int y, ofColor col, float brightness) {
    ofVec2f pos = overflownPos(x, y);
    
    if (col != baseColors.getColor(pos.x, pos.y)) {
        baseColors.setColor(pos.x, pos.y, col);
        col.setBrightness(brightness);
        image.setColor(pos.x, pos.y, col);
    }
}

//--------------------------------------------------------------
ofColor Canvas::getColor(int x, int y) const {
    ofVec2f pos = overflownPos(x, y);
    return baseColors.getColor(pos.x, pos.x);
}

//--------------------------------------------------------------
void Canvas::increaseBrightness(int x, int y, float val) {
    ofVec2f pos = overflownPos(x, y);
    ofColor c(image.getColor(pos.x, pos.y));
    float b = c.getBrightness();
    if (b < 255) {
        c.setBrightness(b + val);
    }
    image.setColor(pos.x, pos.y, c);
}

//--------------------------------------------------------------
int Canvas::getTileSize() const {
    return tileSize;
}

//--------------------------------------------------------------
ofVec2f Canvas::getRelativePos(const Drawable & obj) const {
    ofVec2f pos = obj.getPosition();
    return ofVec2f(
        (int) (pos.x / tileSize),
        (int) (pos.y / tileSize)
    );
}

//--------------------------------------------------------------
void Canvas::reset(ofImage & img) {
    int width = img.getWidth();
    int height = img.getHeight();

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            img.setColor(x, y, initialColor);
        }
    }
    img.update();
}

//--------------------------------------------------------------
void Canvas::reset() {
    reset(image);
    reset(baseColors);
}

//--------------------------------------------------------------
bool Canvas::collideable() const {
    return false;
}

