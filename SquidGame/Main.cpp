#include "sgg/graphics.h"
#include <iostream>
#include "Game.h"
#include "Config.h"

// The custom callback function that the library calls 
// to check for and set the current application state.
void update(float ms)
{
    Game* mygame = Game::getInstance();
    mygame->update();
}

// The window content drawing function.
void draw()
{
    Game* mygame = Game::getInstance();
    mygame->draw();
}

int main(int argc, char** argv)
{
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Squid Game v0.1");

    Game* game = Game::getInstance();

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::playMusic(std::string(ASSET_PATH) + "let-the-game-begin.wav", 0.5f, true);

    graphics::setFont(std::string(ASSET_PATH) + "GameOfSquids.ttf");

    graphics::startMessageLoop();

    Game::releaseInstance();
    return 0;
}