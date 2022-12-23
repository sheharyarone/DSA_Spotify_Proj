#pragma once
#include "../Template/LinkedList.h"
class Track;

class Artist
{
public:
    std::string name;
    // ListingArtistSongs *SongsList;
    LinkedList_<Track> *SongsList;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist();
    Artist(std::string);
    void trackHandler(Track *); // WILL BE CALLED BY ARTSITHASHTABLE FOR ADDING TRACK WHILE ITS CREATION
    bool operator==(Artist test);
};