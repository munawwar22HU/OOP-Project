#pragma once
#include "Ltexture.hpp"
#include "GameObject.hpp"
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_image/SDL_ttf.h>
#else
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif
class button : public GameObject
{
private:
    std::string m_message;

    int m_state;

public:
    button(Ltexture *, int x, int y, std::string m);
    ~button();
    void Render(SDL_Renderer *gRenderer);
    void EventHandler(SDL_Event e);
    std::string get_message();
    bool clicked();
};
