#include "HealthBar.hpp"

HealthBar::HealthBar()
{                 //Health bar constructor
    health = 400; //Setting the length of the health bar
    std::cout << "Health Bar Constructor" << std::endl;
}

HealthBar::HealthBar(int x, int y)
{
    m_x = x;
    m_y = y;
    health = 400;
}

HealthBar::HealthBar(int x, int y, Ltexture *texture) : Bar(x, y, texture)
{
    x = x;
    y = y;
    health = 400;
}

void HealthBar::operator-(int change)
{ //When any enemy strikes the player health is lost and this function is called
    std::cout<<"Function called";
    health = health - change;

    if (health <= 0)
    {
        std::cout << "The character has died" << std::endl;
        health = 0;
    }
}

void HealthBar::Update(int change)
{ //When any enemy strikes the player health is lost and this function is called

    health = health - change;

    if (health <= 0)
    {
        std::cout << "The character has died" << std::endl;
        health = 0;
    }
}
void HealthBar::DrawBar(SDL_Renderer *gRenderer)
{ //The function which renders the bar
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);

    SDL_Rect b = {m_x, m_y, 400, 50};
    SDL_RenderFillRect(gRenderer, &b);

    SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
    SDL_Rect a = {m_x, m_y, health, 50};
    SDL_RenderFillRect(gRenderer, &a);
    //m_texture->Render(x, y, gRenderer, NULL);
}

HealthBar::~HealthBar()
{ //Deconstructor of the class
    std::cout << "Health Bar Deconstructor is called" << std::endl;
}

void HealthBar::set_HealthBar_x(int m_x)
{
    x = m_x;
}

void HealthBar::set_HealthBar_y(int m_y)
{
    y = m_y;
}

void HealthBar::set_HealthBar_health(int h)
{
    health = h;
}

int HealthBar::get_HealthBar_x()
{
    return x;
}

int HealthBar::get_HealthBar_y()
{
    return y;
}

int HealthBar::get_HealthBar_health()
{
    return health;
}