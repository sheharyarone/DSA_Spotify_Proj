#pragma once
#include <iostream>
#include <string>
#include "Artist.h"
#include "Track.cpp"
#include "Graph.cpp"
using namespace std;

Artist::Artist()
{
    this->name = "";
    SongsList = new LinkedList_<Track>;
    CollabList = new LinkedList_<Edge>;
}
Artist::Artist(string name)
{
    this->name = name;
    SongsList = new LinkedList_<Track>;
    CollabList = new LinkedList_<Edge>;
}
void Artist::trackHandler(Track *toAddInList)
{
    SongsList->ADD(toAddInList);
}
bool Artist::operator==(Artist test)
{
    return (this->name == test.name);
}
void Artist::addTrackToEdge(Artist *a1, Artist *a2, EdgeLinkedList *e1, Track *toAdd)
{
    PointerToEdge *temp = e1->head;
    while (temp->next != nullptr)
    {
        if ((temp->edgePointer->artist1 == a1 && temp->edgePointer->artist2 == a2) ||
            (temp->edgePointer->artist1 == a2 && temp->edgePointer->artist2 == a1))
        {
            temp->edgePointer->collabTracks->ADD(toAdd);
            break;
        }
        if (temp->next != nullptr)
            temp = temp->next;
    }
    temp->next = new PointerToEdge(a1, a2);
    temp->next->edgePointer->collabTracks->ADD(toAdd);
}

void Artist::createGraph(TrackHashTable *h1, EdgeLinkedList *e1)
{
    // this pointer will store head of linked list of tracks from hash table where it is found.
    TrackNode *trackNodeTemp;
    // loop iterating over track hash indexes.
    for (int i = 0; i < h1->tablesize; i++)
    {
        if (h1->isAvailable(i))
            continue;
        // if list is found assign head
        trackNodeTemp = h1->hashTableArr[i]->head; // LINKED LIST HEAD TRACK NODE

        while (trackNodeTemp != nullptr)
        { // now iterate through list and create edges

            if (trackNodeTemp->TrackPointer->ArtistsOfTrack->head->next == nullptr)
            {
                trackNodeTemp = trackNodeTemp->next;
                continue;
                // no edge needed. only solo artist.
            }

            else
            {
                // create local dynamic array to store artist pointers for edges.
                Node<Artist> *artistTemp1 = trackNodeTemp->TrackPointer->ArtistsOfTrack->head;
                Node<Artist> *artistTemp2;
                while (artistTemp1 != nullptr)
                {
                    artistTemp2 = artistTemp1->next;
                    while (artistTemp2 != nullptr)
                    {
                        addTrackToEdge(artistTemp1->object, artistTemp2->object, e1, trackNodeTemp->TrackPointer);
                    }
                    artistTemp1 = artistTemp1->next;
                }
            }
        }
    }
}