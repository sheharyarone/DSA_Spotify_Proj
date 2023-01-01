#include <iostream>
#include <string>
#include "Parser/Parser.cpp"
#include "HeaderFiles/Graph.cpp"
using namespace std;

// new function. prints all artists songs
void printArtistDetails(ArtistHashTable *table)
{
    string artistname;
    cout << "Enter artist name: ";
    getline(cin, artistname);
    cout << endl;
    Artist *temp = table->ReturnArtistNode(artistname);
    Node<Track> *temp1 = temp->SongsList->head;
    cout << "Artist Name: " << artistname << endl
         << "Songs list:" << endl
         << endl;
    while (temp1 != nullptr)
    {
        cout << temp1->object->Title << endl;
        temp1 = temp1->next;
    }
    cout << endl;
}

int main()
{
    ArtistHashTable *ArtistContainer = new ArtistHashTable(53131);
    parseArtistCSV("DataSet/ArtistNames.csv", ArtistContainer);

    cout << "ARTIST CONTAINER SET" << endl;
    AVLTree<Genre> *GenreContainer = new AVLTree<Genre>;
    parseGenreCSV("DataSet/Genre.csv", GenreContainer);
    cout << "GENRE CONTAINER SET" << endl;
    Genre *pointer = GenreContainer->Search("afrobeat");

    TrackHashTable *TrackContainer = new TrackHashTable(82109);
    parseCSV("DataSet/dataset.csv", ArtistContainer, TrackContainer, GenreContainer);
    cout << "TRACKS HASHTABLE SET" << endl;

    EdgeLinkedList *EdgesContainer = new EdgeLinkedList();

    EdgesContainer->createGraph(TrackContainer);
    EdgesContainer->printEdges();
    int key = ArtistContainer->hashFunction("ZAYN");
    nodeCollab *linkedListEdgeTraver = ArtistContainer->hashTableArr[key]->headArtist->ArtistPointer->CollabList->head;
    while (linkedListEdgeTraver != nullptr)
    {
        Edge *edge = linkedListEdgeTraver->object;
        Node<Track> *collabTrackNodeInEdge = edge->collabTracks->head;
        while (collabTrackNodeInEdge != nullptr)
        {
            cout << collabTrackNodeInEdge->object->Title << endl;
            collabTrackNodeInEdge = collabTrackNodeInEdge->next;
        }
        linkedListEdgeTraver = linkedListEdgeTraver->next;
    }

    return 0;
}
