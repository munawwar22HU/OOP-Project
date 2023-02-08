#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"
#include "button.hpp"
#include "screen.hpp"

class FlashScreen : public Screen   //The class which handles the information screen at the start of the game. It inherits the screen class
{
private:
    Ltexture Title;
    Ltexture Next;
    Ltexture Player;
    Ltexture Left;
    Ltexture Right;
    Ltexture Jump;
    Ltexture Attack;

public:
    FlashScreen(Ltexture *, SDL_Renderer *, int, int, int);
    ~FlashScreen();
    void Render(SDL_Renderer *);
    void render();
};
