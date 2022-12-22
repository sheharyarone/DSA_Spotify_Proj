#pragma once
// FORWARD DECLARATION
class Artist;
class ArtistHashTable;

class ArtistInTrackNode
{
public:
    Artist *ArtistPointer;
    ArtistInTrackNode *next;
    ArtistInTrackNode();
    ArtistInTrackNode(Artist *);
};
class ArtistsForTrack
{
public:
    ArtistInTrackNode *headArtist;
    ArtistsForTrack();
    ArtistsForTrack(std::string allArtistNames, ArtistHashTable *ArtistContainer);
    void addArtistInList(std::string name, ArtistHashTable *ArtistContainer);
    void displayAll();
};

class Track
{
public:
    std::string Title;
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

    Track();
    Track(std::string *array, ArtistHashTable *ArtistContainer);
};