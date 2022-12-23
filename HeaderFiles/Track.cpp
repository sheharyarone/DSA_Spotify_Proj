#pragma once
#include <iostream>
#include <string>
#include "Artist.cpp"
#include "Track.h"
#include "../Functions/ArtistFunc.cpp"
#include "ArtistHashTable.cpp"

using namespace std;

ArtistInTrackNode::ArtistInTrackNode()
{
    ArtistPointer = NULL;
    next = NULL;
}
ArtistInTrackNode::ArtistInTrackNode(Artist *ArtistPointer)
{
    this->ArtistPointer = ArtistPointer;
    next = NULL;
}
ArtistsForTrack::ArtistsForTrack()
{
    headArtist = NULL;
}
ArtistsForTrack::ArtistsForTrack(string allArtistNames, ArtistHashTable *ArtistContainer, Track *trackPointer)
{
    if (!AreThereManyArtists(allArtistNames))
    {
        // cout << "ADDING ARTIST NAME IN TRACK : " << allArtistNames << endl;
        headArtist = new ArtistInTrackNode(ArtistContainer->GetArtistPointer(allArtistNames, trackPointer));
    }
    else
    {
        int noOfArtist = countArtists(allArtistNames);
        string *arrayOfArtistNames = SeperatingArtist(allArtistNames, noOfArtist);
        headArtist = new ArtistInTrackNode(ArtistContainer->GetArtistPointer(arrayOfArtistNames[0], trackPointer));
        for (int i = 1; i < noOfArtist; i++)
        {
            // cout << "ADDING ARTIST NAME IN TRACK : " << arrayOfArtistNames[i] << endl;
            addArtistInList(arrayOfArtistNames[i], ArtistContainer, trackPointer);
        }
    }
}
void ArtistsForTrack::addArtistInList(string name, ArtistHashTable *ArtistContainer, Track *trackPointer)
{
    ArtistInTrackNode *temp = headArtist;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new ArtistInTrackNode(ArtistContainer->GetArtistPointer(name, trackPointer));
}
void ArtistsForTrack::displayAll()
{
    if (headArtist == NULL)
    {
        cout << "linked list is empty" << endl;
        return;
    }
    cout << endl
         << "----link list items------" << endl;
    ArtistInTrackNode *temp = headArtist;
    while (temp != NULL)
    {
        cout << temp->ArtistPointer->name << " | ";
        temp = temp->next;
    }
    cout << endl
         << "--------------------------" << endl;
}
Track::Track()
{
    Title = "";
    Artists = NULL;
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

Track::Track(string *array, ArtistHashTable *ArtistContainer)
{
    Title = array[1];
    // cout << "TITLE : " << Title << endl;
    Artists = new ArtistsForTrack(array[0], ArtistContainer, this);

    // Genre = NULL;
    // Playlist = NULL;
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