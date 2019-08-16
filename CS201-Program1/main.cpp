/*
    Liam Floyd
    CS201R - Program #1
    Rock, Paper, Scissors
    lcffz9@mail.umkc.edu

*/

#include <iostream>
using namespace std;

int winner(char playerOne, char playerTwo){
    //Winner function determines which player won the round
    if (playerOne == '1'){
        if (playerTwo == '1')
            cout << "It's a tie!\n";
        else if (playerTwo == '2')
            cout << "Player 2 wins!\n";
        else
            cout << "Player 1 wins!\n";
    }
    else if (playerOne == '2'){
        if (playerTwo == '1')
            cout << "Player 1 wins!\n";
        else if (playerTwo == '2')
            cout << "It's a tie!\n";
        else
            cout << "Player 2 wins!\n";
    }
    else{
        if (playerTwo == '1')
            cout << "Player 2 wins!\n";
        else if (playerTwo == '2')
            cout << "Player 1 wins!\n";
        else
            cout << "It's a tie!\n";
    }
    return 0;
}
char menu(int playerNum){
    //Handles user input for the main game
    char playerChoice;
    //Used char to handle errors with user inputting non-int values
    cout << "Player " << playerNum << "'s turn\n";
    bool choiceCheck = false;
    //choiceCheck is to verify that the user chose a valid answer
    while (choiceCheck == false){
        cout << "Enter your choice:\n1 : Rock\n2 : Paper\n3 : Scissors\n";
        cin >> playerChoice;
        switch(playerChoice){
        case '1':
            choiceCheck = true;
            cout << "You chose Rock\n\n";
            break;
        case '2':
            choiceCheck = true;
            cout << "You chose Paper\n\n";
            break;
        case '3':
            choiceCheck = true;
            cout<< "You chose Scissors\n\n";
            break;
        default:
            cout << "Choice invalid\n";
        }
    }
    return playerChoice;
}
bool rematch(){
    //Checks user input for errors and returns the player's choice on a rematch
    bool again;
    char userPlay;
    bool choiceCheck = false;
    while (choiceCheck == false){
        cout << "Would you like to play again? (y or n)\n";
        cin >> userPlay;
        switch(userPlay){
        case 'y':
            again = true;
            cout << "\nRematch\n________________\n";
            choiceCheck = true;
            break;
        case 'Y':
            again = true;
            cout << "\nRematch\n________________\n";
            choiceCheck = true;
            break;
        case 'n':
            again = false;
            cout << "Thanks for playing!";
            choiceCheck = true;
            break;
        case 'N':
            again = false;
            cout << "\nThanks for playing!\n";
            choiceCheck = true;
            break;
        default:
            cout << "Please enter a valid value\n";
        }
    }
    return again;
}

int main(){
    cout << "Welcome to Rock, Paper, Scissors\n";
    bool playAgain = true;
    char playerOneChoice;
    char playerTwoChoice;
    while (playAgain == true){
        //While loop to allow users to replay if they so choose
        playerOneChoice = menu(1);
        playerTwoChoice = menu(2);
        winner(playerOneChoice, playerTwoChoice);
        playAgain = rematch();
    }
    return 0;
}
