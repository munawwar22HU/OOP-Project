
#pragma once
#include "GameObject.hpp"
#include "Ltexture.hpp"
class Bar
{ //The bar class is the base class for  health and confidence bars
protected:
    Ltexture *m_texture;
    int m_x;
    int m_y;

public:
    Bar();
    Bar(int, int, Ltexture *);
    virtual void DrawBar(SDL_Renderer *); //Virtual function to make it the base class as it will be inherited by other classes
    void Update(int, SDL_Renderer *);
    ~Bar();
};