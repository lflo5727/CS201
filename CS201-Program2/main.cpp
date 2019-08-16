/*
    Liam Floyd
    CS201R
    Assignment #2
    lcffz0@mail.umkc.edu

*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Staff.h"

using namespace std;

char getMenuChoice(){
//Handles user input for the main game
    char userChoice;
    bool choiceCheck = false;
    //choiceCheck is to verify that the user chose a valid answer
    while (choiceCheck == false){
        cout << "Please make a selection:\n(1) Print staff roster\n(2) Print staff roster with evaluation grades\n(3) Print staff roster with increase %\n(4) Exit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        switch(userChoice){
        case '1':
            choiceCheck = true;
            break;
        case '2':
            choiceCheck = true;
            break;
        case '3':
            choiceCheck = true;
            break;
        case '4':
            choiceCheck = true;
            break;
        default:
            cout << "Choice invalid\n";
        }
    }
    return userChoice;
}

int main()
{
    ifstream info ("INFO.txt");
    ifstream grades ("Grades.txt");
    int sid;
    string first;
    string last;
    //Open the files


    vector <Staff> roster;
    //Using a vector to handle a file however long
    for(int i = 0; info.good(); i++){
        info >> sid >> first >> last;
        Staff staffEntry(sid, first, last);
        roster.push_back(staffEntry);
    }

    if (!Staff::readData(info)){
        //Call the readData function and if there is an error with the file, the below will be printed to the screen
        cout << "There is an error in INFO.txt, please correct it and try again.\n\n";
        return 0;
    }

    int staffSize = roster.size();
    for(int m = 0; grades.good(); m++){
        //Read through grades file to assign evaluation grades to teachers that have them
        int currentID;
        grades >> currentID;
        for(int n = 0; n < staffSize; n++){
            double f1, s1, f2, s2;
            if (currentID == roster[n].getStaffID()){
                grades >> s1 >> f1 >> s2 >> f2;
                roster[n].setGrades(f1, s1, f2, s2);
            }
        }
    }

    while (true){
        //While loop keeps going until the user selects 4
        char choice = getMenuChoice();
        if (choice == '1'){
            //print roster
            for(int p = 0; p < staffSize; p++){
                    cout << roster[p].getStaffID() << " " << roster[p].FullName() << endl;
            }
            cout << "\n\n";
        }
        //Choice one will print just the objects' StaffID and Name
        else if (choice == '2'){
            for(int p = 0; p < staffSize; p++){
                if (roster[p].getFallOne() != -1){
                    cout << roster[p].FullName() << ":      " << roster[p].getSpringOne() << " " <<roster[p].getFallOne() << " " << roster[p].getSpringTwo() << " " << roster[p].getFallTwo() << endl;
                }
            }
            cout << "\n\n";
        }
        //Choice two prints off names of objects with grades and their respective grades
        else if (choice == '3'){
            for(int p = 0; p < staffSize; p++){
                if (roster[p].getFallOne() != -1){
                    roster[p].FindIncreasedPercentage();
                    cout << roster[p].FullName() << ":      " << roster[p].getS1toF1() << "% increased over Fall 1 and " << roster[p].getS1toF2() << "% increased over Fall 2.\n";
                }
            }
            cout << "\n\n";
        }
        //Choice three calls FindIncreasedPercentage to get s1toF1 and s1toF2 and print them along with Staff names
        else{
            break;
            //Break out of while loop
        }
        //Choice four ends the program
    }
    info.close();
    grades.close();
    //Close the files
    return 0;
}
