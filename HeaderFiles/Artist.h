#pragma once
#include "../Template/LinkedList.h"
#include <iostream>
// FORWARD DECLARATION
using namespace std;
class Edge;
class Track;
class TrackHashTable;

class nodeCollab
{
public:
    Edge *object;
    nodeCollab *next;
    explicit nodeCollab(Edge *val)
    {
        object = val;
        next = nullptr;
    }
};

class CollabLinkedList
{
public:
    nodeCollab *head;

    CollabLinkedList()
    {
        head = nullptr;
    }

    bool isempty() const
    {
        return head == nullptr;
    }

    int length() const
    {
        nodeCollab *temp = head;
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
        nodeCollab *newnode = new nodeCollab(val);
        if (isempty())
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }
    }
    void printll() const
    {
        nodeCollab *temp = head;
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
    CollabLinkedList *CollabList;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist();
    Artist(std::string);
    void trackHandler(Track *); // WILL BE CALLED BY ARTSITHASHTABLE FOR ADDING TRACK WHILE ITS CREATION
    bool operator==(Artist);
    friend ostream &operator<<(ostream &out, const Artist &obj)
    {
        out << obj.name;
        return out;
    }
};
