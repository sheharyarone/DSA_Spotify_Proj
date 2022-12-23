#include <iostream>
#include <string>
#include "Parser/Parser.cpp"
#include "Parser/ArtistParser.cpp"
using namespace std;
int main()
{

    ArtistHashTable *ArtistContainer = new ArtistHashTable(53131);
    parseArtistCSV("DataSet/ArtistNames.csv", ArtistContainer);
    cout << "NO OF Unique Artists WERE : " << noOfArtist << endl;
    cout << "No of Collisions in Artist were : " << noOfCollisionsInArtist << endl;

    TrackHashTable *TrackContainer = new TrackHashTable(82109);
    parseCSV("DataSet/dataset.csv", ArtistContainer, TrackContainer);
    cout << "NO OF UNIQUE SONGS : " << noOfUniqueSongs << endl;
    cout << "NO oF Collisions in TRACKS were : " << noOfCollisionsInTracks << endl;

    // int key = TrackContainer->hashFunction("93 Million Miles");
    // cout << TrackContainer->hashTableArr[key]->head->TrackPointer->ArtistsOfTrack->head->object->SongsList->head->next->object->Title << endl;

    // int key = TrackContainer->hashFunction("Comedy");
    // TrackContainer->hashTableArr[key]->head->TrackPointer->Artists->displayAll();
    // std::ofstream outfile;      // Create ofstream object
    // outfile.open("output.txt"); // Open file

    // // Redirect cout to the ofstream object
    // std::cout.rdbuf(outfile.rdbuf());

    // // Output to the file using cout

    // for (int i = 0; i < TrackContainer->tablesize; i++)
    // {
    //     if ((TrackContainer->hashTableArr[i]))
    //     {
    //         TrackContainer->hashTableArr[i]->displayAll();
    //     }
    // }
    // outfile.close(); // Close the file

    return 0;
}