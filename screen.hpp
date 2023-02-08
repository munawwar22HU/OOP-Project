#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Ltexture.hpp"
#include "button.hpp"
class Screen
{
protected:
    Ltexture *m_texture;
    int m_x;
    int m_y;
    int m_button_count;
    button **m_ButtonArray;
    TTF_Font *gFont;

public:
    int winner;
    Screen(Ltexture *, int, int, int);
    virtual ~Screen();
    void Free();
    virtual void Render(SDL_Renderer *);
    int getButttonCount() { return m_button_count; }
    void Event(SDL_Event e);
    button **getButtons() { return m_ButtonArray; }
};
