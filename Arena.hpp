#pragma once
#include "Platform.hpp"
#include "Ltexture.hpp"
#include "HealthBar.hpp"
class Arena //The arena class which makes the arena on which the game is played.
{
private:
    Platform **platformarray;
    Bar *bar;
    SDL_Rect spriteclips[2];
    Ltexture *Player1;
    Ltexture *Player2;

public:
    Arena(Ltexture *platformtexture);
    void Render(SDL_Renderer *gRenderer);
    void Free();
    ~Arena();
    SDL_Rect getPlatform(int i);
};
