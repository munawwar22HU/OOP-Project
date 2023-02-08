#include "Enemy.hpp"
Enemy::Enemy(Ltexture *texture, int x, int y) : GameObject(texture, x, y)
{
    frame = 0;
    mVelx = 0;
    mVely = 0;
    mCollider.w = 60;
    mCollider.h = 90;
}
void Enemy::Render(SDL_Renderer *gRenderer)
{
    // This is an array of all the required sprites for this character in terms of x, y, w, h for SDL_Rect
    m_ptr->setBlendMode(SDL_BLENDMODE_BLEND);
    gSpriteClips[0] = {6, 13, 66 - 6, 103 - 13};
    gSpriteClips[1] = {15, 134, 62 - 15, 220 - 134};
    gSpriteClips[2] = {78, 130, 138 - 78, 218 - 130};
    gSpriteClips[3] = {160, 126, 227 - 160, 220 - 126};
    gSpriteClips[4] = {260, 128, 322 - 260, 218 - 128};
    gSpriteClips[5] = {351, 126, 406 - 351, 219 - 126};
    gSpriteClips[6] = {432, 130, 482 - 432, 220 - 130};
    gSpriteClips[7] = {253, 268, 313 - 253, 363 - 268};
    gSpriteClips[8] = {332, 267, 408 - 332, 363 - 267};
    gSpriteClips[9] = {431, 267, 540 - 431, 363 - 267};
    gSpriteClips[10] = {15, 846, 72 - 15, 932 - 846};
    gSpriteClips[11] = {100, 822, 155 - 100, 926 - 822};
    gSpriteClips[12] = {175, 803, 226 - 175, 894 - 803};
    gSpriteClips[13] = {463, 818, 520 - 463, 928 - 818};

    if (frame >= WALKING_ANIMATION_FRAMES)
    {
        frame = 0;
    }
    if (attack == false && isJumping == false)
    {
        m_ptr->Render(m_x, m_y, gRenderer, &gSpriteClips[frame], 0, 0, flip); // Render player on screen using render function
        SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
    }
    else if (attack == true && isJumping == false)
    {
        for (int i = 7; i < 10; i++)
        {
            m_ptr->Render(m_x, m_y, gRenderer, &gSpriteClips[i], 0, 0, flip); // Render player on screen using render function
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks + 250);
        }
        frame = 0;
        flag = false;
    }
    else if (attack == false && isJumping == true)
    {
        for (int i = 10; i < 14; i++)
        {
            m_ptr->Render(m_x, m_y, gRenderer, &gSpriteClips[i], 0, 0, flip); // Render player on screen using render function
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
        }
        frame = 0;
        flag = false;
    }

    if (isMoving == true)
    {

        frame = frame + 1; // This animates the movement of Character by incrementing frames
        SDL_Delay(80);     // To delay the transition between frames
    }

    attack = false;
    jump = false;
}
void Enemy::EventHandler(SDL_Event e)
{
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_w:
            mVely -= DOT_VEL; // The player jumps upon pressing up arrow key
            if (isJumping != true)
            {
                isJumping = true; // This flag is to ensure player only jumps when in contact with ground.
            }

            break;
        case SDLK_s:
            mVely += DOT_VEL;
            flag = true;
            break;
        case SDLK_a:
            mVelx -= DOT_VEL;
            isMoving = true;
            flip = SDL_FLIP_HORIZONTAL; // updates orientation of the sprite if required
            break;
        case SDLK_d:
            mVelx += DOT_VEL;
            isMoving = true;
            flip = SDL_FLIP_NONE; // updates orientation of the sprite if required
            break;
        case SDLK_q:
            attack = true;      // q is clicked to attack
            isAttacking = true; // enables attacking flag for player
            break;
        }
    }
    //If a key was released
    else if (e.type == SDL_KEYUP && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_w:
            mVely += DOT_VEL;
            break;
        case SDLK_s:
            mVely -= DOT_VEL;
            break;

        case SDLK_a:
            mVelx += DOT_VEL;
            isMoving = false; // Player movement has stopped
            break;
        case SDLK_d:
            mVelx -= DOT_VEL;
            isMoving = false; // Player movement has stopped
            break;
        case SDLK_q:
            attack = false;
            break;
        }
    }
}
void Enemy::move()
{
    //Move the character left or right
    m_x += mVelx;

    if ((m_x < 0) || (m_x + 60 > 1280))
    {
        //Move back
        m_x -= mVelx;
    }
    if (isJumping == true)
    {
        if (Jump >= 10 || isFalling == true)
        {
            isFalling = true;
            Jump--;
            m_y = m_y + 10;
            if (Jump <= 0)
            {
                isFalling = false;
                isJumping = false;
            }
        }
        else if (Jump <= 0 && isFalling == true)
        {
            Jump - 0;
            isFalling = false;
            isJumping = false;
        }
        else
        {
            Jump++;
            m_y = m_y - 10;
        }
    }
    if (m_y < 0)
    {
        m_y = 0;
    }
    else if (m_y > 570 - 100)
    {
        m_y = 570 - 100;
    }
}
bool Enemy::checkCollision(SDL_Rect a, SDL_Rect b) // Checks whetehr hitboxes of characters are intersecting while attacking or not
{
    if (isAttacking == true)
    {
        //If A is in contact with B so return false
        isAttacking = false;
        if (a.x + a.w >= b.x && a.x + a.w < b.x + b.w)
        {
            return false;
        }
        if (a.x <= b.x + b.w && a.x > b.x)
        {
            return false;
        }
        if (a.y + a.h >= b.y && a.y + a.h < b.y + b.h)
        {
            return false;
        }
        if (a.y <= b.y + b.h && a.y > b.y)
        {
            return false;
        }
    }
    //If A is not in contact with B return true
    isAttacking = false;
    return true;
}
SDL_Rect Enemy::getFrame() // Used to get current frame SDL_rect
{
    mCollider.x = m_x;
    mCollider.y = m_y;
    return mCollider;
}

Enemy::~Enemy()
{
    std::cout << "Enemy Deconstructor is called" << std::endl;
}
void Enemy::set_alive(bool a)
{
    alive = a;
}

void Enemy::set_mVelx(int x)
{
    mVelx = x;
}

void Enemy::set_mVely(int y)
{
    mVely = y;
}

void Enemy::set_jump_height(int h)
{
    jump_height = h;
}

void Enemy::set_frame(int f)
{
    frame = f;
}
void Enemy::set_isMoving(bool m)
{
    isMoving = m;
}
void Enemy::set_isAttacking(bool attack)
{
    isAttacking = attack;
}

void Enemy::set_jump(bool j)
{
    jump = j;
}
void Enemy::set_flag(bool f)
{
    flag = f;
}

bool Enemy::get_alive()
{
    return alive;
}
bool Enemy::get_isMoving()
{
    return isMoving;
}
bool Enemy::get_isAttacking()
{
    return isAttacking;
}
bool Enemy::get_jump()
{
    return Jump;
}
bool Enemy::get_flag()
{
    return flag;
}
int Enemy::get_mVelx()
{
    return mVelx;
}
int Enemy::get_mVely()
{
    return mVely;
}
int Enemy::get_jump_height()
{
    return jump_height;
}
int Enemy::get_frame()
{
    return frame;
}