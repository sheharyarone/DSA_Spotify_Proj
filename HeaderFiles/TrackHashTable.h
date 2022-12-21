#ifndef TRACKHASHTABLEHEADER
#define TRACKHASHTABLEHEADER
#include <iostream>
#include <string>
#include "Track.h"
#include "ArtistHashTable.h"

using namespace std;
// THIS FILE WILL HANDLE THE REQUEST DIRECTLY FROM PARSER FUNCTION
// IF TRACK IS FOUND THEN IT WILL ADD THE GENRE / PLAYLIST (WHICH WILL BE IMPLEMENTED LATER ON) USING TRACK.H
// IF TRACK IS NOT FOUND THEN IT WILL CALL TRACK.h FILE
class TrackNode
{
public:
    Track *TrackPointer;
    TrackNode *next;
    TrackNode() {}
    TrackNode(string *array, ArtistHashTable *ArtistContainer)
    {
        TrackPointer = new Track(array, ArtistContainer); // IDR HM ARRAY PASS KRA DEI GY OR 1 FUNCITON BNA DEI GY JO ARTIST KE POINTER UTHA KR LYE GA
        this->next = NULL;
    }
};

class LinkedList
{
public:
    TrackNode *head;
    int collisions;
    LinkedList() {}
    LinkedList(string *array, ArtistHashTable *ArtistContainer)
    {
        this->head = new TrackNode(array, ArtistContainer);
        collisions = 0;
    }

    void addTrackInList(string *array, ArtistHashTable *ArtistContainer)
    {
        collisions++;
        TrackNode *node = new TrackNode(array, ArtistContainer);
        if (head == NULL)
        {
            head = node;
            return;
        }
        TrackNode *temp = head;
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
        TrackNode *temp = head;
        while (temp != NULL)
        {
            if (name == head->TrackPointer->Title)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    void displayAll()
    {
        if (head == NULL)
        {
            cout << "linked list is empty" << endl;
            return;
        }
        cout << endl
             << "----link list items------" << endl;
        TrackNode *temp = head;
        while (temp != NULL)
        {
            cout << temp->TrackPointer->Title << " | ";
            temp = temp->next;
        }
        cout << endl
             << "--------------------------" << endl;
    }
    void deleteNode(string name)
    {
        // If the list is empty, there is nothing to delete
        if (!head)
            return;
        TrackNode *head_ = head;
        // If the node to be deleted is the head of the list,
        // update the head to point to the next node
        if (head_->TrackPointer->Title == name)
        {
            TrackNode *temp = head;
            head_ = head_->next;
            delete temp;
            head = head_;
            return;
        }

        // Otherwise, search the list for the node to be deleted
        TrackNode *current = head_;
        while (current->next && current->next->TrackPointer->Title != name)
        {
            current = current->next;
        }

        // If the node was found, delete it
        if (current->next)
        {
            TrackNode *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }
};
class TrackHashTable
{
public:
    int tablesize;
    LinkedList **hashTableArr;

    TrackHashTable()
    {
        cout << "OBJECT CREATED" << endl;
        // WE CAN ASK THE USER HERE FOR THE SIZE OF HASHTABLE AS WELL
        tablesize = 50011;
        hashTableArr = new LinkedList *[tablesize]();
    }

    ~TrackHashTable()
    {
        for (int i = 0; i < tablesize; i++)
        {
            LinkedList *temp = hashTableArr[i];
            delete temp;
        }
        delete[] hashTableArr;
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

    void hashStore(string *arr, ArtistHashTable *ArtistContainer)
    {
        int key = hashFunction(arr[1]);

        if (isAvailable(key))
        {

            hashTableArr[key] = new LinkedList(arr, ArtistContainer);
        }
        else if (!(hashTableArr[key]->findInList(arr[1])))
        {
            hashTableArr[key]->addTrackInList(arr, ArtistContainer);
        }
    }

    void handler(string *arr, int noOfTracks, ArtistHashTable *ArtistContainer)
    {
        hashStore(arr, ArtistContainer);
    }
};

#endif // TrackHashTableHEADER