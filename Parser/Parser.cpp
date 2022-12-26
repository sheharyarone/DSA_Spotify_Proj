#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../HeaderFiles/Genre.cpp"
#include "../Template/AVLTree.h"
#include "../HeaderFiles/TrackHashTable.cpp"
#include "../Functions/ArtistFunc.cpp"
#include "../HeaderFiles/ArtistHashTable.cpp"

using namespace std;

void parseGenreCSV(const string filename, AVLTree<Genre> *GenreContainer)
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
            Genre *pointer = new Genre(field);
            GenreContainer->Insert(pointer);
        }
    }
}

void parseCSV(const string filename, ArtistHashTable *ArtistContainer, TrackHashTable *TrackContainer, AVLTree<Genre> *GenreContainer)
{
    ifstream file(filename);
    string line;
    // FOR SINGLE ROW
    while (getline(file, line))
    {
        istringstream iss(line);
        string *fields = new string[17];
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
            if (j == 2)
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
        TrackContainer->handler(fields, 17, ArtistContainer, GenreContainer);
        delete[] fields;
    }
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
                artistName[0] = field;
                ArtistContainer->handler(artistName, 1);
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
