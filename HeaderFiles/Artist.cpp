#pragma once
#include <iostream>
#include <string>
#include "Artist.h"
#include "Track.h"
using namespace std;

ArtistSong::ArtistSong()
{
    TrackInfo = NULL;
    NextTrack = NULL;
}
ArtistSong::ArtistSong(Track *toBeSave)
{
    TrackInfo = toBeSave;
    NextTrack = NULL;
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
    if (HeadTrack == NULL)
    {
        HeadTrack = new ArtistSong(toBeSave);
        return;
    }
    if (!TrackCheck(toBeSave))
    {
        // NxtToBeSaved WILL BE ON THAT ARTISTNODE NXT TO WHICH SONG NEEDS TO BE ADDED
        NxtToBeSaved->NextTrack = new ArtistSong(toBeSave);
    }
    NxtToBeSaved = NULL;
}
bool ListingArtistSongs::TrackCheck(Track *toBeSave)
{
    NxtToBeSaved = HeadTrack;
    while (NxtToBeSaved->NextTrack != NULL)
    {
        // CHECK FOR DUPLICATION CUZ SONGS ARE IN DIFFERENT PLAYLISTS
        if (toBeSave->Title == NxtToBeSaved->TrackInfo->Title)
        {
            // IF FOUND THEN TRUE
            return true;
        }
        NxtToBeSaved = NxtToBeSaved->NextTrack;
    }
    // FALSE ELSEWISE
    return false;
}
void Artist::trackHandler(Track *toAddInList)
{
    SongsList->addTrack(toAddInList);
}
void ListingArtistSongs::displayAll()
{

    if (HeadTrack == NULL)
    {
        cout << "linked list is empty" << endl;
        return;
    }
    cout << endl
         << "----link list items------" << endl;
    ArtistSong *temp = HeadTrack;
    while (temp != NULL)
    {
        cout << temp->TrackInfo->Title << " | ";
        temp = temp->NextTrack;
    }
    cout << endl
         << "--------------------------" << endl;
}