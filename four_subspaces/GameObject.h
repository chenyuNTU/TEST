#ifndef GAMEOBJECT_H_INCLUDED
#define GAMEOBJECT_H_INCLUDED

#include "Game.h"

class GameObject
{
private:
    int xpos;
    int ypos;
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

public:
    GameObject(const char* texturesheet, SDL_Renderer* renderer, int x, int y);
    ~GameObject();

    void update();
    void render();
};

#endif // GAMEOBJECT_H_INCLUDED
