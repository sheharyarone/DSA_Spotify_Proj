#include <iostream>
#include <string>
#include "Track.h";
using namespace std;

// THIS FILE WILL HANDLE THE REQUEST DIRECTLY FROM PARSER FUNCTION
// IF TRACK IS FOUND THEN IT WILL ADD THE GENRE / PLAYLIST (WHICH WILL BE IMPLEMENTED LATER ON) USING TRACK.H
// IF TRACK IS NOT FOUND THEN IT WILL CALL TRACK.h FILE


class trackHashTable
{
public:
    int tablesize;
    Track *trackarray;

    trackHashTable()
    {
        // WE WILL FIX THE SIZE BASED ON OUR DATA
        // cout << "Enter the size of song hash table: ";
        // cin >> tablesize;
        // trackarray = new Track[tablesize];
    }

    ~trackHashTable()
    {
        for (int i = 0; i < tablesize; i++)
        {
            Track *temp = &trackarray[i];
            delete temp;
        }
        delete[] trackarray;
    }

    int hashFunction(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += (int)s[i];
        }
        return sum % tablesize;
    }

    void hashStore(Track *s)
    {
        int key = hashFunction(s->Title);
        trackarray[key] = *s;
    }
};
