#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../HeaderFiles/TrackHashTable.cpp"
#include "../HeaderFiles/ArtistHashTable.cpp"

using namespace std;

void parseCSV(const string filename, ArtistHashTable *ArtistContainer, TrackHashTable *TrackContainer)
{
    ifstream file(filename);
    string line;
    // FOR SINGLE ROW
    while (getline(file, line))
    {
        istringstream iss(line);
        string *fields = new string[18];
        string field;
        int i = 0;
        int j = 1;
        bool firstLine = true;
        // FOR SINGLE COLUMN
        while (getline(iss, field, ','))
        {
            if (field == "artists")
            {
                break;
            }
            if (j == 2 || j == 18)
            {
                j++;
                continue;
            }
            fields[i] = field;
            i++;
            j++;
        }
        if (field == "artists")
        {
            delete[] fields;
            continue;
        }
        TrackContainer->handler(fields, 18, ArtistContainer);
        delete[] fields;
    }
}

// Artist node *returnFoundArtist(string name)
// {
//     // CALL HASH FUNCTION OF ARTIST AND FIND INDEX
//     // IF THIS INDEX HAS AVL TREE TRAVERSE IT TO FIND THE NODE
//     // RETURN THIS NODE
// }