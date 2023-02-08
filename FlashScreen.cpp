#include "FlashScreen.hpp"
FlashScreen::FlashScreen(Ltexture *texture, SDL_Renderer *gRenderer, int count, int x, int y) : Screen(texture, count, x, y)
{   //Overloaded constructor with all the messages that have to be displayed on the screen
    SDL_Color textColor = {253, 145, 47};
    Title.Load("Controls", textColor, gRenderer, gFont);
    Player.Load("Player 1 :                 Player 2 : ", textColor, gRenderer, gFont);
    Left.Load(  "LEFT <                      A        ", textColor, gRenderer, gFont);
    Right.Load( "RIGHT >                   S        ", textColor, gRenderer, gFont);
    Jump.Load(  "JUMP  ^                   W        ", textColor, gRenderer, gFont);
    Attack.Load("ATTACK SPACE         Q        ", textColor, gRenderer, gFont);

    Next.Load("Next", textColor, gRenderer, gFont);

    m_ButtonArray[0] = new button(&Next, 1080, 570, "NEXT");
}

void FlashScreen::Render(SDL_Renderer *gRenderer)  //Function to render the screen
{
    m_texture->Render(m_x, m_y, gRenderer, NULL);
    Title.Render(480, 50, gRenderer, NULL);
    Player.Render(100, 125, gRenderer, NULL);
    Left.Render(100, 200, gRenderer, NULL);
    Right.Render(100, 275, gRenderer, NULL);
    Jump.Render(100, 350, gRenderer, NULL);
    Attack.Render(100, 425, gRenderer, NULL);
    m_ButtonArray[0]->Render(gRenderer);
}
FlashScreen::~FlashScreen()  //Deconstructor of the class
{
    std::cout << "Flash Screen Deconstructor is called" << std::endl;
}