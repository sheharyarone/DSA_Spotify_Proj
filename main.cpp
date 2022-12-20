#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Parser/ArtistParser.h";
using namespace std;

int main()
{
    parseArtistCSV("DataSet/ArtistNames.csv");
    return 0;
}