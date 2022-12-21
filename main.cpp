#include <iostream>
#include <string>
#include "Parser/Parser.h"
#include "Parser/ArtistParser.h"
#include "HeaderFiles/TrackHashTable.h"
#include "HeaderFiles/ArtistHashTable.h"

using namespace std;

int main()
{
    ArtistHashTable *ArtistContainer = new ArtistHashTable();
    parseArtistCSV("DataSet/ArtistNames.csv", ArtistContainer);
    cout << "NO OF Unique Artists WERE : " << noOfArtist << endl;
    cout << "No of Collisions in Artist were : " << noOfCollisionsInArtist << endl;

    TrackHashTable *TrackContainer = new TrackHashTable();
    parseCSV("DataSet/dataset.csv", ArtistContainer, TrackContainer);
    cout << "NO OF UNIQUE SONGS : " << noOfUniqueSongs << endl;

    // std::ofstream outfile;      // Create ofstream object
    // outfile.open("output.txt"); // Open file

    // // Redirect cout to the ofstream object
    // std::cout.rdbuf(outfile.rdbuf());

    // // Output to the file using cout
    // std::cout << "Hello, world!" << std::endl;

    // for (int i = 0; i < ArtistContainer->tablesize; i++)
    // {
    //     if ((ArtistContainer->hashTableArr[i]))
    //     {
    //         ArtistContainer->hashTableArr[i]->displayAll();
    //     }
    // }
    // outfile.close(); // Close the file

    return 0;
}