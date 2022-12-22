#pragma once

class Track;
class ArtistSong
{
public:
    Track *TrackInfo;
    ArtistSong *NextTrack;
    ArtistSong();
    ArtistSong(Track *);
};
class ListingArtistSongs
{
public:
    ArtistSong *HeadTrack;
    ArtistSong *NxtToBeSaved;
    ListingArtistSongs();
    ListingArtistSongs(Track *);
    void addTrack(Track *);
    bool TrackCheck(Track *);
    void displayAll();
};

class Artist
{
public:
    std::string name;
    ListingArtistSongs *SongsList;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist();
    Artist(std::string);
    void trackHandler(Track *); // WILL BE CALLED BY ARTSITHASHTABLE FOR ADDING TRACK WHILE ITS CREATION
};