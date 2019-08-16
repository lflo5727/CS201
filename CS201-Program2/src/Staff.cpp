#include "Staff.h"
#include <string>
#include <fstream>
using namespace std;

Staff::Staff(int a, string b, string c){
    //Constructor for class
    staffID = a;
    firstName = b;
    lastName = c;
}

string Staff::FullName(){
    //Return the full name of the object
    return lastName + ", " + firstName;
}

void Staff::FindIncreasedPercentage(){
    //Calculate the increased percentage and assign it to members
    s1toF1 = (((fallOne-springOne)/5)*100);
    s1toF2 = (((fallTwo-springOne)/5)*100);
}
bool Staff::readData(ifstream &infile){
    //Return false if data was not read into the file
    int sid = -1;
    string first = "";
    string last = "";
    for(int i = 0; infile.good(); i++){
        infile >> sid >> first >> last;
        if((sid == -1) || (first == "") || (last == "")){
            return false;
        }
    }

    return true;
    //Return true if there are no issues reading file
}

//Getters for StaffID as well as first and last name
int Staff::getStaffID(){
    return staffID;
}
string Staff::getFirstName(){
    return firstName;
}
string Staff::getLastName(){
    return lastName;
}

//Setters for StaffID as well as first and last name
void Staff::setStaffID(int sid){
    staffID = sid;
}
void Staff::setFirstName(string first){
    firstName = first;
}
void Staff::setLastName(string last){
    lastName = last;
}

//Set all four grades
void Staff::setGrades(double f1, double s1, double f2, double s2){
    fallOne = f1;
    springOne = s1;
    fallTwo = f2;
    springTwo = s2;
}
double Staff::getFallOne(){
    return fallOne;
}
double Staff::getSpringOne(){
    return springOne;
}
double Staff::getFallTwo(){
    return fallTwo;
}
double Staff::getSpringTwo(){
    return springTwo;
}

double Staff::getS1toF1(){
    return s1toF1;
}
double Staff::getS1toF2(){
    return s1toF2;
}

