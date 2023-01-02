#include "../Parser/Parser.cpp"
#include "../HeaderFiles/Graph.cpp"

// new function. prints all artists songs
void printArtistDetails(string artist, ArtistHashTable *table)
{
    Artist *temp = table->ReturnArtistPointer(artist);
    Node<Track> *temp1 = temp->SongsList->head;
    cout << "Artist Name: " << artist << endl
         << "Songs list:" << endl
         << endl;
    while (temp1 != nullptr)
    {
        cout << temp1->object->Title << endl;
        temp1 = temp1->next;
    }
    cout << endl;
}

void ShowSoloTracks(string artist, ArtistHashTable *table1)
{
    // change into one func
    Artist *helperq = table1->ReturnArtistPointer(artist);
    LinkedList_<Track> * line2= helperq->SongsList;
    nodeCollab *edgeNode = helperq->CollabList->head;
    while (edgeNode != nullptr)
    {
        Node<Track> *use = edgeNode->object->collabTracks->head;
        while (use != nullptr)
        {
            Track *song = use->object;
            line2->DeleteNode(song);
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
    LinkedList_<Track> *trackz = new LinkedList_<Track>;
    Artist *main = table1->ReturnArtistPointer(artist1);
    nodeCollab *edge = main->CollabList->head;
    while (edge != nullptr)
    {
        Edge *edger = edge->object;
        if (edger->artist1->name == artist2 || edger->artist2->name == artist2)
        {
            cout << "Yes they are Coartists!" << endl;
            Node<Track> *trackx = edger->collabTracks->head;
            while (trackx != nullptr)
            {
                Track *realtrack = trackx->object;
                trackz->ADD(realtrack);
                trackx = trackx->next;
            }
            trackz->Displayall();
            break;
        }
        edge = edge->next;
    }
    if (trackz->head == nullptr)
    {
        cout << "No match!" << endl;
    }
}

void mostEnergeticSongOfGenre(string genre, AVLTree<Genre>* tree){
    Genre* found=tree->Search(genre);
    Node<Track>* tracklist=found->GenreTrackList->head->next;
    Node<Track>* mostEnergeticSongOfGenre=found->GenreTrackList->head;
    while(tracklist!=nullptr){
        if ((tracklist->object->Energy)>(mostEnergeticSongOfGenre->object->Energy)){
            mostEnergeticSongOfGenre=tracklist;
        }
        tracklist=tracklist->next;
    }
    Node<Artist>* artistlist=mostEnergeticSongOfGenre->object->ArtistsOfTrack->head;
    cout<<"Genre: "<<found->name<<endl
    <<"Most energetic song: "<<mostEnergeticSongOfGenre->object->Title<<endl
    <<"Artist(s): ";
    while(artistlist!=nullptr){
        cout<<artistlist->object->name<<"\t";
        artistlist=artistlist->next;
    }
    cout<<endl
    <<"Energy level: "<<mostEnergeticSongOfGenre->object->Energy<<endl;
}