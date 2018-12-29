#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
using namespace std;

class Game
{
private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    Game();
    ~Game();

    void init(const char* title, int x, int y, int width, int height, bool fullscreen);

    void events();
    void update();
    void render();
    void clean();

    bool running();
};

#endif // GAME_H_INCLUDED
