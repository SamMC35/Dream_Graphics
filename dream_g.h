/* DREAM ENGINE(GRAPHICS MODE)

Created By Sambaditya Guha Biswas
Created For the students of IEM

If you want to add a feature, contact me at sambaditya.1337@gmail.com

*/

#ifndef DREAM_INIT
#define DREAM_INIT

#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window* window;			    //Window variable
SDL_Surface* surface;			//Surface variable
SDL_Renderer* renderer;			//Renderer variable
SDL_Event event;			    //Event variable


void CreateWindow(int x, int y)		//Creates window
{
    SDL_Init(SDL_INIT_EVERYTHING);	//Inits SDL
    
    window = SDL_CreateWindow("Dream", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, x, y, SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
}


void ClearScreen()               //Draws the Screen
{
    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

void SetColor(int r, int g, int b)          //Sets the color
{
    SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
}

void DrawPixel(int x, int y)                //Draws point
{
    SDL_RenderDrawPoint(renderer, x, y);            
}

void DrawLine(int x1, int y1, int x2, int y2)       //Draws line
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void DrawQuad(int x, int y, int w, int h)
{
    SDL_Rect rect = {x,y,w,h};
    SDL_RenderFillRect(renderer, &rect);
}

void Render()                       //Render
{
    SDL_RenderPresent(renderer);
}

void Delay(int seconds)             //Delay 
{
    SDL_Delay(seconds);
}

void CloseWindow()          //Close Window
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int Done()
{
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT)
    {
        return 1;
    }
    else
        return 0;
}

int Wait()                  //Wait for an input
{
    int quit = 0;

    while(!quit)
    {
        SDL_PollEvent(&event);
        if(event.type == SDL_QUIT)
        {
            quit = 1;
            break;
        }
    }
}



#endif

