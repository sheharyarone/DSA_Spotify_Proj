#ifndef TRACKHEADER
#define TRACKHEADER

#include <iostream>
#include <string>
#include "Artist.h"
using namespace std;

// THIS FILE WILL BE CALLED IF TRACK IS BEING ADDED FOR THE VERY FIRST TIME
// OR IF TRACK IS ALREADY IN TRACK HASH TABLE THEN GENRE/ PLAYLIST WILL BE THE REQUIRED THING

class ArtistsForTrack
{
public:
    Artist *ArtistName;
    ArtistsForTrack *NextArtist;
    ArtistsForTrack()
    {
        //
    }
};

class Track
{
public:
    string Title;
    ArtistsForTrack *Artists;
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

    Track(string *array)
    {
        Title = array[4];
        Artists = NULL;
        // Genre = NULL;
        // Playlist = NULL;
        Duration = stoi(array[6]);
        Explicit = stoi(array[7]);
        Dancebility = stof(array[8]);
        Energy = stof(array[9]);
        key = stoi(array[10]);
        Loudness = stof(array[11]);
        Mode = stoi(array[12]);
        Speechiness = stof(array[13]);
        Accousticness = stof(array[14]);
        Instrumental = stof(array[15]);
        Liveness = stof(array[16]);
        Valence = stof(array[17]);
        Tempo = stof(array[18]);
        TimeSignature = stoi(array[19]);
    }
};

#endif // TRACKHEADER