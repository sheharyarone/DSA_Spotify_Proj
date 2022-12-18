#ifndef ARTISTHASHTABLEHEADER
#define ARTISTHASHTABLEHEADER
#include <iostream>
#include <string>
#include "Artist.h"

using namespace std;

// WE WILL BE STRORING ALL OF OUR ARTIST RECORD HERE
// FIRST OF ALL WHEN ADDING A SONGS WE WILL FIRST CONSIDER ITS ARTIST
// DATA FOR ARTIST WILL COME IN STRING FORM WITH SEMI COLONS AND THIS FILE WILL HANDLE EVERYTHING AFTER THAT
// IF THEY ARE ALREADY HERE IN HASH TABLE THEN WE WILL RETURN THEM IN ARRAY
// IF THEY ARE NOT HERE ( MAYBE 1 OF OTHER 3 ) THEN WE WILL CREATE AND PASS THE POINTERS IN ARRAYS
// WE CAN MAKE A LINK FOR THESE ARTIST AND WILL RETURN THE LINK OF HEAD NODE TO THE ARTIST ATTRIBUTE IN TRACK CLASS
bool manyArtists(string s)
{
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

void printWords(string &input)
{
    string word;
    for (char c : input)
    {
        if (c == ';')
        {
            // Artist *a1 = new Artist();
            word.clear();
        }
        else
        {
            word += c;
        }
    }
    if (!word.empty())
    {
        cout << word << endl;
    }
}

string getArtistName(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        //
    }
}
void createStructures(string *arr)
{
    // track *t1 = new track(arr);

    if (manyArtists(arr[0]))
    {
        int artistnumber = countArtists(arr[0]);
    }
}
#endif // ARTISTHASHTABLEHEADER