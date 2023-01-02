#pragma once
#include <iostream>
#include <string>
#include "Track.cpp"
#include "Genre.h"
using namespace std;

Genre::Genre()
{
    this->name = "";
    GenreTrackList = new LinkedList_<Track>;
}
Genre::Genre(string name)
{
    this->name = name;
    GenreTrackList = new LinkedList_<Track>;
}
void Genre::trackHandler(Track *toAddInList)
{
    GenreTrackList->ADD(toAddInList);
}
bool Genre::operator==(Genre test)
{
    return (this->name == test.name);
}
bool Genre::operator>(Genre test)
{
    return (this->name > test.name);
}
bool Genre::operator<(Genre test)
{
    return (this->name < test.name);
}

ostream &operator<<(ostream &os, const Genre obj)
{
    os << obj.name;
    return os;
}
