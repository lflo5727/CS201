#ifndef PLAYER_H
#define PLAYER_H
#include <Character.h>
#include <string>
using namespace std;


class Player : public Character{
    public:
        Player();
        void selectAction();
};

#endif // PLAYER_H
