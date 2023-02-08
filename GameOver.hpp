#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"

#include "screen.hpp"
class Gameover : public Screen //The start screen class which will work on the content shown on the very first screen. It inherits the screen class
{
private:
    Ltexture message;
    Ltexture player1;
    Ltexture player2;

public:
    Gameover(Ltexture *, SDL_Renderer *gRenderer, int, int, int);
    ~Gameover();
    void Render(SDL_Renderer *);
    void set_win(int w) { winner = w; }
};