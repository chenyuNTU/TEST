#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Game.h"
#include "GameObject.h"
using namespace std;

const int WINDOW_W = 800;
const int WINDOW_H = 640;

const int FPS = 60;
const int frameDelay = 1000 / FPS;

Game* game = nullptr;

int main(int argc, char* argv[])
{
    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_W, WINDOW_H, false);

    while(game->running())
    {
        frameStart = SDL_GetTicks();

        game->events();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }
    game->clean();
    return 0;
}
