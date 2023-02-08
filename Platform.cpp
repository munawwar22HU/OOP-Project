#include "Platform.hpp"
Platform::Platform(Ltexture *texture, int x, int y, SDL_Rect clip) : GameObject(texture, x, y)
{
    m_clip = clip;
    wall = {m_x, m_y, m_clip.w, m_clip.h};
}

void Platform::Render(SDL_Renderer *gRenderer)  // Renders then platforms
{
    m_ptr->Render(m_x, m_y, gRenderer, &m_clip);
}
void Platform::EventHandler(SDL_Event e)
{
}

SDL_Rect Platform::get_rect()
{

    return wall;
}

