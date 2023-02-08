#include "Game.hpp"
Game::Game()
{
    Zack = NULL;
    Samurai = NULL;
    KingPass = NULL;
    HealthBarP1 = NULL;
    HealthBarP2 = NULL;
    isGameOver = false;
}

void Game::NewGame(Ltexture *Player1, Ltexture *Player2, Ltexture *Platforms)
{
    Zack = new Player(Player1, 132, 469);
    Samurai = new Enemy(Player2, 1000, 469);
    KingPass = new Arena(Platforms);
    HealthBarP1 = new HealthBar(10, 10);
    HealthBarP2 = new HealthBar(880, 10);
}
void Game::Render(SDL_Renderer *gRenderer)
{

    KingPass->Render(gRenderer);
    Zack->Render(gRenderer);
    Samurai->Render(gRenderer);
    HealthBarP1->DrawBar(gRenderer);
    HealthBarP2->DrawBar(gRenderer);
}
void Game::EventHandler(SDL_Event e)
{
    Zack->EventHandler(e);
    Samurai->EventHandler(e);
}
void Game::Update()
{
    Zack->move();
    Samurai->move();

    if (Zack->checkCollision(Zack->getFrame(), Samurai->getFrame()) == false)
    {
        HealthBarP2->operator-(40);
    }
    if (HealthBarP1->get_HealthBar_health() == 0)
    {
        isGameOver = true;
        who = 0;
    }

    if (Samurai->checkCollision(Zack->getFrame(), Samurai->getFrame()) == false)
    {
        HealthBarP1->operator-(40);
    }
    if (HealthBarP2->get_HealthBar_health() == 0)
    {
        
        isGameOver = true;
        who = 1;
    }
}

Game::~Game()
{
    std::cout << "Game Deconstuctor is called" << std::endl;
    delete Zack;
    delete Samurai;
    delete KingPass;
    delete HealthBarP1;
    delete HealthBarP2;
}

bool Game::GameOver()
{
    return isGameOver;
}

void Game::LoadGame(Ltexture *Player1, Ltexture *Player2, Ltexture *Platforms)
{

    this->NewGame(Player1, Player2, Platforms);
    // Read from Files and send the data to the setters
}

void Game::SaveGame()
{
    // Read Data from getters. and store in files.
}

int Game::getwho()
{
    return who;
}