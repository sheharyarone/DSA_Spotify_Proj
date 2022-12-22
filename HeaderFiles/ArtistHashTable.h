#ifndef ARTISTHASHTABLEHEADER
#define ARTISTHASHTABLEHEADER
#include <iostream>
#include <string>
#include "Artist.h"

using namespace std;
int noOfArtist = 0;
int noOfCollisionsInArtist = 0;

class ArtistNode
{
public:
    Artist *ArtistPointer;
    ArtistNode *next;
    ArtistNode()
    {
        ArtistPointer = NULL;
        next = NULL;
    }
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
    ArtistLinkList()
    {
        headArtist = NULL;
        collisions = 0;
    }
    ArtistLinkList(string name)
    {
        this->headArtist = new ArtistNode(name);
        collisions = 0;
    }

    void addArtistInList(string name)
    {
        noOfCollisionsInArtist++;
        collisions++;
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
    bool findInList(string name_)
    {
        // IF FOUND RETURNS TRUE
        // FALSE OTHERWISE
        ArtistNode *temp = headArtist;
        while (temp != NULL)
        {
            if (name_ == temp->ArtistPointer->name)
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
        return NULL;
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

    ArtistHashTable(int size = 50011)
    {
        tablesize = size;
        hashTableArr = new ArtistLinkList *[tablesize] {};
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
        int value = 3;
        for (int i = 0; i < s.length(); i++)
        {
            s[i] = tolower(s[i]);
            sum += s[i] * computePower(value, i);
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
            noOfArtist++;
            hashTableArr[key] = new ArtistLinkList(name);
        }
        else if (!(hashTableArr[key]->findInList(name)))
        {
            noOfArtist++;
            hashTableArr[key]->addArtistInList(name);
        }
    }

    void handler(string *arr, int noOfArtists)
    {
        for (int i = 0; i < noOfArtists; i++)
        {
            hashStore(arr[i]);
        }
    }
};

#endif // ARTISTHASHTABLEHEADER