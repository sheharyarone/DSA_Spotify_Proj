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
    LinkedList_<Track> *GenreTrackList;
    Genre();
    Genre(string);
    bool operator==(Genre test);
    bool operator>(Genre test);
    bool operator<(Genre test);
    void trackHandler(Track *);
};