cmake_minimum_required(VERSION 3.23)
project(DSA_Spotify_Proj)

set(CMAKE_CXX_STANDARD 14)

include_directories(HeaderFiles)
include_directories(Parser)

add_executable(DSA_Spotify_Proj
        HeaderFiles/Artist.h
        HeaderFiles/ArtistHashTable.h
        HeaderFiles/CollabUsingGraph.cpp
        HeaderFiles/Genre.h
        HeaderFiles/Track.h
        HeaderFiles/TrackHashTable.h
        Parser/Parser.h
        main.cpp HeaderFiles/AVLTree.h)
