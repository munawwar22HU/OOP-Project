#include "ShopScreen.hpp"
ShopScreen::ShopScreen(Ltexture *texture, SDL_Renderer *gRenderer, int count, int x, int y) : Screen(texture, count, x, y)
{
    SDL_Color textColor = {255, 255, 255};

    end.Load("Quit Inventory", textColor, gRenderer, gFont);
    m_ButtonArray[0] = new button(&end, 1100, 10, "Quit");
    Buy.Load("BUY", textColor, gRenderer, gFont);
    m_ButtonArray[1] = new button(&Buy, 900, 620, "BUY");
    Sell.Load("SELL", textColor, gRenderer, gFont);
    m_ButtonArray[2] = new button(&Sell, 1100, 620, "SELL");
}
void ShopScreen::Render(SDL_Renderer *gRenderer)
{

    m_texture->Render(m_x, m_y, gRenderer, NULL);
    m_ButtonArray[0]->Render(gRenderer);
    m_ButtonArray[1]->Render(gRenderer);
    m_ButtonArray[2]->Render(gRenderer);
}

ShopScreen::~ShopScreen()
{
    std::cout << "Shop Screen Deconstructor is called." << std::endl;
}