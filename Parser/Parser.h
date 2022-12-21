#ifndef PARSER
#define PARSER
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../HeaderFiles/TrackHashTable.h";
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
        // FOR SINGLE COLUMN
        while (getline(iss, field, ','))
        {
            if (j == 1 || j == 2 || j == 4 || j == 20)
            {
                j++;
                continue;
            }
            fields[i] = field;
            // CHECK FOR SKIPPING ARTIST CUZ WE ARE TESTING TRACK FOR NOW
            // if (j == 5)
            // {
            //     int ExistOn = h1->hashFunction(field);
            // }
            i++;
            j++;

            // if (!isExists)
        }
        TrackContainer->handler(fields, 18, ArtistContainer);
    }
}

// Artist node *returnFoundArtist(string name)
// {
//     // CALL HASH FUNCTION OF ARTIST AND FIND INDEX
//     // IF THIS INDEX HAS AVL TREE TRAVERSE IT TO FIND THE NODE
//     // RETURN THIS NODE
// }
#endif