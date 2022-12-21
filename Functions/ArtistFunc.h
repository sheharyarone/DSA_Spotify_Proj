#ifndef ARTISTFUNC
#define ARTISTFUNC

#include <iostream>
#include <string>
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
#endif