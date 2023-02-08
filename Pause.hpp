#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"
#include "button.hpp"
#include "screen.hpp"

class Pause : public Screen   // Class to make and render the pause screen. It inherits the screen class
{
private:
    Ltexture resume;
    Ltexture save;
    Ltexture inventory;

public:
    Pause(Ltexture *, SDL_Renderer *, int, int, int);
    ~Pause();
    void Render(SDL_Renderer *);
    void render();
};
