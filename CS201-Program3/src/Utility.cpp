#include "Utility.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int GetUserInput(int minimum, int maximum){
    int userChoice;
    cin >> userChoice;
    while((userChoice > maximum) || (userChoice < minimum)){
        cout << "Please input an integer between " << minimum << " and " << maximum << ": ";
        cin >> userChoice;
    }
    return userChoice;
}

int getRandom(int minimum, int maximum){
    int randomNum = (rand() % maximum) + minimum;
    return randomNum;
}
