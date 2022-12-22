#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../Functions/ArtistFunc.cpp"
#include "../HeaderFiles/ArtistHashTable.cpp"
using namespace std;

void parseArtistCSV(const string filename, ArtistHashTable *ArtistContainer)
{
    ifstream file(filename);
    string line;
    int i = 0;
    while (getline(file, line))
    {
        i++;
        istringstream iss(line);
        string field;
        while (getline(iss, field, ','))
        {
            // SINGLE ARTIST CASE
            if (!AreThereManyArtists(field))
            {
                string *artistName = new string[1];
                artistName[0] = field;
                ArtistContainer->handler(artistName, 1);
                delete[] artistName;
            }
            else
            {
                int noOfArtist = countArtists(field);
                string *arrayOfArtistNames = SeperatingArtist(field, noOfArtist);

                ArtistContainer->handler(arrayOfArtistNames, noOfArtist);

                delete[] arrayOfArtistNames;
            }
        }
    }
}