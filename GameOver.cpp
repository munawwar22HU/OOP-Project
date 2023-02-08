#include "Gameover.hpp"
Gameover::Gameover(Ltexture *texture, SDL_Renderer *gRenderer, int count, int x, int y) : Screen(texture, count, x, y)
{ //Overloaded constructor to create the start screen with all the necessary contents

    SDL_Color textColor = {255, 255, 255};

    message.Load("Game Over", textColor, gRenderer, gFont);
    player1.Load("Player 1 Wins", textColor, gRenderer, gFont);
    player2.Load("Player 2 Wins", textColor, gRenderer, gFont);
}
void Gameover::Render(SDL_Renderer *gRenderer) //Function to render the start screen
{

    m_texture->Render(m_x, m_y, gRenderer, NULL);
    message.Render(560, 320, gRenderer, NULL);
    if (winner == 1)
    {
        player1.Render(560, 480, gRenderer, NULL);
    }
    else if (winner == 0)
    {
        player2.Render(560, 480, gRenderer, NULL);
    }
}

Gameover::~Gameover() //Destructor of start screen
{
}
