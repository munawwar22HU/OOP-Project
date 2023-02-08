#include "Arena.hpp"

Arena::Arena(Ltexture *platformtexture) //Overloaded constructor for the arena. It loads all the required sprites
{
    std::cout << "Arena constructor  is called \n";
    spriteclips[0] = {2, 569, 157, 150};
    spriteclips[1] = {172, 347, 107, 35};
    

    platformarray = new Platform *[9];
    platformarray[0] = new Platform(platformtexture, 0, 570, spriteclips[0]);
    platformarray[1] = new Platform(platformtexture, 157, 570, spriteclips[0]);
    platformarray[2] = new Platform(platformtexture, 314, 570, spriteclips[0]);
    platformarray[3] = new Platform(platformtexture, 471, 570, spriteclips[0]);
    platformarray[4] = new Platform(platformtexture, 628, 570, spriteclips[0]);
    platformarray[5] = new Platform(platformtexture, 785, 570, spriteclips[0]);
    platformarray[6] = new Platform(platformtexture, 942, 570, spriteclips[0]);
    platformarray[7] = new Platform(platformtexture, 1099, 570, spriteclips[0]);
    platformarray[8] = new Platform(platformtexture, 1256, 570, spriteclips[0]);
}

Arena::~Arena() //Deconstructor of the arena. It deletes all the resources that were created.
{
    std::cout << "Arena Deconstructor  is called \n";
    this->Free();
}

void Arena::Render(SDL_Renderer *gRenderer) //The function which renders the arena.
{
    for (int i = 0; i < 9; i++)
    {
        platformarray[i]->Render(gRenderer);
    }
}
SDL_Rect Arena::getPlatform(int i) //Returns an SDL_Rect 
{

    return platformarray[i]->get_rect();
}
void Arena::Free() //Function to free 
{
    // for (int i = 0; i < 9; i++)
    // {
    //     platformarray[i]->Free();
    //     platformarray[i] = NULL;
    // }
    // delete[] platformarray;
}