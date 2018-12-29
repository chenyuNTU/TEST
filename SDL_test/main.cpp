#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
using namespace std;

const int WINDOW_W = 800;
const int WINDOW_H = 600;

/*
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Test",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_W, WINDOW_H,
                                          /*SDL_WINDOW_FULLSCREEN*//*SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(render);

    SDL_Event event;
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                cout << "Quit!\n";
                quit = true;
            }
        }
        SDL_RenderPresent(render);
        SDL_Delay(5);
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}*/


int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Test",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_W, WINDOW_H,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(render);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music* sound = Mix_LoadMUS("jazz.wav");
    Mix_PlayMusic(sound, 0);
    SDL_Event event;
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                cout << "Quit!\n";
                quit = true;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    Mix_PauseMusic();
                }
                else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    ;
                }
            }
        }
        SDL_RenderPresent(render);
        SDL_Delay(5);
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
/*
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Test",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_W, WINDOW_H,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(render);

    SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(render, 255,255,255,250);
    //SDL_RenderDrawPoint(render, 100, 100);
    //SDL_RenderDrawLine(render, 50, 50,200,70);


    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.h = 100;
    rect.w = 100;

    SDL_RenderDrawRect(render, &rect);


    int x1 = 0;
    int y1 = 0;
    bool state = 1; //0 = mouse down

    SDL_Event event;
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                cout << "Quit!\n";
                quit = true;
            }
            else if(event.type == SDL_MOUSEMOTION)
            {
                if(state == 0)
                {
                    int x = event.motion.x;
                    int y = event.motion.y;
                    /*if(x1 == 0 && y1 ==0)
                    {
                        x1=x;
                        y1=y;
                    }*/
                    //SDL_RenderDrawLine(render, WINDOW_W/2, WINDOW_H/2, x, y);
                    /*SDL_RenderDrawLine(render, x1, y1, x, y);
                    x1 = x;
                    y1 = y;
                }

            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                state = 0;
                int x = event.motion.x;
                int y = event.motion.y;
                x1 = x;
                y1 = y;
            }
            else if(event.type == SDL_MOUSEBUTTONUP)
            {
                state = 1;
            }
        }
        SDL_RenderPresent(render);
        SDL_Delay(5);
        //SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


/*
SDL_Rect rect;
bool moveR = true;
bool moveD = true;*/
/*
void updatePosition()
{
    if(moveR == true)
    {
        rect.x++;
        if(rect.x + rect.w >= WINDOW_W)
        {
            moveR = false;
        }
    }
    else
    {
        rect.x--;
        if(rect.x <= 0)
        {
            moveR = true;
        }
    }

    if(moveD == true)
    {
        rect.y++;
        if(rect.y + rect.h >= WINDOW_H)
        {
            moveD = false;
        }
    }
    else
    {
        rect.y--;
        if(rect.y <= 0)
        {
            moveD = true;
        }
    }
}
*/
/*
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Test",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_W, WINDOW_H,
                                          /*SDL_WINDOW_FULLSCREEN*//*SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(render);

    SDL_Event event;
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                cout << "Quit!\n";
                quit = true;
            }
        }
        SDL_RenderPresent(render);
        SDL_Delay(5);
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}*/
/*
struct Spot
{
    int x;
    int y;
    int r;
    int speed;
    int alpha;
};

void moveSpot(Spot* spot)
{
    spot->y = spot->y + spot->speed;
    if(spot->y >= WINDOW_H)
        spot->y = 0;

}

void drawSpot(Spot* spot, SDL_Renderer* render, SDL_Texture* circle)
{
    SDL_Rect rect;
    rect.x = spot -> x;
    rect.y = spot -> y;
    rect.w = spot -> r;
    rect.h = spot -> r;
    SDL_SetTextureAlphaMod(circle, spot->alpha);
    SDL_RenderCopy(render, circle, NULL, &rect);
}

const int dotAmount = 200;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Test",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_W, WINDOW_H,
                                          SDL_WINDOW_SHOWN);
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(render);

    SDL_Surface* blackS = SDL_LoadBMP("black.bmp");
    SDL_Surface* circleS = SDL_LoadBMP("circle.bmp");

    SDL_SetColorKey(circleS, SDL_TRUE, SDL_MapRGB(circleS->format,0,0,0));

    SDL_Texture* black = SDL_CreateTextureFromSurface(render, blackS);
    SDL_Texture* circle = SDL_CreateTextureFromSurface(render, circleS);
    SDL_SetTextureBlendMode(black, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(circle, SDL_BLENDMODE_BLEND);

    SDL_SetTextureAlphaMod(black, 50);
    SDL_SetTextureColorMod(circle, rand()%255, rand()%255, rand()%255);

    SDL_Rect rectW;
    rectW.x = 0;
    rectW.y = 0;
    rectW.h = WINDOW_H;
    rectW.w = WINDOW_W;

    SDL_Rect rect;
    rect.x = 100;
    rect.y = 100;
    rect.h = circleS -> h;
    rect.w = circleS -> w;

    Spot spots[dotAmount];
    for(int i = 0 ; i < dotAmount ; i++)
    {
        spots[i].x = rand() % WINDOW_W;
        spots[i].y = rand() % WINDOW_H;
        spots[i].r = rand() % 5 + 1;
        spots[i].speed = rand() % 3 + 1;
        spots[i].alpha = rand() % 255;
    }

    SDL_Event event;
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                cout << "Quit!\n";
                quit = true;
            }
        }
        SDL_RenderCopy(render, black, NULL, &rectW);
        //SDL_RenderCopy(render, circle, NULL, &rect);
        for(int i = 0 ; i < dotAmount ; i++)
        {
            drawSpot(&spots[i], render, circle);
            moveSpot(&spots[i]);
        }
        SDL_RenderPresent(render);
        SDL_Delay(5);
        //SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}


/*
int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL Test",
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                          WINDOW_W, WINDOW_H,
                                          /*SDL_WINDOW_FULLSCREEN*//*SDL_WINDOW_SHOWN);
/*
    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;*//*

    SDL_Surface* surface = SDL_GetWindowSurface(window);/*
    SDL_Surface* image1 = SDL_LoadBMP("dickman.bmp");
    SDL_Surface* image2 = IMG_Load("angry.png");
    SDL_Surface* currentImage = image1;*/

    /*for(int i = 0 ; i < 5 ; i++)
    {
        SDL_BlitSurface(image, NULL, surface, &rect);
        rect.x = rect.x + 300;
    }*/

    /*
    SDL_BlitSurface(image1, NULL, surface, &rect);

    SDL_UpdateWindowSurface(window);*/

    //SDL_Delay(5000);
