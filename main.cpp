#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Parser/ArtistParser.h"
#include "HeaderFiles/ArtistHAshTable.h"
#include "AVLTree.h"
#include "ArtistHashTable.h"

using namespace std;

int main()
{
    /*ArtistHashTable *ArtistContainer = new ArtistHashTable();
    parseArtistCSV("DataSet/ArtistNames.csv", ArtistContainer);
    cout << "NO OF COLLISION WERE : " << noOfCOLLISIONS;
     */

    avl_tree<Artist> t1;
    Artist t2("Ali");
    Artist t3("Aon");
    Artist t4("Shehreyar");

    t1.insert(t1.root,t2);
    t1.insert(t1.root,t3);
    t1.insert(t1.root,t4);
    t1.inorderPrint(t1.root);
    return 0;
}