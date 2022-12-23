#pragma once
#include "Artist.cpp"
#include "../Template/LinkedList.h"
// FORWARD DECLARATION
class ArtistHashTable;

class Track
{
public:
    std::string Title;
    LinkedList_<Artist> *ArtistsOfTrack;
    // singlyNode<string> *Genre;
    // singlyNode<string> *Playlist;
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
    Track(std::string *, ArtistHashTable *);
    bool operator==(Track test);
    void addArtistInList(string, ArtistHashTable *, Track *);
};