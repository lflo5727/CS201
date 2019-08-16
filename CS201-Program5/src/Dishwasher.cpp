//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#include "Dishwasher.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Dishwasher::Dishwasher()
{
    cycleTime = 0;
    waterSaver = false;
    highTempDry = false;
}

string Dishwasher::reportType(){
    return "Dishwasher";
}

void Dishwasher::readData(ifstream &infile){
    Appliance::readData(infile);
    char tempWS, tempHT;
    infile >> cycleTime >> tempWS >> tempHT;
    if(tempWS == 'T')
        waterSaver = true;

    if(tempHT == 'T')
        highTempDry = true;
}

void Dishwasher::writeData(){
    Appliance::writeData();
    char ws = 'F';
    char ht = 'F';
    if(waterSaver)
        ws = 'T';
    if(highTempDry)
        ht = 'T';
    cout << cycleTime << " " << ws << " " << ht << endl;
}
