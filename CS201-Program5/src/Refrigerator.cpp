//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#include "Refrigerator.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Refrigerator::Refrigerator()
{
    capacity = 0;
    frostFree = false;
}

string Refrigerator::reportType(){
    return "Refrigerator";
}

void Refrigerator::readData(ifstream &infile){
    Appliance::readData(infile);
    char temp;
    infile >> capacity >> temp;
    if(temp == 'T')
        frostFree = true;
}

void Refrigerator::writeData(){
    Appliance::writeData();
    char frostF = 'F';
    if(frostFree)
        frostF = 'T';
    cout << capacity << " " << frostF << endl;

}
