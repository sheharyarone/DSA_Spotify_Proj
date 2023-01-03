#pragma once
#include <iostream>
#include <string>
#include "Track.cpp"
#include "../Template/LinkedList.h"
using namespace std;
class Genre
{
public:
    string name;
    
    // WE HAVE STORED ALL THE TACKS FOR ONE GENRE IN
    // GENRE OBJECT USING TEPLATE LINKEDLIST CLASS WE HAVE
    LinkedList_<Track> *GenreTrackList;
    Genre();
    Genre(string);
    bool operator==(Genre test);
    bool operator>(Genre test);
    bool operator<(Genre test);

    // THIS FUNCTION WILL BE CALLED FOR ADDING TRACK
    // INTO GENRE OBJECT BY TRACK CONSTRUCTOR
    void trackHandler(Track *);
};