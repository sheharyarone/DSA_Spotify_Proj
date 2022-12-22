#ifndef ARTISTHEADER
#define ARTISTHEADER
#include "AVLTREE.h"

#include <iostream>
#include <string>
#include "Track.h"
using namespace std;

// IF ARTIST IS NOT FOUND
// ARTIST HASH TABLE WILL CALL THIS FILE AND WILL MAKE AN ARTIST OBJECT
// IF FOUND
// ARTIST HASH TABLE WILL CALL THIS FOR ADDING THE TRACK TO THAT ARTIST NAME
class ArtistSong
{
public:
    Track *TrackInfo;
    ArtistSong *NextArtistTrack;
    ArtistSong(Track *toBeSave)
    {
        TrackInfo = toBeSave;
        NextArtistTrack = NULL;
    }
};
class ListingArtistSongs
{
public:
    ArtistSong *HeadTrack;
    ArtistSong *NxtToBeSaved;
    ListingArtistSongs(Track *toBeSave)
    {
        HeadTrack = new ArtistSong(toBeSave);
        NxtToBeSaved = NULL;
    }
    void addTrack(Track *toBeSave)
    {
        if (!TrackCheck(toBeSave))
        {
            // NxtToBeSaved WILL BE ON THAT ARTISTNODE NXT TO WHICH SONG NEEDS TO BE ADDED
            NxtToBeSaved->NextArtistTrack = new ArtistSong(toBeSave);
        }
        NxtToBeSaved = NULL;
    }
    bool TrackCheck(Track *toBeSave)
    {
        NxtToBeSaved = HeadTrack;
        while (NxtToBeSaved->NextArtistTrack != NULL)
        {
            // CHECK FOR DUPLICATION CUZ SONGS ARE IN DIFFERENT PLAYLISTS
            if (toBeSave->Title == NxtToBeSaved->TrackInfo->Title)
            {
                // IF FOUND THEN TRUE

                return true;
            }
        }
        // FALSE ELSEWISE
        return false;
    }
};

class Artist
{
public:
    string name;
    ListingArtistSongs *SongsList;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist(){
        SongsList=NULL;
    }
    Artist(string name)
    {
        this->name = name;
        SongsList = NULL;
    }
    bool operator<(Artist RHS){
        return name<RHS.name;
    }
    bool operator>=(Artist RHS){
        return name>=RHS.name;
    }
    bool operator==(Artist RHS){
        return name==RHS.name;
    }
};
ostream & operator<<(ostream & ost,Artist ll){
    ost<<ll.name;
    return ost;
}

#endif // ARTISTHEADER