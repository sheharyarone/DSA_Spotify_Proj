#ifndef ARTISTHASHTABLEHEADER
#define ARTISTHASHTABLEHEADER
#include <iostream>
#include <string>
#include "Artist.h"

#include "AVLTree.h"

using namespace std;
int noOfCOLLISIONS = 0;
// THIS FILE WILL HANDLE THE REQUEST DIRECTLY FROM PARSER FUNCTION
// IF TRACK IS FOUND THEN IT WILL ADD THE GENRE / PLAYLIST (WHICH WILL BE IMPLEMENTED LATER ON) USING TRACK.H
// IF TRACK IS NOT FOUND THEN IT WILL CALL TRACK.h FILE
class ArtistHashTable
{
public:
    int tablesize;
    avl_tree<Artist> **trackarray;

    ArtistHashTable(int size)
    {
        cout << "OBJECT CREATED" << endl;
        // WE CAN ASK THE USER HERE FOR THE SIZE OF HASHTABLE AS WELL
        tablesize = size;
        trackarray = new avl_tree<Artist> * [size]();
    }


    ~ArtistHashTable()
    {
        for (int i = 0; i < tablesize; i++)
        {
            //LinkedList *temp = trackarray[i];
            //delete temp;
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

    int computePower(int value, int power)
    {
        if (power != 0)
            return (value * computePower(value, power - 1));
        else
            return 1;
    }

    int hashFunction(string s)
    {
        long long int sum = 0;
        int value = 3;
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = tolower(s[i]);
            sum += s[i] * computePower(value, i);
            ;
        }
        // SUM TO BE MULTIPLIED BY PRIME NUMBER
        // Will add table size over here rather than a random number.
        if (sum < 0)
            sum *= -1;
        return (sum % tablesize);
    }

    void hashStore(string name)
    {
        int key = hashFunction(name);
        if (isAvailable(key))
        {
            trackarray[key] = new avl_tree<Artist>;
            trackarray[key]->insert(trackarray[key]->root,Artist(name));

        }
        else
        {
            //trackarray[key]->addArtistInList(name);
        }
    }

    void handler(string *arr, int noOfArtists)
    {
        for (int i = 0; i < noOfArtists - 1; i++)
        {
            hashStore(arr[i]);
        }
    }
};
// WE WILL BE STRORING ALL OF OUR ARTIST RECORD HERE
// FIRST OF ALL WHEN ADDING A SONGS WE WILL FIRST CONSIDER ITS ARTIST
// DATA FOR ARTIST WILL COME IN STRING FORM WITH SEMI COLONS AND THIS FILE WILL HANDLE EVERYTHING AFTER THAT
// IF THEY ARE ALREADY HERE IN HASH TABLE THEN WE WILL RETURN THEM IN ARRAY
// IF THEY ARE NOT HERE ( MAYBE 1 OF OTHER 3 ) THEN WE WILL CREATE AND PASS THE POINTERS IN ARRAYS
// WE CAN MAKE A LINK FOR THESE ARTIST AND WILL RETURN THE LINK OF HEAD NODE TO THE ARTIST ATTRIBUTE IN TRACK CLASS

#endif // ARTISTHASHTABLEHEADER