/*
    SDL_Renderer* render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderClear(render);

    SDL_Surface* rockman = SDL_LoadBMP("rockman.bmp");
    SDL_SetColorKey(rockman, SDL_TRUE, SDL_MapRGB(rockman -> format,181,230,29));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(render, rockman);

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
    int alpha = 255;
    bool desc = true;
    SDL_SetTextureAlphaMod(texture, alpha);


    SDL_Surface* cursor = IMG_Load("green_cursor.png");
    SDL_Texture* cursorTexture = SDL_CreateTextureFromSurface(render, cursor);

    SDL_Surface* black = SDL_LoadBMP("black.bmp");
    SDL_Texture* blackTexture = SDL_CreateTextureFromSurface(render, black);

    SDL_SetTextureBlendMode(cursorTexture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureBlendMode(blackTexture, SDL_BLENDMODE_BLEND);
    SDL_SetTextureAlphaMod(blackTexture, 100);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.h = cursor -> h /4;
    rect.w = cursor -> w /4;

    SDL_Rect rectW;
    rectW.x = 0;
    rectW.y = 0;
    rectW.h = WINDOW_H;
    rectW.w = WINDOW_W;
    /*
    int imgW = rockman -> w;
    int imgH = rockman -> h /2;

    SDL_Rect position;
    position.x = 0;
    position.y = 0;
    position.h = imgH/2;
    position.w = imgW/2;


    SDL_Rect clips[2];
    for(int i = 0 ; i < 2 ; i++)
    {
        clips[i].x = 0;
        clips[i].y = i * imgH;
        clips[i].w = imgW;
        clips[i].h = imgH;
    }*/
/*
    int cnt = 0;

    SDL_Event event;
    bool quit = false;
    while(quit == false)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                cout << "Quit!\n";
                quit = true;
            }/*
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                cout << "Clicked!  ";
                if(event.button.button == SDL_BUTTON_LEFT)
                {
                    cout << "left!\n";
                    //SDL_BlitSurface(image1, NULL, surface, &rect);
                    currentImage = image1;
                }
                else if(event.button.button == SDL_BUTTON_RIGHT)
                {
                    cout << "right!\n";
                    //SDL_BlitSurface(image2, NULL, surface, &rect);
                    currentImage = image2;
                }
            }
            else if(event.type == SDL_KEYDOWN)
            {
                cout << event.key.keysym.sym << "\n";
                if(event.key.keysym.sym == SDLK_UP)
                {
                    cout << "UP!\n";
                    rect.y = rect.y - 10;
                }
                else if(event.key.keysym.sym == SDLK_DOWN)
                {
                    cout << "DOWN!\n";
                    rect.y = rect.y + 10;
                }
                else if(event.key.keysym.sym == SDLK_LEFT)
                {
                    cout << "LEFT!\n";
                    rect.x = rect.x - 10;
                }
                else if(event.key.keysym.sym == SDLK_RIGHT)
                {
                    cout << "RIGHT!\n";
                    rect.x = rect.x + 10;
                }
                SDL_FillRect(surface, NULL, 0);
                SDL_BlitSurface(currentImage, NULL, surface, &rect);
            }*//*
            else if(event.type == SDL_MOUSEMOTION)
            {
                rect.x = event.motion.x - (rect.w/2);
                rect.y = event.motion.y - (rect.h/2);
                //SDL_FillRect(surface, NULL, 0);
                //SDL_RenderClear(render);
                //SDL_RenderCopy(render, cursorTexture, NULL, &rect);
                //SDL_BlitSurface(cursor, NULL, surface, &rect);
            }
        }/*
        //SDL_Delay(5);
        SDL_RenderClear(render);
        SDL_RenderCopy(render, texture, &clips[cnt], &position);*//*
        //SDL_RenderClear(render);
        SDL_RenderCopy(render, blackTexture, NULL, &rectW);
        SDL_RenderCopy(render, cursorTexture, NULL, &rect);

        SDL_RenderPresent(render);/*
        cnt++;
        if(cnt >= 2)
            cnt = 0;
        position.x += 10;
        if(desc == true)
        {
            alpha -= 5;
            if(alpha == 0)
                desc = false;

        }
        else
        {
            alpha += 5;
            if(alpha == 255)
                desc = true;

        }*//*

        SDL_SetTextureAlphaMod(texture, alpha);

        SDL_Delay(5);
        //SDL_UpdateWindowSurface(window);
    }

    //SDL_FreeSurface(image2);
    //SDL_FreeSurface(cursor);
    SDL_FreeSurface(surface);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}*/
