/*
    Liam Floyd
    16175485

    CS201 - Program 3
    Battle Game

    10/6/2017

    NOTES:
    I made the starting HP 30 as I couldn't find anything about what the starting HP should be
    in the instructions.

    Also, I use char and a switch statement in place of GetUserInput in setupCharacters as it
    can handle if the user inputs a char by accident, whereas GetUserInput cannot because it
    can only handle integers as per the instructions

*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Utility.h"
using namespace std;

void setupCharacters(Player &player, Enemy &enemy){
    bool satisfied = false;
    string playerName;
    char playerChoice;
    while(!satisfied){
        cout << "Please enter your name: ";
        cin >> playerName;
        cout << "\nOption\tAttack\tDefense\n1\t5\t15\n2\t15\t5\n3\t10\t10\nChoose your stats (1,2,3):";
        bool choiceCheck = false;
        while(!choiceCheck){
            //Used char instead of int with GetUserInput() to handle improper input better
            cin >> playerChoice;
            switch(playerChoice){
                case '1':
                    player.setup(playerName, 30, 5, 15);
                    choiceCheck = true;
                    break;
                case '2':
                    player.setup(playerName, 30, 15, 5);
                    choiceCheck = true;
                    break;
                case '3':
                    player.setup(playerName, 30, 10, 10);
                    choiceCheck = true;
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        }
        player.DisplayStats();
        cout << "Is this good?(y or n)\n";
        choiceCheck = false;
        //Reset choiceCheck to reuse it
        while(!choiceCheck){
            cin >> playerChoice;
            switch(playerChoice){
                case 'y':
                    satisfied = true;
                    choiceCheck = true;
                    cout << "Then we are ready to go!\n\n";
                    break;
                case 'n':
                    satisfied = false;
                    choiceCheck = true;
                    cout << "Let's do it again, then!\n\n";
                    break;
                default:
                    cout << "Invalid Choice\n";
            }
        }
    }
    //Enemy Generation
    int enemyChoice = getRandom(1,3);
    if(enemyChoice == 1)
        enemy.setup("Enemy", 30, 5, 15);
    else if(enemyChoice == 2)
        enemy.setup("Enemy", 30, 15, 5);
    else if(enemyChoice == 3)
        enemy.setup("Enemy", 30, 10, 10);
}

int main(){
    srand(time(0));
    //Give the RNG a seed to base randoms off of
    Player playerChar;
    Enemy enemyChar;
    setupCharacters(playerChar, enemyChar);
    int cnt = 1;

    cout << "BEGIN!\n\n___________________\n";
    while((playerChar.getHP()>0) && (enemyChar.getHP()>0)){
        //This loop handles the game until one of the dueler's HP drops below zero
        cout << "ROUND: " << cnt << "\n\n";
        playerChar.DisplayStats();
        enemyChar.DisplayStats();
        //Show stats each round
        playerChar.selectAction();
        enemyChar.selectAction();
        //Select attack type
        enemyChar.getHit(playerChar.getAttack());
        playerChar.getHit(enemyChar.getAttack());
        //Each entity gets hit
        cout << "Player HP: " << playerChar.getHP() << "\tComputer HP: " << enemyChar.getHP() << endl;

        cout << "\n___________________\n\n";
        cnt++;
    }

    //End game
    if((playerChar.getHP() > 0) && (enemyChar.getHP() < 1)){
        cout << "\nYou Win!";
    }else if((playerChar.getHP() < 1) && (enemyChar.getHP() > 0)){
        cout << "\nYou Lose!";
    }else{
        cout << "\nTie!";
    }
    return 0;
}
