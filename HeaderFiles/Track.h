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
    // CONSTRUCOTR WILL ADD NECESSARY INT'S AND STRINGS TO MEMBERS OF TRACK
    // ALSO IT WILL ADD GENRE AND ARTIST POINTERS INTO TRACK'S LINKED LIST
    // ALSO IT WILL ADD THE TRACK'S POINTER TO THEIR OBJECTS
    Track(string *, ArtistHashTable *, AVLTree<Genre> *);
    bool operator==(Track);

    // THIS FUNCTION WILL ADD TRACK TO ARTIST LIST
    // WILL ADD ARTIST IN TO TRACK'S LINKEDLIST OF STORING ARTIST
    void assigningArtistPointersToTrackClass(string, ArtistHashTable *, Track *);
    bool operator<(Track);
    bool operator>(Track);
    bool operator!=(Track);

    friend ostream &operator<<(ostream &out, const Track &obj)
    {
        out << obj.Title;
        return out;
    }
};