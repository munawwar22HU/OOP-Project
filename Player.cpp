#include "Player.hpp"
Player::Player(Ltexture *texture, int x, int y) : GameObject(texture, x, y)
{
    frame = 0;
    mVelx = 0;
    mVely = 0;
    mCollider.w = 64;
    mCollider.h = 100;
}
void Player::Render(SDL_Renderer *gRenderer)
{
    // This is an array of all the required sprites for this character in terms of x, y, w, h for SDL_Rect
    m_ptr->setBlendMode(SDL_BLENDMODE_BLEND);
    gSpriteClips[0] = {90, 20, 64, 100};
    gSpriteClips[1] = {172, 20, 172 - 90, 124 - 20};
    gSpriteClips[2] = {245, 20, 245 - 170, 124 - 20};
    gSpriteClips[3] = {320, 20, 320 - 250, 106};
    gSpriteClips[4] = {394, 20, 394 - 314, 122 - 20};
    gSpriteClips[5] = {470, 20, 470 - 396, 124 - 20};
    gSpriteClips[6] = {540, 20, 610 - 540, 124 - 20};
    gSpriteClips[7] = {615, 20, 615 - 540, 124 - 20};
    gSpriteClips[8] = {616, 20, 690 - 616, 124 - 20};
    gSpriteClips[9] = {8, 160, 92, 265 - 160};
    gSpriteClips[10] = {100, 161, 100 - 10, 260 - 161};
    gSpriteClips[11] = {190, 161, 240 - 112, 263 - 159};
    gSpriteClips[12] = {0, 290, 90, 400 - 290};
    gSpriteClips[13] = {90, 270, 180 - 90, 400 - 270};
    gSpriteClips[14] = {180, 270, 260 - 180, 400 - 270};

    if (frame >= WALKING_ANIMATION_FRAMES)
    {
        frame = 0;
    }
    if (attack == false && isJumping == false)
    {
        m_ptr->Render(m_x, m_y, gRenderer, &gSpriteClips[frame], 0, 0, flip); // Render player on screen using render function
    }
    else if (attack == true && isJumping == false)
    {
        for (int i = 9; i < 12; i++)
        {
            m_ptr->Render(m_x, m_y, gRenderer, &gSpriteClips[i], 0, 0, flip); // Render player on screen using render function
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks + 250);
        }
        frame = 0;
    }
    else if (attack == false && isJumping == true)
    {
        for (int i = 12; i < 15; i++)
        {
            m_ptr->Render(m_x, m_y, gRenderer, &gSpriteClips[i], 0, 0, flip); // Render player on screen using render function
            SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
        }
        frame = 0;
    }

    if (isMoving == true)
    {

        frame = frame + 1;                              // This animates the movement of Character by incrementing frames
        SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks); // To delay the transition between frames
    }

    attack = false;
    jump = false;
}
void Player::EventHandler(SDL_Event e)
{
    //If a key was pressed
    if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
    {
        //Adjust the velocity
        switch (e.key.keysym.sym)
        {
        case SDLK_UP:
            mVely -= DOT_VEL; // The player jumps upon pressing up arrow key
            if (isJumping != true)
            {
                isJumping = true; // This flag is to ensure player only jumps when in contact with ground.
            }

            break;
        case SDLK_DOWN:
            mVely += DOT_VEL;
            flag = true;
            break;
        case SDLK_LEFT:
            mVelx -= DOT_VEL;
            isMoving = true;
            flip = SDL_FLIP_HORIZONTAL; // updates orientation of the sprite if required
            break;
        case SDLK_RIGHT:
            mVelx += DOT_VEL;
            isMoving = true;
            flip = SDL_FLIP_NONE; // updates orientation of the sprite if required
            break;
        case SDLK_SPACE:
            attack = true;      // spacebar is clicked to attack
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
        case SDLK_UP:
            mVely += DOT_VEL;
            break;
        case SDLK_DOWN:
            mVely -= DOT_VEL;
            break;

        case SDLK_LEFT:
            mVelx += DOT_VEL;
            isMoving = false; // Player movement has stopped
            break;
        case SDLK_RIGHT:
            mVelx -= DOT_VEL; // Player movement has stopped
            isMoving = false;
            break;
        }
    }
}
void Player::move()
{
    //Move the Character left or right
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
bool Player::checkCollision(SDL_Rect a, SDL_Rect b) // Checks whetehr hitboxes of characters are intersecting while attacking or not
{
    //If A is in contact with B so return false
    if (isAttacking == true)
    {
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

SDL_Rect Player::getFrame() // Used to get current frame SDL_rect
{
    mCollider.x = m_x;
    mCollider.y = m_y;

    return mCollider;
}
void Player::set_alive(bool a)
{
    alive = a;
}

void Player::set_mVelx(int x)
{
    mVelx = x;
}

void Player::set_mVely(int y)
{
    mVely = y;
}

void Player::set_jump_height(int h)
{
    jump_height = h;
}

void Player::set_frame(int f)
{
    frame = f;
}
void Player::set_isMoving(bool m)
{
    isMoving = m;
}
void Player::set_isAttacking(bool attack)
{
    isAttacking = attack;
}

void Player::set_jump(bool j)
{
    jump = j;
}
void Player::set_flag(bool f)
{
    flag = f;
}

bool Player::get_alive()
{
    return alive;
}
bool Player::get_isMoving()
{
    return isMoving;
}
bool Player::get_isAttacking()
{
    return isAttacking;
}
bool Player::get_jump()
{
    return Jump;
}
bool Player::get_flag()
{
    return flag;
}
int Player::get_mVelx()
{
    return mVelx;
}
int Player::get_mVely()
{
    return mVely;
}
int Player::get_jump_height()
{
    return jump_height;
}
int Player::get_frame()
{
    return frame;
}