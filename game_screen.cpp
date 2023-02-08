#include "game_screen.hpp"
game_screen::game_screen(Ltexture *texture, SDL_Renderer *gRenderer, int count, int x, int y) : Screen(texture, count, x, y)
{   //Overloaded constructor of the game screen
    SDL_Color textColor = {0, 0, 0};
    player1.Load("Player 1", textColor, gRenderer, gFont);
    player2.Load("Player 2", textColor, gRenderer, gFont);

    pause.Load("Pause", textColor, gRenderer, gFont);
    m_ButtonArray[0] = new button(&pause, 510, 20, "Pause");
}

void game_screen::Render(SDL_Renderer *gRenderer) //Function to render the game screen
{

    m_texture->Render(m_x, m_y, gRenderer, NULL);
    player1.Render(10, 50, gRenderer, NULL);
    player2.Render(880, 50, gRenderer, NULL);
    m_ButtonArray[0]->Render(gRenderer);
}
game_screen::~game_screen() //Deconstructor of the game screen
{
    std::cout << "Game Screen Deconstructor is called" << std::endl;
}