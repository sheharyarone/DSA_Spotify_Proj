#pragma once
#include "Track.cpp"
#include "ArtistHashTable.cpp"
class TrackNode
{
public:
    Track *TrackPointer;
    TrackNode *next;
    TrackNode();

    // THIS CONSTRUCTOR OF NODE WILL PASS THESE ARGUMENTS TO TRACK'S
    // CONSTRUCTOR AND IT WILL ADD NECESSARY POINTERS INTO TRACK'S OBJECT
    TrackNode(std::string *array, ArtistHashTable *, AVLTree<Genre> *);
};

class LinkedList
{
public:
    TrackNode *head;
    int collisions;
    LinkedList();
    LinkedList(std::string *, ArtistHashTable *, AVLTree<Genre> *);
    // HASHTABLE IS PASSING ALL NECESSARY PARAMETERS DOWN
    void addTrackInList(std::string *, ArtistHashTable *, AVLTree<Genre> *);

    // THIS WILL BE USED BEFORE CREATING THE OBJECT OF TRACK
    // TO AVOID DUPLICATION AND TO CHECK IF THERE IS CHAINING
    // WHETHER THE TRACK IS IN CHAINING OR NOT
    bool findInList(std::string);
    void displayAll();

    // THIS WILL RETURN THE TRACK POINTER
    // IF PASSE THE STRING
    Track *getTrackPointer(string);
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
    // THIS FUNCITON WILL TELL GIVE US
    // THE SITUATION OF ARRAY AT SPECIFIC KEY
    bool isAvailable(int);

    // BOTH FUNCTIONS ARE INLVOLVED IN COMPUTING THE HASHKEY
    int computePower(int, int);
    int hashFunction(std::string);

    // HANDLER WILL BE CALLED BY PARSER FUNCTION
    // ALL THESE PARAMETERS WILL BE PASSED DOWN BY FUNCTIONS
    // TO ADD TRACK INTO REQUIRED OBJECTS AND
    // ADD THE DATA FROM THESE CONTAINERS TO TRACK OBJECT
    void hashStore(std::string *, ArtistHashTable *, AVLTree<Genre> *);
    void handler(std::string *, int, ArtistHashTable *, AVLTree<Genre> *);
};
