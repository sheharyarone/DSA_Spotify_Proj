#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void parseArtistCSV(const string filename)
{
    ifstream file(filename);
    string line;
    // FOR SINGLE ROW
    while (getline(file, line))
    {
        istringstream iss(line);
        string field;
        int i = 1;
        int j = 1;
        // FOR SINGLE COLUMN
        while (getline(iss, field, ','))
        {
            cout << field << endl;
        }
        // if (!isExists)
    }
}