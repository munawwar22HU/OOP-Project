#include "start_screen.hpp"
start_screen::start_screen(Ltexture *texture, SDL_Renderer *gRenderer, int count, int x, int y) : Screen(texture, count, x, y)
{   //Overloaded constructor to create the start screen with all the necessary contents

    SDL_Color textColor = {253, 145, 47};
   
    start.Load("Start Game", textColor, gRenderer, gFont);
    m_ButtonArray[0] = new button(&start, 500, 210, "start");
    load.Load("End Game", textColor, gRenderer, gFont);
    m_ButtonArray[2] = new button(&load, 500, 330, "load");
    end.Load("Load Game", textColor, gRenderer, gFont);
    m_ButtonArray[1] = new button(&end, 500,450, "end");
    std::cout << "Start Screen Constructor \n";
}
void start_screen::Render(SDL_Renderer *gRenderer)  //Function to render the start screen
{

    m_texture->Render(m_x, m_y, gRenderer,NULL);
    m_ButtonArray[0]->Render(gRenderer);
    m_ButtonArray[1]->Render(gRenderer);
    m_ButtonArray[2]->Render(gRenderer);
}

start_screen::~start_screen()  //Destructor of start screen
{
}
