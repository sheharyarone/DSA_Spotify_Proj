#ifndef ARTISTHASHTABLEHEADER
#define ARTISTHASHTABLEHEADER
#include <iostream>
#include <string>
#include "Artist.h"
// #include "AVLTree.h"

using namespace std;
int noOfCOLLISIONS = 0;
// THIS FILE WILL HANDLE THE REQUEST DIRECTLY FROM PARSER FUNCTION
// IF TRACK IS FOUND THEN IT WILL ADD THE GENRE / PLAYLIST (WHICH WILL BE IMPLEMENTED LATER ON) USING TRACK.H
// IF TRACK IS NOT FOUND THEN IT WILL CALL TRACK.h FILE
class ArtistNode
{
public:
    Artist *ArtistPointer;
    ArtistNode *next;
    ArtistNode(string name)
    {
        ArtistPointer = new Artist(name);
        this->next = NULL;
    }
};

class ArtistLinkList
{
public:
    ArtistNode *headArtist;
    int collisions;

    ArtistLinkList(string name)
    {
        this->headArtist = new ArtistNode(name);
        collisions = 0;
    }

    void addArtistInList(string name)
    {
        collisions++;
        noOfCOLLISIONS++;
        ArtistNode *node = new ArtistNode(name);
        if (headArtist == NULL)
        {
            headArtist = node;
            return;
        }
        ArtistNode *temp = headArtist;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    bool findInList(string name)
    {
        // IF FOUND RETURNS TRUE
        // FALSE OTHERWISE
        ArtistNode *temp = headArtist;
        while (temp != NULL)
        {
            if (name == headArtist->ArtistPointer->name)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    Artist *GetArtistPointerFromList(string name)
    {
        // IF FOUND RETURNS TRUE
        // FALSE OTHERWISE
        ArtistNode *temp = headArtist;
        while (temp != NULL)
        {
            if (name == headArtist->ArtistPointer->name)
            {
                return temp->ArtistPointer;
            }
            temp = temp->next;
        }
        cout << "___________________________________________" << endl;
    }
    void displayAll()
    {
        if (headArtist == NULL)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        cout << endl
             << "----link list items------" << endl;
        ArtistNode *temp = headArtist;
        while (temp != NULL)
        {
            cout << temp->ArtistPointer->name << " | ";
            temp = temp->next;
        }
        cout << endl
             << "--------------------------" << endl;
    }
    void deleteNode(string name)
    {
        // If the list is empty, there is nothing to delete
        if (!headArtist)
            return;
        ArtistNode *head_ = headArtist;
        // If the node to be deleted is the head of the list,
        // update the head to point to the next node
        if (head_->ArtistPointer->name == name)
        {
            ArtistNode *temp = headArtist;
            head_ = head_->next;
            delete temp;
            headArtist = head_;
            return;
        }

        // Otherwise, search the list for the node to be deleted
        ArtistNode *current = head_;
        while (current->next && current->next->ArtistPointer->name != name)
        {
            current = current->next;
        }

        // If the node was found, delete it
        if (current->next)
        {
            ArtistNode *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
};
class ArtistHashTable
{
public:
    int tablesize;
    ArtistLinkList **hashTableArr;

    ArtistHashTable()
    {
        cout << "OBJECT CREATED" << endl;
        // WE CAN ASK THE USER HERE FOR THE SIZE OF HASHTABLE AS WELL
        tablesize = 50011;
        hashTableArr = new ArtistLinkList *[tablesize]();
    }

    ~ArtistHashTable()
    {
        for (int i = 0; i < tablesize; i++)
        {
            ArtistLinkList *temp = hashTableArr[i];
            delete temp;
        }
        delete[] hashTableArr;
    }
    string getHeadArtistName(int hashFunctionKey)
    {
        return (hashTableArr[hashFunctionKey]->headArtist->ArtistPointer->name);
    }
    // GET ARTIST POINTER AND IT WILL BE THERE
    Artist *GetArtistPointer(string name)
    {
        int key = hashFunction(name);
        if (getHeadArtistName(key) == name)
        {
            return hashTableArr[key]->headArtist->ArtistPointer;
        }
        else
        {
            return hashTableArr[key]->GetArtistPointerFromList(name);
        }
    }
    bool isAvailable(int ExistOn)
    {
        // IF ARRAY CONTAINS POINTER = TRUE
        // IN THE ABOVE CASE THIS FUNCTION WILL RETURN FALSE BECAUSE SPACE IS NOT FREE

        // IF ARRAY DOESN'T CONTAINS POINTER = FALSE
        // IN THE ABOVE CASE THIS FUNCTION WILL RETURN TRUE BECAUSE SPACE IS FREE
        return (!(hashTableArr[ExistOn]));
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
        int value = 7;
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

            hashTableArr[key] = new ArtistLinkList(name);
        }
        else if (!(hashTableArr[key]->findInList(name)))
        {
            hashTableArr[key]->addArtistInList(name);
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