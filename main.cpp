#include <iostream>
#include <string>
#include "Functions/Procedures.cpp"
using namespace std;

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
    // int key = ArtistContainer->hashFunction("ZAYN");
    // nodeCollab *linkedListEdgeTraver = ArtistContainer->hashTableArr[key]->headArtist->ArtistPointer->CollabList->head;
    // while (linkedListEdgeTraver != nullptr)
    // {
    //     Edge *edge = linkedListEdgeTraver->object;
    //     Node<Track> *collabTrackNodeInEdge = edge->collabTracks->head;
    //     while (collabTrackNodeInEdge != nullptr)
    //     {
    //         cout << collabTrackNodeInEdge->object->Title << endl;
    //         collabTrackNodeInEdge = collabTrackNodeInEdge->next;
    //     }
    //     linkedListEdgeTraver = linkedListEdgeTraver->next;
    // }
    ShowSoloTracks("ZAYN", ArtistContainer);
    // printArtistDetails(ArtistContainer);
    //ShowCollaboratesongs("ZAYN", ArtistContainer);
    // artistsGenres("ZAYN", ArtistContainer);
    // Coartist("ZAYN", ArtistContainer);
    //CheckIfCoartist("ZAYN", "Sia", ArtistContainer);
    //mostEnergeticSongOfGenre("sleep",GenreContainer);
    return 0;
}
