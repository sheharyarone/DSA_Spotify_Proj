#pragma once
#include <iostream>
#include <string>
#include "Artist.h"
#include "Track.cpp"
using namespace std;

Artist::Artist()
{
    this->name = "";
    SongsList = new LinkedList_<Track>;
    CollabList = new CollabLinkedList;
}
Artist::Artist(string name)
{
    this->name = name;
    SongsList = new LinkedList_<Track>;
    CollabList = new CollabLinkedList;
}
void Artist::trackHandler(Track *toAddInList)
{
    SongsList->ADD(toAddInList);
}
bool Artist::operator==(Artist test)
{
    return (this->name == test.name);
}