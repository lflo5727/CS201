//////////////////////////
//      Liam Floyd
//      11/19/17
//  CS201 Assignment 6
//////////////////////////
#include <iostream>
using namespace std;

void tokenMath(int tokenNum, int goalToken, int turnNum){
    //Base case if turns hit zero
    if((turnNum == 0) && (tokenNum != goalToken)){
        cout << "Sorry, solution wasn't found within alloted turns.\n\n";
        return;
    }
    //If tokens reach the goal
    if(tokenNum == goalToken){
        cout << "Solution found with " << turnNum << " turn(s) remaining\n\n";
        return;
    }

    //Checks if number is even or not and chooses it's move accordingly
    if(tokenNum % 2 == 1){
        int tokenLarger = tokenNum + 25;
        cout << "Adding 25, you get " << tokenLarger << " tokens.\n";
        tokenMath(tokenLarger, goalToken, turnNum - 1);
    }else if(tokenNum % 2 == 0){
        int tokenHalf = tokenNum / 2;
        cout << "Reducing by half, you get " << tokenHalf << " tokens.\n";
        tokenMath(tokenHalf, goalToken, turnNum - 1);
    }


}
bool playAgain(){
    //Function to determine if the player would like to play again
    cout << "Would you like to play again? (y/n)\n";
    while(true){
        //Loop that keeps going if choice is invalid and breaks once choice is valid
        char yesorno;
        cin >> yesorno;
        switch(yesorno){
            case 'Y':
                return true;
            case 'y':
                return true;
            case 'n':
                cout << "Thanks for playing!\n";
                return false;
            case 'N':
                cout << "Thanks for playing!\n";
                return false;
            default:
                cout << "Invalid Choice. Please input a y or n.\n";
        }
    }

}

int main(){
    int tokens = 13;
    bool wanttoplay = true;
    //Setup a bool condition for the main loop and declare tokens

    while(wanttoplay){
        int tokenGoal;
        int turns;
        cout << "Enter the number of tokens you want to reach: ";
        cin >> tokenGoal;
        cout << "What is the number of turns? ";
        cin >> turns;

        cout << "Searching for solution in " << turns << " turn(s).\n\n";
        tokenMath(tokens, tokenGoal, turns);
        //Calls function
        wanttoplay = playAgain();
        //Checks to break loop

    }

    return 0;
}
