
#pragma once
// #include "Track.h"
// class ArtistSong
// {
// public:
//     Track *TrackInfo;
//     ArtistSong *NextArtistTrack;
//     ArtistSong()
//     {
//         TrackInfo = NULL;
//         NextArtistTrack = NULL;
//     }
//     ArtistSong(Track *toBeSave)
//     {
//         TrackInfo = toBeSave;
//         NextArtistTrack = NULL;
//     }
// };
// class ListingArtistSongs
// {
// public:
//     ArtistSong *HeadTrack;
//     ArtistSong *NxtToBeSaved;
//     ListingArtistSongs()
//     {
//         HeadTrack = NULL;
//         NxtToBeSaved = NULL;
//     }
//     ListingArtistSongs(Track *toBeSave)
//     {
//         HeadTrack = new ArtistSong(toBeSave);
//         NxtToBeSaved = NULL;
//     }
//     void addTrack(Track *toBeSave)
//     {
//         if (!TrackCheck(toBeSave))
//         {
//             // NxtToBeSaved WILL BE ON THAT ARTISTNODE NXT TO WHICH SONG NEEDS TO BE ADDED
//             NxtToBeSaved->NextArtistTrack = new ArtistSong(toBeSave);
//         }
//         NxtToBeSaved = NULL;
//     }
//     bool TrackCheck(Track *toBeSave)
//     {
//         NxtToBeSaved = HeadTrack;
//         while (NxtToBeSaved->NextArtistTrack != NULL)
//         {
//             // CHECK FOR DUPLICATION CUZ SONGS ARE IN DIFFERENT PLAYLISTS
//             if (toBeSave->Title == NxtToBeSaved->TrackInfo->Title)
//             {
//                 // IF FOUND THEN TRUE

//                 return true;
//             }
//         }
//         // FALSE ELSEWISE
//         return false;
//     }
// };

class Artist
{
public:
    std::string name;
    // ListingArtistSongs *SongsList;
    // FROM NXT NODE WE WILL SEE ALL THE TRACKS
    Artist();
    Artist(std::string);
};