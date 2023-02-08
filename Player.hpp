#pragma once
#include "GameObject.hpp"
#include "Ltime.hpp"

class Player : public GameObject //, public HealthBar
{
private:
    LTimer capTimer;
    const int SCREEN_FPS = 30;
    const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS; // Frame Rate
    int frameTicks = capTimer.getTicks();
    bool alive;
    int strength;
    int cash;
    int mVelx;
    int mVely;
    int jump_height;
    int frame;
    bool isMoving;
    bool isAttacking = false;
    bool attack;
    bool jump;
    bool flag;
    SDL_Rect mCollider;
    int Jump = 0;
    bool isJumping = false;
    bool isFalling = false;
    SDL_RendererFlip flip = SDL_FLIP_NONE; // Player orientation is set as set to default initially

public:
    static const int DOT_VEL = 10;          // constant velocity for player movement
    const int WALKING_ANIMATION_FRAMES = 9; // Total number of frames for walking animaton
    Player(Ltexture *texture, int x, int y);
    void Render(SDL_Renderer *);
    void EventHandler(SDL_Event e); // Handles all inputs provided by user
    void move();
    void set_alive(bool);
    void set_mVelx(int);
    void set_mVely(int);
    void set_jump_height(int);
    void set_frame(int);
    void set_isMoving(bool);
    void set_isAttacking(bool);
    void set_jump(bool);
    void set_flag(bool);

    bool get_alive();
    bool get_isMoving();
    bool get_isAttacking();
    bool get_jump();
    bool get_flag();
    int get_mVelx();
    int get_mVely();
    int get_jump_height();
    int get_frame();

    bool Player_Jump(SDL_Rect a, SDL_Rect b);
    SDL_Rect gSpriteClips[15];                   //  An array of type SDL_Rect to keep sprites
    bool checkCollision(SDL_Rect a, SDL_Rect b); // This function checks whether a succesful hit is registered
    bool Confirm_Contact(SDL_Rect, SDL_Rect);
    SDL_Rect getFrame(); // Used to get current frame SDL_rect
    void Free() {}       // Frees Memory
};