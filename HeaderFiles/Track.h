#ifndef TRACKHEADER
#define TRACKHEADER
#include <iostream>
#include <string>
#include "Artist.h"
#include "../Functions/ArtistFunc.h"
#include "ArtistHashTable.h"
using namespace std;

class ArtistInTrackNode
{
public:
    Artist *ArtistPointer;
    ArtistInTrackNode *next;
    ArtistInTrackNode()
    {
        ArtistPointer = NULL;
        next = NULL;
    }
    ArtistInTrackNode(Artist *ArtistPointer)
    {
        this->ArtistPointer = ArtistPointer;
        next = NULL;
    }
};
class ArtistsForTrack
{
public:
    ArtistInTrackNode *headArtist;
    ArtistsForTrack()
    {
        headArtist = NULL;
    }
    ArtistsForTrack(string allArtistNames, ArtistHashTable *ArtistContainer)
    {
        if (!AreThereManyArtists(allArtistNames))
        {
            headArtist = new ArtistInTrackNode(ArtistContainer->GetArtistPointer(allArtistNames));
        }
        else
        {
            int noOfArtist = countArtists(allArtistNames);
            string *arrayOfArtistNames = SeperatingArtist(allArtistNames, noOfArtist);
            headArtist = new ArtistInTrackNode(ArtistContainer->GetArtistPointer(arrayOfArtistNames[0]));
            for (int i = 1; i < noOfArtist; i++)
            {
                addArtistInList(arrayOfArtistNames[i], ArtistContainer);
            }
        }
    }
    void addArtistInList(string name, ArtistHashTable *ArtistContainer)
    {
        ArtistInTrackNode *temp = headArtist;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new ArtistInTrackNode(ArtistContainer->GetArtistPointer(name));
    }
    void displayAll()
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

    Track()
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

    Track(string *array, ArtistHashTable *ArtistContainer)
    {
        Title = array[1];
        Artists = new ArtistsForTrack(array[0], ArtistContainer);
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
};

#endif // TRACKHEADER