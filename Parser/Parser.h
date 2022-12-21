#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "D:\DSA_Spotify_Proj\HeaderFiles\TrackHashTable.h"
using namespace std;

TrackHashTable *h1 = new TrackHashTable();

void parseCSV(const string filename)
{
    ifstream file(filename);
    string line;
    // FOR SINGLE ROW
    while (getline(file, line))
    {
        istringstream iss(line);
        string fields[18];
        string field;
        int i = 1;
        int j = 1;
        // FOR SINGLE COLUMN
        while (getline(iss, field, ','))
        {
            if (j == 1 || j == 2 || j == 3)
            {
                j++;
                continue;
            }
            // CHECK FOR SKIPPING ARTIST CUZ WE ARE TESTING TRACK FOR NOW
            if (j == 4)
            {
                int ExistOn = h1->hashFunction(field);
            }

            fields[i] = field;
            i++;
            j++;
        }
        // if (!isExists)
    }
}