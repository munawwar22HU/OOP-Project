#include "Pause.hpp"
Pause::Pause(Ltexture *texture, SDL_Renderer *gRenderer, int count, int x, int y) : Screen(texture, count, x, y)
{   //Overloaded constructor to create the pause screen and the necessary objects in it
    SDL_Color textColor = {253, 145, 47};

    resume.Load("Save Game", textColor, gRenderer, gFont);
    m_ButtonArray[0] = new button(&resume, 500, 210, "Save");
    save.Load("Resume Game", textColor, gRenderer, gFont);
    m_ButtonArray[1] = new button(&save, 500, 330, "Resume");
    inventory.Load("Inventory", textColor, gRenderer, gFont);
    m_ButtonArray[2] = new button(&inventory, 500, 420, "Inventory");
}

void Pause::Render(SDL_Renderer *gRenderer) //Function to render the pause screen
{

    m_texture->Render(m_x, m_y, gRenderer, NULL);
    m_ButtonArray[0]->Render(gRenderer);
    m_ButtonArray[1]->Render(gRenderer);
    m_ButtonArray[2]->Render(gRenderer);
}
Pause::~Pause()  //Destructor of the pause screen
{
    std::cout << "Pause Screen Deconstructor is called." << std::endl;
}