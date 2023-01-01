#pragma once
#include <iostream>
#include <string>
#include "Artist.cpp"
#include "Genre.h"
#include "../Template/LinkedList.h"
#include "../Template/AVLTree.h"
// FORWARD DECLARATION
using namespace std;
class ArtistHashTable;

class Track
{
public:
    std::string Title;
    LinkedList_<Artist> *ArtistsOfTrack;
    LinkedList_<Genre> *GenreOfTrack;
    int Duration;
    bool Explicit;
    float Dancebility;
    float Energy;
    int key;
    float Loudness;
    bool Mode;
    float Speechiness;
    float Accousticness;
    float Instrumental;
    float Liveness;
    float Valence;
    float Tempo;
    int TimeSignature;

    Track();
    Track(string *array, ArtistHashTable *ArtistContainer, AVLTree<Genre> *GenreContainer);
    bool operator==(Track test);
    void assigningArtistPointersToTrackClass(string, ArtistHashTable *, Track *);
    bool operator<(Track test);
    bool operator>(Track test);
    
    friend ostream &operator<<(ostream &out, const Track &obj)
    {
        out << obj.Title;
        return out;
    }
};