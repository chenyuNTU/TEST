#include "Game.h"
#include "GameObject.h"

GameObject* player;
GameObject* enemy;

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char* title, int x, int y, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        cout << "INITIALIZED" << endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);

        if(window)
        {
            cout << "Window Created!\n";
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            cout << "Renderer Created!\n";
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    }
    else
    {
        isRunning = false;
    }
    player = new GameObject("assets/circle.bmp",renderer, 0, 0);
    enemy = new GameObject("assets/black.bmp",renderer, 50, 50);
}

void Game::events()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}
int cnt;
void Game::update()
{
    player->update();
    enemy->update();
}
void Game::render()
{
    SDL_RenderClear(renderer);

    player->render();
    enemy->render();
    SDL_RenderPresent(renderer);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Cleaned\n";
}

bool Game::running()
{
    return isRunning;
}
