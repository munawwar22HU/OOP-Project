#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"
#include "button.hpp"
#include "screen.hpp"

class game_screen : public Screen    //The game screen class
{
private:
    Ltexture player1;
    Ltexture player2;
    Ltexture pause;

public:
    game_screen(Ltexture *, SDL_Renderer *, int, int, int);
    ~game_screen();
    void Render(SDL_Renderer *);
    void render();
};
