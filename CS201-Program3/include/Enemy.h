#ifndef ENEMY_H
#define ENEMY_H
#include <Character.h>
#include <string>
using namespace std;


class Enemy : public Character
{
    public:
        Enemy();
        void selectAction();
};

#endif // ENEMY_H
