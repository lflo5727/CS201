//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#ifndef DISHWASHER_H
#define DISHWASHER_H

#include "Appliance.h"
#include <string>
#include <fstream>
using namespace std;


class Dishwasher : public Appliance{
    private:
        int cycleTime;
        bool waterSaver;
        bool highTempDry;
    public:
        Dishwasher();
        string reportType();
        void readData(ifstream&);
        void writeData();
};

#endif // DISHWASHER_H
