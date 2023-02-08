#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"

#include "screen.hpp"
class start_screen : public Screen  //The start screen class which will work on the content shown on the very first screen. It inherits the screen class
{
private:
    Ltexture start;
    Ltexture end;
    Ltexture load;

public:
    start_screen(Ltexture *, SDL_Renderer *gRenderer, int, int, int);
    ~start_screen();
    void Render(SDL_Renderer *);
};