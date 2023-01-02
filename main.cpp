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
    Artist *temp = table->ReturnArtistPointer(artistname);
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

LinkedList_<Track> *InsertArtistSongs(string artist, ArtistHashTable *table1)
{

    int location = table1->hashFunction((artist));
    ArtistNode *helper = table1->hashTableArr[location]->headArtist;

    while (helper != nullptr && helper->ArtistPointer->name != artist)
    {
        helper = helper->next;
    }
    LinkedList_<Track> *line1 = new LinkedList_<Track>;
    Node<Track> *trackhelper = helper->ArtistPointer->SongsList->head;
    while (trackhelper != nullptr)
    {
        Track *Tracker = trackhelper->object;
        line1->ADD(Tracker);
        trackhelper = trackhelper->next;
    }
    return line1;
}
void deleteCollabSong(LinkedList_<Track> *line2, Track *toDelete)
{
    Node<Track> *current = line2->head;
    Node<Track> *prev = nullptr;

    // Search for the value in the linked list
    while (current != nullptr && current->object->Title != toDelete->Title)
    {
        prev = current;
        current = current->next;
    }

    // If the value was not found, return without deleting anything
    if (current == nullptr)
        return;

    // If the value is the first element in the list, update the head pointer
    if (prev == nullptr)
    {
        line2->head = current->next;
    }
    // Otherwise, update the next pointer of the previous element to skip over the current element
    else
    {
        prev->next = current->next;
    }

    // Free the memory for the current element
    delete current;
}

void ShowSoloSongs(string artist, ArtistHashTable *table1)
{
    LinkedList_<Track> *line2 = InsertArtistSongs(artist, table1);
    // change into one func
    Artist *helperq = table1->ReturnArtistPointer(artist);
    nodeCollab *edgeNode = helperq->CollabList->head;
    while (edgeNode != nullptr)
    {
        Node<Track> *use = edgeNode->object->collabTracks->head;
        while (use != nullptr)
        {
            Track *song = use->object;
            deleteCollabSong(line2, song);
            use = use->next;
        }
        edgeNode = edgeNode->next;
    }
    cout << "SOLO SONGS ARE " << artist << " : " << endl;
    line2->Displayall();
    cout << endl;
}

void ShowCollaboratesongs(string artist, ArtistHashTable *table1)
{
    int key = table1->hashFunction((artist));
    Artist *plzreply = table1->ReturnArtistPointer(artist);
    nodeCollab *Dmzz = plzreply->CollabList->head;
    LinkedList_<Track> *collabSongs = new LinkedList_<Track>;
    while (Dmzz != nullptr)
    {
        Node<Track> *Iluvu = Dmzz->object->collabTracks->head;
        while (Iluvu != nullptr)
        {
            collabSongs->ADD(Iluvu->object);
            Iluvu = Iluvu->next;
        }
        Dmzz = Dmzz->next;
    }
    cout << "COLLAB SONGS OF " << artist << " : " << endl;
    collabSongs->Displayall();
    cout << endl;
}

void artistsGenres(string artistName, ArtistHashTable *table)
{
    Artist *temp = table->ReturnArtistPointer(artistName);
    Node<Track> *temp1 = temp->SongsList->head;
    LinkedList_<Genre> *genretypes = new LinkedList_<Genre>;
    while (temp1 != nullptr)
    {
        Node<Genre> *temp2 = temp1->object->GenreOfTrack->head;
        while (temp2 != nullptr)
        {
            genretypes->ADD(temp2->object);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    cout << "GENRE ON WHICH " << artistName << " WORKED : " << endl;
    genretypes->Displayall();
    cout << endl;
}

void Coartist(string artist, ArtistHashTable *table1)
{
    LinkedList_<Artist> *ArtistStore = new LinkedList_<Artist>;
    Artist *main = table1->ReturnArtistPointer(artist);
    nodeCollab *edge = main->CollabList->head;
    while (edge != nullptr)
    {
        Edge *edger = edge->object;
        if (edger->artist1->name != artist)
        {
            ArtistStore->ADD(edger->artist1);
        }
        else
        {
            ArtistStore->ADD(edger->artist2);
        }
        edge = edge->next;
    }
    ArtistStore->Displayall();
}

void CheckIfCoartist(string artist1, string artist2, ArtistHashTable *table1)
{
    bool yes = false;
    LinkedList_<Track> *trackz = new LinkedList_<Track>;
    Artist *main = table1->ReturnArtistPointer(artist1);
    nodeCollab *edge = main->CollabList->head;
    while (edge != nullptr)
    {
        Edge *edger = edge->object;
        if (edger->artist1->name == artist2 || edger->artist2->name == artist2)
        {
            cout << "Yes they are Coartists!" << endl;
            yes = true;
            Node<Track> *trackx = edger->collabTracks->head;
            while (trackx != nullptr)
            {
                Track *realtrack = trackx->object;
                trackz->ADD(realtrack);
                trackx = trackx->next;
            }
        }
        edge = edge->next;
    }
    if (!yes)
    {
        cout << "No match!" << endl;
    }
    trackz->Displayall();
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
    // ShowSoloSongs("ZAYN", ArtistContainer);
    // printArtistDetails(ArtistContainer);
    // ShowCollaboratesongs("ZAYN", ArtistContainer);
    // artistsGenres("ZAYN", ArtistContainer);
    // Coartist("ZAYN", ArtistContainer);
    CheckIfCoartist("ZAYN", "Sia", ArtistContainer);
    return 0;
}
