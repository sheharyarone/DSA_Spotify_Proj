#pragma once
#include <iostream>
#include <string>
#include "Track.cpp"
#include "ArtistHashTable.cpp"
#include "TrackHashTable.h"

using namespace std;

TrackNode::TrackNode()
{
    TrackPointer = NULL;
    next = NULL;
}
TrackNode::TrackNode(string *array, ArtistHashTable *ArtistContainer, AVLTree<Genre> *GenreContainer)
{
    TrackPointer = new Track(array, ArtistContainer, GenreContainer); 
    this->next = NULL;
}
LinkedList::LinkedList()
{
    head = new TrackNode();
    collisions = 0;
}
LinkedList::LinkedList(string *array, ArtistHashTable *ArtistContainer, AVLTree<Genre> *GenreContainer)
{

    this->head = new TrackNode(array, ArtistContainer, GenreContainer);
    collisions = 0;
}

void LinkedList::addTrackInList(string *array, ArtistHashTable *ArtistContainer, AVLTree<Genre> *GenreContainer)
{
    collisions++;

    TrackNode *node = new TrackNode(array, ArtistContainer, GenreContainer);
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
bool LinkedList::findInList(string name)
{
    // IF FOUND RETURNS TRUE
    // FALSE OTHERWISE
    TrackNode *temp = head;
    while (temp != NULL)
    {
        if (name == temp->TrackPointer->Title)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void LinkedList::displayAll()
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
Track *LinkedList::getTrackPointer(string name)
{
    TrackNode *temp = head;
    while (temp != NULL)
    {
        if (name == temp->TrackPointer->Title)
        {
            return temp->TrackPointer;
        }
        temp = temp->next;
    }
    return nullptr;
}
void LinkedList::deleteNode(string name)
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

TrackHashTable::TrackHashTable(int size = 50011)
{
    tablesize = size;
    hashTableArr = new LinkedList *[tablesize]();
}

TrackHashTable::~TrackHashTable()
{
    for (int i = 0; i < tablesize; i++)
    {
        LinkedList *temp = hashTableArr[i];
        delete temp;
    }
    delete[] hashTableArr;
}

bool TrackHashTable::isAvailable(int ExistOn)
{
    // IF ARRAY CONTAINS POINTER = TRUE
    // IN THE ABOVE CASE THIS FUNCTION WILL RETURN FALSE BECAUSE SPACE IS NOT FREE

    // IF ARRAY DOESN'T CONTAINS POINTER = FALSE
    // IN THE ABOVE CASE THIS FUNCTION WILL RETURN TRUE BECAUSE SPACE IS FREE
    return (!(hashTableArr[ExistOn]));
}

int TrackHashTable::computePower(int value, int power)
{
    if (power != 0)
        return (value * computePower(value, power - 1));
    else
        return 1;
}

int TrackHashTable::hashFunction(string s)
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

void TrackHashTable::hashStore(string *arr, ArtistHashTable *ArtistContainer, AVLTree<Genre> *GenreContainer)
{
    int key = hashFunction(arr[1]);

    if (isAvailable(key))
    {
        hashTableArr[key] = new LinkedList(arr, ArtistContainer, GenreContainer);
    }
    else if (!(hashTableArr[key]->findInList(arr[1])))
    {
        hashTableArr[key]->addTrackInList(arr, ArtistContainer, GenreContainer);
    }
    else
    {
        Track *GenreAddReq = hashTableArr[key]->getTrackPointer(arr[1]);
        Genre *pointerOfGenre = GenreContainer->Search(arr[16]);
        // ADDING GENRE IN TRACK
        GenreAddReq->GenreOfTrack->ADD(pointerOfGenre);
        // ADDING TRACK IN GENRE OBJECT LINKED LIST
        pointerOfGenre->GenreTrackList->ADD(GenreAddReq);
    }
}

void TrackHashTable::handler(string *arr, int noOfTracks, ArtistHashTable *ArtistContainer, AVLTree<Genre> *GenreContainer)
{
    hashStore(arr, ArtistContainer, GenreContainer);
}
