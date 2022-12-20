#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../HeaderFiles/ArtistHashTable.h"
using namespace std;

bool AreThereManyArtists(string s)
{
    // TRUE IF SEMI COLON IS PRESENT
    // FALSE OTHERWISE
    return (s.find(';') != string::npos);
}

int countArtists(string s)
{
    int count = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ';')
        {
            count++;
        }
    }
    return count;
}
string *SeperatingArtist(string s, int noOfArtist)
{
    string *ArtistArr = new string[noOfArtist];

    string word;
    int counter = 0;
    for (char c : s)
    {
        if (c == ';')
        {
            ArtistArr[counter] = word;
            counter++;
            word.clear();
        }
        else
        {
            word += c;
        }
    }

    if (!word.empty())
    {
        ArtistArr[counter] = word;
        counter++;
    }
    return ArtistArr;
}

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