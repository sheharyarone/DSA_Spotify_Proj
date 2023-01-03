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

    // cout << "NO OF Unique Artists WERE : " << noOfArtist << endl;
    // cout << "No of Collisions in Artist were : " << noOfCollisionsInArtist << endl;

    // cout << "NO OF UNIQUE SONGS : " << noOfUniqueSongs << endl;
    // cout << "NO oF Collisions in TRACKS were : " << noOfCollisionsInTracks << endl;
    EdgeLinkedList *EdgesContainer = new EdgeLinkedList();

    EdgesContainer->createGraph(TrackContainer);
    EdgesContainer->printNoOfEdges();
    cout<<"Function 1"<<endl;
    printArtistDetails("ZAYN", ArtistContainer);
    cout<<"Function 2"<<endl;
    ShowSoloTracks("ZAYN", ArtistContainer);
    cout<<"Function 3"<<endl;
    ShowCollaboratesongs("ZAYN", ArtistContainer);
    cout<<"Function 4"<<endl;
    artistsGenres("ZAYN", ArtistContainer);
    cout<<"Function 5"<<endl;
    Coartist("ZAYN", ArtistContainer);
    cout<<"Function 6"<<endl;
    CheckIfCoartist("ZAYN", "Sia", ArtistContainer);
    cout<<"Function 7"<<endl;
    mostEnergeticSongOfGenre("sleep",GenreContainer);
    cout<<"Function 8"<<endl;
    averageTrackLengthforGenre("acoustic",GenreContainer);

    return 0;
}
