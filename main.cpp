#define SDL_MAIN_HANDLED

#include "Ltexture.hpp"
#include "ShopScreen.hpp"
#include "Ltime.hpp"
#include "button.hpp"
#include "start_screen.hpp"
#include "game_screen.hpp"
#include "GameOver.hpp"
#include "Pause.hpp"
#include "FlashScreen.hpp"
#include "Arena.hpp"
#include "linkedlist.hpp"
#include "Platform.hpp"
#include "Game.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int SCREEN_FPS = 60;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;
TTF_Font *gFont = NULL;
SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
Ltexture Menu;
Ltexture BattleArena;
Ltexture Platforms;
Ltexture Player1;
Ltexture Player2;
Ltexture PauseScr;
Ltexture Inventory;
Ltexture Gameove;
Screen *MenuScreen = NULL;
Screen *GameScreen = NULL;
Screen *PauseScreen = NULL;
Screen *FlashScr = NULL;
Screen *Shop = NULL;
Screen *Endgame = NULL;
button **screenButtons = NULL;
Game *CourtYard = NULL;

bool init()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }
    else
    {
        //Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf("Warning: Linear texture filtering not enabled!");
        }

        //Create window
        gWindow = SDL_CreateWindow("COURT YARD BRAWL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (gRenderer == NULL)
            {
                printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
            if (TTF_Init() == -1)
            {
                printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                success = false;
            }
        }
    }

    return success;
}
bool loadMedia() // Loads all required files for rendering
{
    bool success = true;

    if (!Menu.Load("Menu.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }
    if (!BattleArena.Load("BattleArena.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }
    if (!Platforms.Load("Platform.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }
    if (!Player1.Load("Jack.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }
    if (!Player2.Load("Samurai.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }

    if (!PauseScr.Load("PauseScreen.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }

    if (!Inventory.Load("shopScreen.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }

    if (!Gameove.Load("Gameover.png", gRenderer))
    {
        printf("Failed to load Foo' texture image!\n");
        success = false;
    }
    return success;
}
void close() // Frees resources
{
    //Free loaded images
    Menu.Free();
    BattleArena.Free();
    Platforms.Free();
    Player1.Free();
    Player2.Free();
    PauseScr.Free();

    //Destroy window
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    gRenderer = NULL;

    //Quit SDL subsystems
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
int main(int argc, char *args[]) // Main game loop
{
    if (!init())
    {
        printf("Failed to initialize!\n");
    }
    else
    {
        //Load media
        if (!loadMedia())
        {
            printf("Failed to load media!\n");
        }
        else
        {

            bool isQuit = false;
            bool isMenu = true;
            bool isGame = false;
            bool isPause = false;
            bool isFlash = false;
            bool isShop = false;
            bool isGameOver = false;

            //Event handler
            SDL_Event e;
            //The frames per second timer
            LTimer fpsTimer;

            //The frames per second cap timer
            LTimer capTimer;

            //Start counting frames per second
            int countedFrames = 0;
            fpsTimer.start();

            // Initializing screens
            MenuScreen = new start_screen(&Menu, gRenderer, 3, 0, 0);
            GameScreen = new game_screen(&BattleArena, gRenderer, 1, 0, 0);
            PauseScreen = new Pause(&PauseScr, gRenderer, 3, 0, 0);
            FlashScr = new FlashScreen(&PauseScr, gRenderer, 1, 0, 0);
            Shop = new ShopScreen(&Inventory, gRenderer, 3, 0, 0);
            Endgame = new Gameover(&Gameove, gRenderer, 0, 0, 0);
            CourtYard = new Game();
            CourtYard->NewGame(&Player1, &Player2, &Platforms);

            //While application is running
            while (!isQuit)
            {
                capTimer.start();
                //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        isQuit = true;
                    }
                    if (e.type == SDL_MOUSEBUTTONDOWN) // When mouse is clicked
                    {
                        MenuScreen->Event(e);
                        GameScreen->Event(e);
                        FlashScr->Event(e);
                        PauseScreen->Event(e);
                        Shop->Event(e);
                    }
                    if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
                    {
                        CourtYard->EventHandler(e);
                    }

                    // After a button is clicked the relevant flag values are updated
                    if (isMenu)
                    {
                        screenButtons = MenuScreen->getButtons();

                        for (int i = 0; i < MenuScreen->getButttonCount(); i++)
                        {

                            if (screenButtons[i]->get_message() == "start" && screenButtons[i]->clicked() == true)
                            {
                                isGame = false;
                                isMenu = false;
                                isPause = false;
                                isFlash = true;
                            }
                        }
                    }
                    if (isFlash)
                    {
                        screenButtons = FlashScr->getButtons();
                        for (int i = 0; i < FlashScr->getButttonCount(); i++)
                        {

                            if (screenButtons[i]->get_message() == "NEXT" && screenButtons[i]->clicked() == true)
                            {
                                isGame = true;
                                isMenu = false;
                                isPause = false;
                                isFlash = false;
                            }
                        }
                    }
                    if (isGame)
                    {
                        screenButtons = GameScreen->getButtons();
                        for (int i = 0; i < GameScreen->getButttonCount(); i++)
                        {

                            if (screenButtons[i]->get_message() == "Pause" && screenButtons[i]->clicked() == true)
                            {

                                isGame = false;
                                isMenu = false;
                                isPause = true;
                                isFlash = false;
                            }
                        }
                        CourtYard->Update();
                        isGameOver = CourtYard->GameOver();
                        if (isGameOver)
                        {
                            Endgame->winner = CourtYard->getwho();
                            std::cout << Endgame->winner << std::endl;
                            isGame = false;
                            isMenu = false;
                            isPause = false;
                            isFlash = false;
                            isShop = false;
                        }
                    }
                    if (isPause)
                    {
                        screenButtons = PauseScreen->getButtons();
                        for (int i = 0; i < PauseScreen->getButttonCount(); i++)
                        {

                            if (screenButtons[i]->get_message() == "Resume" && screenButtons[i]->clicked() == true)
                            {
                                isGame = true;
                                isMenu = false;
                                isPause = false;
                                isFlash = false;
                            }

                            if (screenButtons[i]->get_message() == "Inventory" && screenButtons[i]->clicked() == true)
                            {
                                isGame = false;
                                isMenu = false;
                                isPause = false;
                                isFlash = false;
                                isShop = true;
                            }
                        }
                    }
                    if (isShop)
                    {
                        screenButtons = Shop->getButtons();
                        for (int i = 0; i < Shop->getButttonCount(); i++)
                        {

                            if (screenButtons[i]->get_message() == "Quit" && screenButtons[i]->clicked() == true)
                            {
                                isGame = false;
                                isMenu = false;
                                isPause = true;
                                isFlash = false;
                                isShop = false;
                            }
                        }
                    }
                }

                float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f); // Frame rate
                if (avgFPS > 2000000)                                          // resets avgFPS
                {
                    avgFPS = 0;
                }
                //Clear screen
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

                SDL_RenderClear(gRenderer);
                if (isPause)
                {
                    PauseScreen->Render(gRenderer);
                }

                if (isMenu)
                {
                    MenuScreen->Render(gRenderer);
                }
                if (isFlash)
                {
                    FlashScr->Render(gRenderer);
                }
                if (isGame)
                {
                    GameScreen->Render(gRenderer);
                    CourtYard->Render(gRenderer);
                }
                if (isShop)
                {
                    Shop->Render(gRenderer);
                }
                if (isGameOver)
                {
                    Endgame->Render(gRenderer);
                }
                SDL_RenderPresent(gRenderer);
                int frameTicks = capTimer.getTicks();
                if (frameTicks < SCREEN_TICKS_PER_FRAME)
                {
                    //Wait remaining time
                    SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
                }
            }
        }
    }

    //Free resources and close SDL
    close();
    return 0;
}