#ifndef TRACKHASHTABLEHEADER
#define TRACKHASHTABLEHEADER
#include <iostream>
#include <string>
#include "Track.h"
using namespace std;

// THIS FILE WILL HANDLE THE REQUEST DIRECTLY FROM PARSER FUNCTION
// IF TRACK IS FOUND THEN IT WILL ADD THE GENRE / PLAYLIST (WHICH WILL BE IMPLEMENTED LATER ON) USING TRACK.H
// IF TRACK IS NOT FOUND THEN IT WILL CALL TRACK.h FILE

class TrackHashTable
{
public:
    int tablesize;
    Track **trackarray;

    TrackHashTable()
    {
        tablesize = 100000;
        trackarray = new Track *[tablesize];
    }

    ~TrackHashTable()
    {
        for (int i = 0; i < tablesize; i++)
        {
            Track *temp = trackarray[i];
            delete temp;
        }
        delete[] trackarray;
    }
    bool isAvailable(int ExistOn)
    {
        // IF ARRAY CONTAINS POINTER = TRUE
        // IN THE ABOVE CASE THIS FUNCTION WILL RETURN FALSE BECAUSE SPACE IS NOT FREE

        // IF ARRAY DOESN'T CONTAINS POINTER = FALSE
        // IN THE ABOVE CASE THIS FUNCTION WILL RETURN TRUE BECAUSE SPACE IS FREE
        return (!(trackarray[ExistOn]));
    }

    int hashFunction(string s)
    {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += (int)s[i];
        }
        // SUM TO BE MULTIPLIED BY PRIME NUMBER
        return (sum % tablesize);
    }

    void hashStore(Track *s)
    {
        int key = hashFunction(s->Title);
        if (isAvailable(key))
        {
            trackarray[key] = s;
        }
    }
    void handler(string arr[])
    {
    }
};
#endif // TRACKHASHTABLEHEADER