#include "Player.h"
#include "Character.h"
#include "Utility.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(){
    //Default Constructor
    name = "";
    hp = 0;
    atk = 0;
    def = 0;
}
void Player::selectAction(){
    cout << "Select 1 for Offensive attack or 2 for Defensive\n";
    int playerChoice = GetUserInput(1,2);
    if(playerChoice == 1)
        attackType = OFFENSIVE;
    else if(playerChoice == 2)
        attackType = DEFENSIVE;
}
