#pragma once
#include "Artist.cpp"

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
    std::string getHeadArtistName(int hashFunctionKey);
    // GET ARTIST POINTER AND IT WILL BE THERE
    Artist *GetArtistPointer(std::string name, Track *);
    
    //new function add by AON.
    Artist* ReturnArtistPointer(string);
    bool isAvailable(int ExistOn);

    int computePower(int value, int power);

    int hashFunction(std::string s);
    void hashStore(std::string name);

    void handler(std::string *arr, int noOfArtists);
};