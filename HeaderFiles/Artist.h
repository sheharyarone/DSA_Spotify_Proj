#pragma once

class Track;
class ArtistSong
{
public:
    Track *TrackInfo;
    ArtistSong *NextArtistTrack;
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
};

class Artist
{
public:
    std::string name;
    ListingArtistSongs *SongsList;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist();
    Artist(std::string);
};