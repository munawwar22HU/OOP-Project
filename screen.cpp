#include "screen.hpp"
Screen::Screen(Ltexture *texture, int count, int x, int y)
{
    m_texture = texture;
    m_x = x;
    m_y = y;
    m_button_count = count;
    gFont = TTF_OpenFont("Veto-Com-Bold.ttf", 80);
    m_ButtonArray = new button *[m_button_count];
    std::cout << "Screen Constructor \n";
}

void Screen::Render(SDL_Renderer *gRenderer)
{
    m_texture->Render(m_x, m_y, gRenderer, NULL);
}
Screen::~Screen()
{
    this->Free();
}
void Screen::Event(SDL_Event e)
{
    for (int i = 0; i < m_button_count; i++)
    {
        m_ButtonArray[i]->EventHandler(e);
    }
}
void Screen::Free()
{
    m_texture->Free();
    std::cout << "Screen Deconstructor is called \n";
    TTF_CloseFont(gFont);
    gFont = NULL;
    for (int i = 0; i < m_button_count; i++)
    {
        delete m_ButtonArray[i];
        m_ButtonArray[i] = NULL;
    }
    delete[] m_ButtonArray;
}