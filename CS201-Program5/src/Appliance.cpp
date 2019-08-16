//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#include "Appliance.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Appliance::Appliance(){
    modelNumber = "";
    serialNumber = "";
}

//Setters
void Appliance::setModelNumber(string a){
    modelNumber = a;
}
void Appliance::setSerialNumber(string b){
    serialNumber = b;
}

//Getters
string Appliance::getModelNumber(){
    return modelNumber;
}
string Appliance::getSerialNumber(){
    return serialNumber;
}

//Virtual functions
string Appliance::reportType(){
    return "";
}
void Appliance::readData(ifstream &fin){
    fin >> modelNumber >> serialNumber;
}
void Appliance::writeData(){
    cout << modelNumber << " " << serialNumber << " ";
}
