#pragma once
#include "Track.cpp"
#include "ArtistHashTable.cpp"
class TrackNode
{
public:
    Track *TrackPointer;
    TrackNode *next;
    TrackNode();
    TrackNode(std::string *array, ArtistHashTable *, AVLTree<Genre> *);
};

class LinkedList
{
public:
    TrackNode *head;
    int collisions;
    LinkedList();
    LinkedList(std::string *, ArtistHashTable *, AVLTree<Genre> *);

    void addTrackInList(std::string *, ArtistHashTable *, AVLTree<Genre> *);

    bool findInList(std::string);
    void displayAll();

    void deleteNode(std::string);
};
class TrackHashTable
{
public:
    int tablesize;
    LinkedList **hashTableArr;
    TrackHashTable();

    TrackHashTable(int);

    ~TrackHashTable();

    bool isAvailable(int);

    int computePower(int, int);
    int hashFunction(std::string);

    void hashStore(std::string *, ArtistHashTable *, AVLTree<Genre> *);

    void handler(std::string *, int, ArtistHashTable *, AVLTree<Genre> *);
};
