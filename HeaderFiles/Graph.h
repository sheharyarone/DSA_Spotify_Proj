#pragma once
#include <iostream>
#include <string>
#include "Artist.cpp"
#include "../Template/LinkedList.h"
#include "ArtistHashTable.cpp"
#include "TrackHashTable.cpp"
using namespace std;

class Edge
{
public:
    Artist *artist1;
    Artist *artist2;
    LinkedList_<Track> *collabTracks;

    Edge();
    Edge(Artist *, Artist *);
    bool operator==(Edge test);
};

class PointerToEdge
{
public:
    Edge *edgePointer;
    PointerToEdge *next;
    PointerToEdge();
    PointerToEdge(Artist *, Artist *);
};

class EdgeLinkedList
{
public:
    PointerToEdge *head;
    int noOfEdges;

    EdgeLinkedList();
    void addTrackToEdge(Artist *, Artist *, Track *);
    void createGraph(TrackHashTable *);
    void printEdges();
};
