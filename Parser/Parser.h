#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void parseCSV(const string filename)
{
    ifstream file(filename);
    string line;
    // FOR SINGLE ROW
    while (getline(file, line))
    {
        istringstream iss(line);
        string fields[18];
        string field;
        int i = 0;
        int j = 0;
        // FOR SINGLE COLUMN
        while (getline(iss, field, ','))
        {
            if (j == 0 || j == 1)
            {
                j++;
                continue;
            }
            fields[i] = field;
            i++;
            j++;
        }
    }
}