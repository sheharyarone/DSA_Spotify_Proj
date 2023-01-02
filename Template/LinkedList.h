//
// Created by Ali on 22/12/2022.
//

#ifndef DSA_SPOTIFY_PROJ_LINKEDLIST_H
#define DSA_SPOTIFY_PROJ_LINKEDLIST_H
#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T *object;
    Node<T> *next;
    bool operator==(Node<T> test)
    {
        return this->object == test.object;
    }
    Node()
    {
        object = nullptr;
        next = nullptr;
    }
    Node(T *thing)
    {
        object = thing;
        next = nullptr;
    }
};
template <class T>
class LinkedList_
{
public:
    Node<T> *head;
    int collisions;
    LinkedList_()
    {
        head = nullptr;
        collisions = 0;
    }
    LinkedList_(T *newthing)
    {
        head = new Node<T>(newthing);
        head->next = nullptr;
        collisions = 0;
    }
    void ADD(T *additem)
    {
        if (!SearchItem(additem))
        {
            Node<T> *newitem = new Node<T>(additem);
            collisions++;
            if (head == nullptr)
            {
                head = newitem;
            }
            else
            {
                Node<T> *temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = newitem;
            }
        }
        // delete temp;//Comment this out if code not working.
    }
    bool SearchItem(T *SearchItem)
    {
        Node<T> *helper = head;
        while (helper != nullptr)
        {
            if (*(SearchItem) == *(helper->object))
            { // operator overloading in individual classes.
                return true;
            }
            helper = helper->next;
        }
        return false;
    }
    Node<T> GetPointerObject(T *SearchItem)
    {
        Node<T> *helper = head;
        while (helper != nullptr)
        {
            if (*(SearchItem) == *(helper->object))
                return helper;
            helper = helper->next;
        }
        return nullptr; // If nullptr returned it means object not found.
    }
    void Displayall()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << *(temp->object) << endl;
            temp = temp->next;
        }
    }
    void DeleteNode(T *DeleteObject)
    {
        Node<T> *item;
        if (SearchItem(DeleteObject))
        {

            if (*(DeleteObject) == *(head))
            {
                item = head;
                head = head->next;
                delete item;
            }
            else
            {
                Node<T> *item = head;
                Node<T> *previtem;
                while (item != nullptr && (*(DeleteObject) != *(item)))
                {
                    previtem = item;
                    item = item->next;
                }
                previtem->next = item->next;
                delete item;
            }
        }
        else
            return;
    }
};

#endif // DSA_SPOTIFY_PROJ_LINKEDLIST_H
