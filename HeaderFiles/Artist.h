#pragma once
#include "../Template/LinkedList.h"
#include <iostream>
// FORWARD DECLARATION
using namespace std;
class Edge;
class Track;
class TrackHashTable;

class nodeF
{
public:
    Edge *object;
    nodeF *next;
    explicit nodeF(Edge *val)
    {
        object = val;
        next = nullptr;
    }
};

class linkedListEdge
{
public:
    nodeF *head;
    nodeF *tail;
    nodeF *ploc;
    nodeF *loc;

    linkedListEdge()
    {
        head = nullptr;
        tail = nullptr;
        ploc = nullptr;
        loc = nullptr;
    }

    bool isempty() const
    {
        return head == nullptr;
    }

    int length() const
    {
        nodeF *temp = head;
        int n = 0;

        while (temp != nullptr)
        {
            n++;
            temp = temp->next;
        }
        return n;
    }

    void ADD(Edge *val)
    {
        nodeF *newnode = new nodeF(val);
        if (isempty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void printll() const
    {
        nodeF *temp = head;
        while (temp != nullptr)
        {
            cout << temp->object << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class Artist
{
public:
    std::string name;
    LinkedList_<Track> *SongsList;
    linkedListEdge *CollabList;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist();
    Artist(std::string);
    void trackHandler(Track *); // WILL BE CALLED BY ARTSITHASHTABLE FOR ADDING TRACK WHILE ITS CREATION
    bool operator==(Artist);
};
