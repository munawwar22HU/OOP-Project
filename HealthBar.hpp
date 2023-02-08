#pragma once
#include "Bar.hpp"

class HealthBar : public Bar
{ //The health bar creates the health bar and inherits from the bar class
private:
    int health;
    int x; // Coordinates for health bar to display on screen
    int y;
    SDL_Rect rect;

public:
    HealthBar();
    HealthBar(int, int, Ltexture *);
    HealthBar(int x, int y);
    void DrawBar(SDL_Renderer *);
    void set_HealthBar_x(int);
    void set_HealthBar_y(int);
    void set_HealthBar_health(int);

    int get_HealthBar_x();
    int get_HealthBar_y();
    int get_HealthBar_health();
    void operator-(int change); // updates status of health bar after player has been attacked
    void Update(int change);
    ~HealthBar(); // healthbar deconstructor
};