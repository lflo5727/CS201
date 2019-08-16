#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

enum AttackType{
    OFFENSIVE = 1,
    DEFENSIVE = 2
};
class Character{
    protected:
        string name;
        int hp;
        int atk;
        int def;
        AttackType attackType;

    public:
        Character();
        void setup(string, int, int, int);
        void DisplayStats();
        virtual void selectAction();
        void getHit(int);
        int getAttack();
        int getHP();
};

#endif // CHARACTER_H
