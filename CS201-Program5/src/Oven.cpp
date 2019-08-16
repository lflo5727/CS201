//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#include "Oven.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Oven::Oven()
{
    ovenSize = 0;
    selfClean = false;
    convection = false;
}

string Oven::reportType(){
    return "Oven";
}
void Oven::readData(ifstream &infile){
    Appliance::readData(infile);
    char tempSC, tempC;
    infile >> ovenSize >> tempSC >> tempC;
    if(tempSC == 'S'){
        selfClean = true;
    }
    if(tempC == 'C'){
        convection = true;
    }
}

void Oven::writeData(){
    Appliance::writeData();
    char sclean = 'R';
    char con = 'R';
    if(selfClean)
        sclean = 'S';
    if(convection)
        con = 'C';
    cout << ovenSize << " " << sclean << " " << con << endl;

}
