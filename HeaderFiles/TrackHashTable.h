#pragma once
#include "Track.cpp"
#include "ArtistHashTable.cpp"
class TrackNode
{
public:
    Track *TrackPointer;
    TrackNode *next;
    TrackNode();
    TrackNode(std::string *array, ArtistHashTable *);
};

class LinkedList
{
public:
    TrackNode *head;
    int collisions;
    LinkedList();
    LinkedList(std::string *, ArtistHashTable *);

    void addTrackInList(std::string *, ArtistHashTable *);

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

    void hashStore(std::string *, ArtistHashTable *);

    void handler(std::string *, int, ArtistHashTable *);
};
