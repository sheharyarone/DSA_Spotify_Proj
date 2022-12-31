#pragma once
#include <iostream>
#include <string>
#include "Artist.cpp"
#include "../Template/LinkedList.h"
#include "ArtistHashTable.cpp"
using namespace std;

class Edge
{
public:
    Artist *artist1;
    Artist *artist2;
    LinkedList_<Track> *collabTracks;

    Edge();
    Edge(Artist *, Artist *);
};

class PointerToEdge
{
public:
    Edge *edgePointer;
    PointerToEdge *next;
    PointerToEdge(Artist *, Artist *);
};

class EdgeLinkedList
{
public:
    PointerToEdge *head;

    EdgeLinkedList()
    {
        head = nullptr;
    }
};
