#include "button.hpp"
button::button(Ltexture *ptr, int x, int y, std::string message) : GameObject(ptr, x, y)
{
    m_message = message;
    m_state = 0;
    std::cout << "Button Constructor is called \n";
}

button::~button()
{
    std::cout << "Button Deconstructor is called \n";
    m_ptr->Free();
}
void button::Render(SDL_Renderer *gRender)
{
    m_ptr->Render(m_x, m_y, gRender, NULL);
}
void button::EventHandler(SDL_Event e)
{
    int x, y;
    SDL_GetMouseState(&x, &y);
    if (e.type == SDL_MOUSEBUTTONDOWN && (x >= m_x && x <= m_x + m_ptr->GetWidth()) && (y >= m_y && y <= m_y + m_ptr->GetHeight()))
    {
        m_state = 1;
        std::cout << m_message << " is clicked.\n";
    }
}
std::string button::get_message()
{
    return m_message;
}
bool button::clicked()
{

    if (m_state == 1)
    {
        m_state=0;
        return true;
    }
    return false;
}