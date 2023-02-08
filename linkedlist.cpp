#include <iostream>
#include "linkedlist.hpp"
using namespace std;

link_list::link_list()
{
    head = NULL;
    tail = NULL;
}

void link_list::createnode(GameObject *value)
{
    node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void link_list::display(SDL_Renderer *gRenderer)
{
    node *temp = new node;
    temp = head;
    while (temp != NULL)
    {
        temp->data->Render(gRenderer);
        temp = temp->next;
    }
}

void link_list::insertnode(int position, GameObject *value)
{
    if (position == 1) // insert at start node
    {
        node *temp = new node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    else    // insert at other than start node
    {
        node *previous = new node;
        node *current = new node;
        node *temp = new node;
        current = head;
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        temp->data = value;
        previous->next = temp;
        temp->next = current;
    }
}

void link_list::deletenode(int position)
{
    if (position == 1) // to delete start node
    {
        node *temp = new node;
        temp = head;
        head = head->next;
        delete temp;
    }

    else // to delete a particular node
    {
        node *current = new node;
        node *previous = new node;
        current = head;
        for (int i = 1; i < position; i++)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
}

void link_list::delete_last()
{
    node *current = new node;
    node *previous = new node;
    current = head;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    tail = previous;
    previous->next = NULL;
    delete current;
}
void link_list::event_handler(SDL_Event e)
{
    node *temp = new node;
    temp = head;
    while (temp != NULL)
    {
        temp->data->EventHandler(e);
        temp = temp->next;
    }
}