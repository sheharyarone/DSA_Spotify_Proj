#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Parser/ArtistParser.h"
#include "HeaderFiles/ArtistHAshTable.h"

using namespace std;

int main()
{
    ArtistHashTable *ArtistContainer = new ArtistHashTable();
    parseArtistCSV("DataSet/ArtistNames.csv", ArtistContainer);
    cout << "NO OF COLLISION WERE : " << noOfCOLLISIONS;
    return 0;
}