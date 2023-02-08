#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"

#include "screen.hpp"
class ShopScreen : public Screen
{
private:
    Ltexture end;
    Ltexture Buy;
    Ltexture Sell;

public:
    ShopScreen(Ltexture *, SDL_Renderer *gRenderer, int, int, int);
    ~ShopScreen();
    void Render(SDL_Renderer *);
};