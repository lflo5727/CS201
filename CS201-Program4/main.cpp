/*
    Liam Floyd
    16175485

    CS201
    Assignment 4


*/
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

using namespace std;

int userCount(){
    //Opens the file and counts how many users so a dynamic array can be created with that size
    fstream userFile("users.txt");
    int userAmount = 0;
    User tempUser;
    while(userFile.good()){
        userFile >> tempUser;
        userAmount++;
    }
    userFile.close();
    return userAmount;
}
int main()
{
    int arraySize = userCount();
    int cnt = 0;
    fstream usersFile("users.txt");
    User* userArray;
    userArray = new User[arraySize];
    while(usersFile.good()){
        //Creates user objects and adds them to array of users
        usersFile >> userArray[cnt];
        cnt++;
    }
    usersFile.close();
    ifstream checkoutFile("checkouts.txt");
    int tempID;
    string checkedBook;
    while(checkoutFile.good()){
        //Go through checkout file and checkout all requested books
        checkoutFile >> tempID >> checkedBook;
        for(int p = 0; p < arraySize; p++){
            if(userArray[p].getIDNumber() == tempID){
                userArray[p].CheckOut(checkedBook);
            }
        }

    }
    checkoutFile.close();
    ifstream checkinFile("checkins.txt");
    while(checkinFile.good()){
        //Go through checkin file and check in all requested books
        checkinFile >> checkedBook;
        for(int q = 0; q < arraySize; q++){
            if(userArray[q].HasCheckedOut(checkedBook)){
                userArray[q].CheckIn(checkedBook);
            }
        }
    }
    checkinFile.close();


    ofstream outFile("updated_Users.txt");
    for(int m = 0; m < arraySize; m++){
        //Write all the users' updated members to the output file
        outFile << userArray[m];
    }
    outFile.close();
    return 0;
}
