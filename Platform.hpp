#pragma once
#include "GameObject.hpp"

class Platform : public GameObject
{
private:
    SDL_Rect m_clip;
    SDL_Rect wall;

public:
    Platform(Ltexture *texture, int x, int y, SDL_Rect clip);
    //~Platform();

    void Render(SDL_Renderer *gRenderer);
    void EventHandler(SDL_Event e);
    
    SDL_Rect get_rect();
};
