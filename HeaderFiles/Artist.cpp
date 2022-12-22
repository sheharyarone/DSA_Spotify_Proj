#pragma once
#include <iostream>
#include <string>
#include "Artist.h"

using namespace std;

Artist::Artist()
{
    this->name = "";
}
Artist::Artist(string name_)
{

    this->name = name_;
    // SongsList = NULL;
}