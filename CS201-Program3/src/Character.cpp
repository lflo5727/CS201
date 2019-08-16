#include "Character.h"
#include "Utility.h"
#include <string>
#include <iostream>
using namespace std;

Character::Character(){
    //Default Constructor
    name = "";
    hp = 0;
    atk = 0;
    def = 0;
}
void Character::setup(string a, int b, int c, int d){
    //Setup the values for each class
    name = a;
    hp = b;
    atk = c;
    def = d;
}

void Character::DisplayStats(){
    cout << "Name: " << name << ", HP: " << hp << ", ATK: " << atk << ", DEF: " << def << endl;
}
void Character::selectAction(){
    //Empty for Character
}

void Character::getHit(int attack){
    //Handles the damage taken to object's HP for each hit
    int dmg = attack;
    dmg -= def;
    if(attackType == DEFENSIVE){
        dmg -= getRandom(1,3);
    }

    if(dmg < 0){
        dmg = 0;
    }
    hp -= dmg;
}

int Character::getAttack(){
    //Gets the damage the object does
    int dmg = atk;
    if(attackType == OFFENSIVE){
        dmg += getRandom(1,3);
    }
    cout << name << " does " << dmg << " points of damage!\n";
    return dmg;
}

int Character::getHP(){
    return hp;
}

