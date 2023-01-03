#pragma once
#include "../Template/LinkedList.h"
#include <iostream>
// FORWARD DECLARATION
using namespace std;
// FORWARD DECLARATION BECAUSE THIS FILE IS THE TOP MOST
class Edge;
class Track;
class TrackHashTable;

// BELOW IS THE LINK LIST IMPLEMENTAION FOR
// STORING GRAPH EDGE
class nodeCollab
{
public:
    Edge *object;
    nodeCollab *next;
    explicit nodeCollab(Edge *val);
};

class CollabLinkedList
{
public:
    nodeCollab *head;

    CollabLinkedList();

    bool isempty();

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
    void Displayall();
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

    bool operator==(Artist);
    friend ostream &operator<<(ostream &out, const Artist &obj)
    {
        out << obj.name;
        return out;
    }
    // THIS FUNCTION WILL BE CALLED BY ARTISTHASHTABLE
    // FOR ADDING TRACK IN IT'S ARTIST OBJECT
    void trackHandler(Track *);
};
