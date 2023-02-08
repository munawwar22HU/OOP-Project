#pragma once
#include <string>
#include <iostream>
#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_image/SDL_ttf.h>

#else
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

struct Color
{
    int m_x, m_y, m_z;
};
class Ltexture
{
private:
    SDL_Texture *texture;
    int width;
    int height;

public:
    Ltexture();
    ~Ltexture();

    bool Load(std::string path, SDL_Renderer *);
    bool Load(std::string textureText, SDL_Color textColor, SDL_Renderer *gRenderer, TTF_Font *gFont);
    void Render(int x, int y, SDL_Renderer *, SDL_Rect *clip);
    void setAlpha(Uint8 alpha);
    void setBlendMode(SDL_BlendMode blending);
    void Free();
    void Render(int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip, int degree, int rotation, SDL_RendererFlip flip);
    void SetColor(int, int, int);
    int GetWidth();
    int GetHeight();
};

#endif