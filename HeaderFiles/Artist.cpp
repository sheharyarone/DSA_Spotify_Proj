#pragma once
#include <iostream>
#include <string>
#include "Artist.h"
#include "Track.h"
using namespace std;

ArtistSong::ArtistSong()
{
    TrackInfo = NULL;
    NextArtistTrack = NULL;
}
ArtistSong::ArtistSong(Track *toBeSave)
{
    TrackInfo = toBeSave;
    NextArtistTrack = NULL;
}
ListingArtistSongs::ListingArtistSongs()
{
    HeadTrack = NULL;
    NxtToBeSaved = NULL;
}
ListingArtistSongs::ListingArtistSongs(Track *toBeSave)
{
    HeadTrack = new ArtistSong(toBeSave);
    NxtToBeSaved = NULL;
}
Artist::Artist()
{
    this->name = "";
    SongsList = new ListingArtistSongs();
}
Artist::Artist(string name)
{
    this->name = name;
    SongsList = new ListingArtistSongs();
}

void ListingArtistSongs::addTrack(Track *toBeSave)
{
    if (!TrackCheck(toBeSave))
    {
        // NxtToBeSaved WILL BE ON THAT ARTISTNODE NXT TO WHICH SONG NEEDS TO BE ADDED
        NxtToBeSaved->NextArtistTrack = new ArtistSong(toBeSave);
    }
    NxtToBeSaved = NULL;
}
bool ListingArtistSongs::TrackCheck(Track *toBeSave)
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
        NxtToBeSaved = NxtToBeSaved->NextArtistTrack;
    }
    // FALSE ELSEWISE
    return false;
}