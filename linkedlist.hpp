#pragma once
#include "GameObject.hpp"
struct node
{
    GameObject *data;
    node *next;
};

class link_list
{
private:
    node *head, *tail;

public:
    link_list();
    void createnode(GameObject *);  // inserts node at head
    void insertnode(int, GameObject *); // inserts node at specified position
    void deletenode(int);    // deletes node at speicified position
    void delete_last(); // deletes last node
    void display(SDL_Renderer *gRenderer);   // prints the linkedlist
    void event_handler(SDL_Event e);
};