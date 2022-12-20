#include <iostream>
#include "HeaderFiles/TrackHAshTable.h"
#include <fstream>
#include <sstream>
#include <string>
#include "HeaderFiles/TrackHashTable.h"
using namespace std;

int main()
{

    TrackHashTable t1;
    cout<<t1.hashFunction("In The nAme of love");


    /*Track **trackarray = new Track *[20] {};
    trackarray[2] = new Track();
    if (trackarray[2])
    {
        cout << "AGR OBJECT HO TO TRUE HUGA" << endl;
    }
    if (!trackarray[10])
    {
        cout << "AGR OBJECT Ni HUGA TO FALSE HUGA" << endl;
    }
    return 0; */
}