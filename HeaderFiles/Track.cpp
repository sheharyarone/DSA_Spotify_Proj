#pragma once
#include <iostream>
#include <string>
#include "Artist.cpp"
#include "Track.h"
#include "Genre.h"
#include "../Functions/ArtistFunc.cpp"
#include "ArtistHashTable.cpp"

using namespace std;

Track::Track()
{
    Title = "";
    GenreOfTrack = NULL;
    ArtistsOfTrack = NULL;
    Duration = 0;
    Explicit = 0;
    Dancebility = 0;
    Energy = 0;
    key = 0;
    Loudness = 0;
    Mode = 0;
    Speechiness = 0;
    Accousticness = 0;
    Instrumental = 0;
    Liveness = 0;
    Valence = 0;
    Tempo = 0;
    TimeSignature = 0;
}
Track::Track(string *array, ArtistHashTable *ArtistContainer, AVLTree<Genre> *GenreContainer)
{
    Title = array[1];
    ArtistsOfTrack = new LinkedList_<Artist>;
    assigningArtistPointersToTrackClass(array[0], ArtistContainer, this);

    GenreOfTrack = new LinkedList_<Genre>;
    // GETTING GENRE POINTER FROM ITS AVL TREE
    Genre *pointerOfGenre = GenreContainer->Search(array[16]);
    // ADDING GENRE IN TRACK
    GenreOfTrack->ADD(pointerOfGenre);
    // ADDING TRACK IN GENRE OBJECT LINKED LIST
    pointerOfGenre->GenreTrackList->ADD(this);

    Duration = stoi(array[2]);
    Explicit = stoi(array[3]);
    Dancebility = stof(array[4]);
    Energy = stof(array[5]);
    key = stoi(array[6]);
    Loudness = stof(array[7]);
    Mode = stoi(array[8]);
    Speechiness = stof(array[9]);
    Accousticness = stof(array[10]);
    Instrumental = stof(array[11]);
    Liveness = stof(array[12]);
    Valence = stof(array[13]);
    Tempo = stof(array[14]);
    TimeSignature = stoi(array[15]);
}
bool Track::operator==(Track test_)
{
    return (this->Title == test_.Title);
}
void Track::assigningArtistPointersToTrackClass(string allArtistNames, ArtistHashTable *ArtistContainer, Track *trackPointer)
{
    if (!AreThereManyArtists(allArtistNames))
    {
        Artist *addPlz = ArtistContainer->GetArtistPointer(allArtistNames, trackPointer);
        ArtistsOfTrack->ADD(addPlz);
    }
    else
    {
        int noOfArtist = countArtists(allArtistNames);
        string *arrayOfArtistNames = SeperatingArtist(allArtistNames, noOfArtist);
        for (int i = 0; i < noOfArtist; i++)
        {
            ArtistsOfTrack->ADD(ArtistContainer->GetArtistPointer(arrayOfArtistNames[i], trackPointer));
        }
    }
}
bool Track::operator<(Track test)
{
    return (this->Title < test.Title);
}
bool Track::operator>(Track test)
{
    return (this->Title > test.Title);
}