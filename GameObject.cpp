#include "GameObject.hpp"
GameObject::GameObject(Ltexture *ptr, int x, int y)
{
    m_ptr = ptr;
    m_x = x;
    m_y = y;
}

void GameObject::Render(SDL_Renderer *gRenderer)
{
    m_ptr->Render(m_x, m_y, gRenderer, NULL);
}
GameObject::~GameObject()
{
    std::cout << "GameObject deconstructor is called " << std::endl;
}
