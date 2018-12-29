#include "Game.h"
#include "GameObject.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* renderer, int x, int y)
{
    this->renderer = renderer;
    objTexture = IMG_LoadTexture(renderer, texturesheet);

    xpos = x;
    ypos = y;

}

void GameObject::update()
{
    xpos++;
    ypos++;

    srcRect.x = 0;
    srcRect.y = 0;
    srcRect.w = 100;
    srcRect.h = 100;

    destRect.x = xpos;
    destRect.y = ypos;
    destRect.w = 50;
    destRect.h = 50;
}

void GameObject::render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}
