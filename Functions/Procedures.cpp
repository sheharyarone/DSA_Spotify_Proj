#pragma once
#include "../Parser/Parser.cpp"
#include "../HeaderFiles/Graph.cpp"

// THIS FUNCTION WILL PRINT OUT ALL THE ARTIST DETAILS WE HAVE IN IT'S OBJECT
void printArtistDetails(string artist, ArtistHashTable *ArtistContainer)
{
    Artist *temp = ArtistContainer->ReturnArtistPointer(artist);
    cout << "Artist Name: " << artist << endl
         << "Songs list:" << endl
         << endl;
    temp->SongsList->Displayall();
}

// THIS FUNCTION WILL PRINT OUT ALL THE SOLO TRACKS AN ARTSIT HAS WOKRED ON
void ShowSoloTracks(string artist, ArtistHashTable *ArtistContainer)
{
    Artist *reqArtistPointer = ArtistContainer->ReturnArtistPointer(artist);
    LinkedList_<Track> *listOfTracks = reqArtistPointer->SongsList;
    nodeCollab *edgeNode = reqArtistPointer->CollabList->head;
    while (edgeNode != nullptr)
    {
        Node<Track> *use = edgeNode->object->collabTracks->head;
        while (use != nullptr)
        {
            Track *song = use->object;
            listOfTracks->DeleteNode(song);
            use = use->next;
        }
        edgeNode = edgeNode->next;
    }
    cout << "SOLO SONGS OF " << artist << " : " << endl;
    listOfTracks->Displayall();
    cout << endl;
}
// THIS FUNCTION WILL PRINT OUT ALL THE COLLABORATIVE SONGS AN ARTIST HAS WORKED ON
void ShowCollaboratesongs(string artist, ArtistHashTable *ArtistContainer)
{
    int key = ArtistContainer->hashFunction((artist));
    Artist *reqArtistPointer = ArtistContainer->ReturnArtistPointer(artist);
    nodeCollab *EdgeNodeOfCollab = reqArtistPointer->CollabList->head;
    LinkedList_<Track> *collabSongs = new LinkedList_<Track>;
    while (EdgeNodeOfCollab != nullptr)
    {
        Node<Track> *trackNode = EdgeNodeOfCollab->object->collabTracks->head;
        while (trackNode != nullptr)
        {
            collabSongs->ADD(trackNode->object);
            trackNode = trackNode->next;
        }
        EdgeNodeOfCollab = EdgeNodeOfCollab->next;
    }
    cout << "COLLAB SONGS OF " << artist << " : " << endl;
    collabSongs->Displayall();
    cout << endl;
}
// THIS WILL PRINT OUT ALL THE GENRE'S AN ARTIST HAS WORKED ON
void artistsGenres(string artistName, ArtistHashTable *ArtistContainer)
{
    Artist *reqArtistPointer = ArtistContainer->ReturnArtistPointer(artistName);
    Node<Track> *genreTrackNode = reqArtistPointer->SongsList->head;
    LinkedList_<Genre> *genretypes = new LinkedList_<Genre>;
    while (genreTrackNode != nullptr)
    {
        Node<Genre> *temp = genreTrackNode->object->GenreOfTrack->head;
        while (temp != nullptr)
        {
            genretypes->ADD(temp->object);
            temp = temp->next;
        }
        genreTrackNode = genreTrackNode->next;
    }
    cout << "GENRE ON WHICH " << artistName << " WORKED : " << endl;
    genretypes->Displayall();
    cout << endl;
}
// THIS FUNCTION WILL PRINT OUT ALL THE ARTIST
// WITH WHOM AN ARTIST HAS WORKED ON
void Coartist(string artist, ArtistHashTable *ArtistContainer)
{
    LinkedList_<Artist> *ArtistStore = new LinkedList_<Artist>;
    Artist *reqArtistPointer = ArtistContainer->ReturnArtistPointer(artist);
    nodeCollab *edge = reqArtistPointer->CollabList->head;
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
// THIS FUNCTION WILL PRINT OUT WHETHER ARTIST HAS WORKED TOGETHER OR NOT
// IF YES THEN IT WILL PRINT OUT THE TRACKS THEY COLLABORATED NO
// IF NO THEN THERE WILL BE ONE STATEMENT ONLY "NO COLLABORATION !"
void CheckIfCoartist(string artist1, string artist2, ArtistHashTable *ArtistContainer)
{
    LinkedList_<Track> *tracksLinkList = new LinkedList_<Track>;
    Artist *reqArtistPointerFor1 = ArtistContainer->ReturnArtistPointer(artist1);
    nodeCollab *edge = reqArtistPointerFor1->CollabList->head;
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
                tracksLinkList->ADD(realtrack);
                trackx = trackx->next;
            }
            tracksLinkList->Displayall();
            break;
        }
        edge = edge->next;
    }
    if (tracksLinkList->head == nullptr)
    {
        cout << "NO COLLABORATION !" << endl;
    }
}
// THIS WILL PRINT OUT THE TRACK HAVING HIGHEST VALUE IN ONE GENRE
// WHICH IS BEING PASSED INTO THIS FUNCTION
void mostEnergeticSongOfGenre(string genre, AVLTree<Genre> *GenreContainer)
{
    Genre *reqGenre = GenreContainer->Search(genre);
    Node<Track> *trackList = reqGenre->GenreTrackList->head->next;
    Node<Track> *mostEnergeticSongOfGenre = reqGenre->GenreTrackList->head;
    while (trackList != nullptr)
    {
        if ((trackList->object->Energy) > (mostEnergeticSongOfGenre->object->Energy))
        {
            mostEnergeticSongOfGenre = trackList;
        }
        trackList = trackList->next;
    }
    Node<Artist> *artistlist = mostEnergeticSongOfGenre->object->ArtistsOfTrack->head;
    cout << "Genre: " << reqGenre->name << endl
         << "Most energetic song: " << mostEnergeticSongOfGenre->object->Title << endl
         << "Artist(s): ";
    while (artistlist != nullptr)
    {
        cout << artistlist->object->name << "\t";
        artistlist = artistlist->next;
    }
    cout << endl
         << "Energy level: " << mostEnergeticSongOfGenre->object->Energy << endl;
}


//THIS FUNCTION WILL PRINT OUT THE AVERAGE LENGTH OF SONGS OF A GENRE
//WHICH IS PASSED INTO THIS FUNCION
void averageTrackLengthforGenre(string genre,AVLTree<Genre>* tree){
    Node<Track>* tracklist=tree->Search(genre)->GenreTrackList->head;
    int count=0;
    int totallength=0;
    while (tracklist!=nullptr){
        count++;
        totallength+=tracklist->object->Duration;
        tracklist=tracklist->next;
    }
    int avglength=(totallength/count);
    cout<<"Average duration of "<<genre<<" tracks is "<<avglength<<"."<<endl;
}
