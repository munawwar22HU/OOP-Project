#pragma once
#include "GameObject.hpp"
#include "Ltexture.hpp"
#include "Arena.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

class Game
{

private:
    Player *Zack;
    Enemy *Samurai;
    Arena *KingPass;
    HealthBar *HealthBarP1;
    HealthBar *HealthBarP2;
    bool isGameOver;
    int who;

public:
    Game();
    void NewGame(Ltexture *, Ltexture *, Ltexture *);
    void EventHandler(SDL_Event e);
    void LoadGame(Ltexture *, Ltexture *, Ltexture *);
    void Update();
    void SaveGame();
    bool GameOver();
    void Render(SDL_Renderer *);
    int getwho();
    ~Game();
};