#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"
class GameObject
{
protected:
    SDL_Rect sprite_chips;
    Ltexture *m_ptr;
    int m_x, m_y;

public:
    GameObject(Ltexture *, int, int);

    virtual ~GameObject();
    virtual void Render(SDL_Renderer *);
    virtual void EventHandler(SDL_Event e) = 0;
};
