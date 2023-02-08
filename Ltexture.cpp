#include "Ltexture.hpp"
#include <SDL_ttf.h>

Ltexture::Ltexture() //Default constructor for the Ltexture class
{
    texture = NULL;
    width = 0;
    height = 0;
    std::cout << "Ltexture constructor is called \n";
}
Ltexture::~Ltexture() //Deconstructor for the Ltexture class
{
    Free();
    std::cout << "Ltexture deconstructor is called \n";
}
void Ltexture::Free() //Function which frees all the used resources
{
    if (texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}
int Ltexture::GetHeight() //Function to return the height of the sprite
{
    return height;
}

int Ltexture::GetWidth() //Function to return the width of the sprite
{
    return width;
}

void Ltexture::Render(int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip) //Function to render the sprite 
{
    SDL_Rect renderQuad = {x, y, width, height};

    //Set clip rendering dimensions
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopy(gRenderer, texture, clip, &renderQuad);
}

bool Ltexture::Load(std::string path, SDL_Renderer *gRenderer) //Function to load an object
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
    }
    else
    {
        //Color key image
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 186, 254, 202));
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL)
        {
            printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        }
        else
        {
            //Get image dimensions

            width = loadedSurface->w;
            height = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    texture = newTexture;
    return texture != NULL;
}

bool Ltexture::Load(std::string textureText, SDL_Color textColor, SDL_Renderer *gRenderer, TTF_Font *gFont)
{ //Another function to load an object
    //Get rid of preexisting texture
    Free();

    //Render text surface
    SDL_Surface *textSurface = TTF_RenderText_Solid(gFont, textureText.c_str(), textColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    }
    else
    {
        //Create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (texture == NULL)
        {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else
        {
            //Get image dimensions
            width = textSurface->w;
            height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return texture != NULL;
}

void Ltexture::setBlendMode(SDL_BlendMode blending) //Function to set the blend mode
{
    //Set blending function
    SDL_SetTextureBlendMode(texture, blending);
}

void Ltexture::setAlpha(Uint8 alpha) //Function to set the alpha
{
    //Modulate texture alpha
    SDL_SetTextureAlphaMod(texture, alpha);
}
void Ltexture::Render(int x, int y, SDL_Renderer *gRenderer, SDL_Rect *clip, int degree, int rotation, SDL_RendererFlip flip)
{ //Another function to render the sprite 
    SDL_Rect renderQuad = {x, y, width, height};

    //Set clip rendering dimensions
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    //Render to screen
    SDL_RenderCopyEx(gRenderer, texture, clip, &renderQuad, 0, 0, flip);
}