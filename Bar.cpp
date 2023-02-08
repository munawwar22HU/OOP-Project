#include "Bar.hpp"

Bar::Bar()
{ //The bar class constuctor
    std::cout << "Bar Constructor" << std::endl;
}

Bar::Bar(int x, int y, Ltexture *texture)
{
    m_texture = texture;
    m_x = x;
    m_y = y;
}

void Bar::DrawBar(SDL_Renderer *gRenderer)
{
    //m_texture->Render(m_x, m_y, gRenderer,NULL);
}
void Bar::Update(int x, SDL_Renderer *gRenderer)
{
}
Bar::~Bar()
{ //Deconstructor of the class
    std::cout << "Bar DeConstructor is called" << std::endl;
}