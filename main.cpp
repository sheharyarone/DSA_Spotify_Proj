#include <iostream>
#include <string>
#include "Parser/Parser.cpp"
#include "HeaderFiles/Graph.cpp"
using namespace std;

int main()
{

    ArtistHashTable *ArtistContainer = new ArtistHashTable(53131);
    parseArtistCSV("DataSet/ArtistNames.csv", ArtistContainer);
    //    cout << "NO OF Unique Artists WERE : " << noOfArtist << endl;
    //    cout << "No of Collisions in Artist were : " << noOfCollisionsInArtist << endl;
    cout << "ARTIST CONTAINER SET" << endl;
    AVLTree<Genre> *GenreContainer = new AVLTree<Genre>;
    parseGenreCSV("DataSet/Genre.csv", GenreContainer);
    cout << "GENRE CONTAINER SET" << endl;
    Genre *pointer = GenreContainer->Search("afrobeat");

    TrackHashTable *TrackContainer = new TrackHashTable(82109);
    parseCSV("DataSet/dataset.csv", ArtistContainer, TrackContainer, GenreContainer);
    cout << "TRACKS HASHTABLE SET" << endl;

    EdgeLinkedList* EdgesContainer= new EdgeLinkedList();
    EdgesContainer->createGraph(TrackContainer,EdgesContainer);

    EdgesContainer->printEdges();

    

    return 0;
}