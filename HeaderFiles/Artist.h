#ifndef ARTISTHEADER
#define ARTISTHEADER

#include <iostream>
#include <string>
#include "Track.h"
using namespace std;

// IF ARTIST IS NOT FOUND
// ARTIST HASH TABLE WILL CALL THIS FILE AND WILL MAKE AN ARTIST OBJECT
// IF FOUND
// ARTIST HASH TABLE WILL CALL THIS FOR ADDING THE TRACK TO THAT ARTIST NAME

class ListingArtistSongs
{
public:
    Track *TrackInfo;
    ListingArtistSongs *NextTrack;
    ListingArtistSongs(Track *toBeSave)
    {
        TrackInfo = toBeSave;
        NextTrack = NULL;
    }
    void addTrack(Track *toBeSave)
    {
        if (TrackCheck(toBeSave))
        {
            return;
        };
        // LOGIC FOR ADDING
        // WHILE HEADTRACK WILL REMAIN SAME
    }
    bool TrackCheck(Track *toBeSave)
    {
        // CHECK FOR DUPLICATION CUZ SONGS ARE IN DIFFERENT PLAYLISTS
        // IF FOUND THEN TRUE
        // FALSE ELSEWISE
        return true;
    }
};

class Artist
{
public:
    string name;
    ListingArtistSongs *HeadTrack;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist(string name)
    {
        this->name = name;
        HeadTrack = NULL;
    }
};
#endif // ARTISTHEADER