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
    cout << "PRINTING ZAYN ARTIST DETAILS :" << endl;
    printArtistDetails("ZAYN", ArtistContainer);
    cout << "PRINTING SOLO TRACKS OF ZAYN :" << endl;
    ShowSoloTracks("ZAYN", ArtistContainer);
    cout << "PRINTING COLLABORATIVE SONGS OF ZAYN :" << endl;
    ShowCollaboratesongs("ZAYN", ArtistContainer);
    cout << "PRINTING GENRE'S ON WHICH ZAYN WORKED :" << endl;
    artistsGenres("ZAYN", ArtistContainer);
    cout << "COARTISTS OF ZAYN : " << endl;
    Coartist("ZAYN", ArtistContainer);
    cout << "ARE ZAYN AND SIA COARTIST" << endl;
    CheckIfCoartist("ZAYN", "Sia", ArtistContainer);
    cout << "ARE ZAYN AND ANDREW FOY COARTIST" << endl;
    CheckIfCoartist("ZAYN", "Andrew Foy", ArtistContainer);
    cout << "MOST ENERGETIC SONGS OF SLEEP :" << endl;
    mostEnergeticSongOfGenre("sleep", GenreContainer);
    cout << "AVERAGE TRACK LENGTH OF ACOUSTIC GENRE : " << endl;
    averageTrackLengthforGenre("acoustic", GenreContainer);

    return 0;
}
