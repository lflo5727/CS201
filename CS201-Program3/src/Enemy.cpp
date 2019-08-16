#include "Enemy.h"
#include "Character.h"
#include "Utility.h"
#include <iostream>
#include <string>
using namespace std;

Enemy::Enemy(){
    //Default Constructor
    name = "";
    hp = 0;
    atk = 0;
    def = 0;
}

void Enemy::selectAction(){
    //Randomly select attack type for Enemy object
    int enemyAttack = getRandom(1, 2);
    if(enemyAttack == 1)
        attackType = OFFENSIVE;
    else if(enemyAttack == 2)
        attackType = DEFENSIVE;

}
