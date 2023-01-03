#pragma once
#include <iostream>
#include <string>
#include "Artist.cpp"
#include "../Template/LinkedList.h"
#include "ArtistHashTable.cpp"
#include "TrackHashTable.cpp"
using namespace std;

// BELOW IS THE LINK LIST IMPLEMENTATION
// FOR STORING ALL THE EDGES IN A LINK LIST
class Edge
{
public:
    // BELOW TWO ARTIST ARE THOSE WORKED
    // ON SOME SONGS
    Artist *artist1;
    Artist *artist2;
    // LINKED LIST CONTAINING ALL THOSE TRACKS
    // ON WHCIH ABOVE ARTIST WORKED TOGETHER
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

    // BELOW FUNCTION WILL WITHER CREATE THE GRAPH IF THERE IS NO GRAPH
    // BETWEEN THOSE TWO ARTIST OR IT WILL ADD THE TRACK TO ALREADY CREATED EDGE
    void addTrackToEdge(Artist *, Artist *, Track *);

    // THIS FUNCTION WILL MAP OUT OUR GRAPH WHEN CALLED
    // AFTRE CREATION OF HASHTABLES OF ARTIST AND TRACKS
    void createGraph(TrackHashTable *);
    void printNoOfEdges();
};
