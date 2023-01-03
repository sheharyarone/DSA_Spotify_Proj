#pragma once
#include <iostream>
#include <string>
#include "Artist.h"
#include "Track.cpp"
using namespace std;

Artist::Artist()
{
    this->name = "";
    SongsList = new LinkedList_<Track>;
    CollabList = new CollabLinkedList;
}
Artist::Artist(string name)
{
    this->name = name;
    SongsList = new LinkedList_<Track>;
    CollabList = new CollabLinkedList;
}
void Artist::trackHandler(Track *toAddInList)
{
    SongsList->ADD(toAddInList);
}
bool Artist::operator==(Artist test)
{
    return (this->name == test.name);
}
nodeCollab::nodeCollab(Edge *val)
{
    object = val;
    next = nullptr;
}
CollabLinkedList::CollabLinkedList()
{
    head = nullptr;
}
bool CollabLinkedList::isempty()
{
    return head == nullptr;
}
void CollabLinkedList::Displayall()
{
    nodeCollab *temp = head;
    while (temp != nullptr)
    {
        cout << temp->object << " ";
        temp = temp->next;
    }
    cout << endl;
}