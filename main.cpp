#ifndef MAIN
#define MAIN
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Parser/ArtistParser.h"
#include "Parser/Parser.h"
#include "HeaderFiles/ArtistHAshTable.h"

using namespace std;

int main()
{
    ArtistHashTable *ArtistContainer = new ArtistHashTable();
    parseArtistCSV("DataSet/ArtistNames.csv", ArtistContainer);
    cout << "NO OF COLLISION WERE : " << noOfCOLLISIONS << endl;
    TrackHashTable *TrackContainer = new TrackHashTable();
    parseCSV("DataSet/ArtistNames.csv", ArtistContainer, TrackContainer);
    cout << "HU GYA BHNCHOOD" << endl;

    return 0;
}
#endif