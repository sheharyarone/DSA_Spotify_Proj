#pragma once
#include <iostream>
#include <string>
#include "Artist.h"
#include "Track.h"
#include "../Template/LinkedList.h"
using namespace std;

Artist::Artist()
{
    this->name = "";
    SongsList = new LinkedList_<Track>;
}
Artist::Artist(string name)
{
    this->name = name;
    SongsList = new LinkedList_<Track>;
}
void Artist::trackHandler(Track *toAddInList)
{
    SongsList->ADD(toAddInList);
}
bool Artist::operator==(Artist test)
{
    return (this->name == test.name);
}