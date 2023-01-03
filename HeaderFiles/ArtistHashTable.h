#pragma once
#include "Artist.cpp"

// BELOW IS THE LINK LIST IMPLEMENTATION OF STORING LINK LIST
// AT EACH HASHTABLE'S ARRAY KEY

class ArtistNode
{
public:
    Artist *ArtistPointer;
    ArtistNode *next;
    ArtistNode();
    ArtistNode(std::string);
};

class ArtistLinkList
{
public:
    ArtistNode *headArtist;
    int collisions;
    ArtistLinkList();
    ArtistLinkList(std::string);

    void addArtistInList(std::string);
    bool findInList(std::string);

    // BELOW FUNCTION WILL RETURN THE POINTER FORM LIST
    Artist *GetArtistPointerFromList(std::string, Track *);
    void displayAll();
    void deleteNode(std::string);
};
class ArtistHashTable
{
public:
    int tablesize;
    ArtistLinkList **hashTableArr;
    ArtistHashTable();
    ArtistHashTable(int);
    ~ArtistHashTable();
    // THIS FUNCTION WILL GIVE THE ARTIST NAME BASED ON IT'S HASHING KEY
    std::string getHeadArtistName(int hashFunctionKey);

    // THIS FUNCTION WILL RETURN THE POINTER OF ARTIST AND
    // WILL ADD THE TRACK WHICH WILL BE PASSED FROM TRACK CONSTRUCTOR
    Artist *GetArtistPointer(std::string name, Track *);

    // THIS FUNCTION WILL RETURN THE ARTIST POINTER BY PASSING NAME
    Artist *ReturnArtistPointer(string);
    // THIS FUNCTION WILL CHECK WHETHER ARRAY KEY IS FREE OR NOT
    bool isAvailable(int ExistOn);

    // BELOW TWO FUNCTIONS ARE FOR COMPUTING THE HASHING KEY
    int computePower(int value, int power);
    int hashFunction(std::string s);

    // PARSER WILL CALL THIS FUNCTION BY SEPERATING THE ARTIST
    // THROUGH SOME FUNCTIONS BASED ON SEMI COLON
    void handler(std::string *arr, int noOfArtists);
    void hashStore(std::string name);
};