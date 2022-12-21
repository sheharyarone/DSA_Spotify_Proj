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
    cout << "NO OF COLLISION WERE : " << noOfCollisions << endl;
    TrackHashTable *TrackContainer = new TrackHashTable();
    parseCSV("DataSet/ArtistNames.csv", ArtistContainer, TrackContainer);

    return 0;
}