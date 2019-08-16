//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H
#include <string>
#include <fstream>
#include "Appliance.h"
using namespace std;


class Refrigerator : public Appliance{
    private:
        float capacity;
        bool frostFree;
    public:
        Refrigerator();
        string reportType();
        void readData(ifstream&);
        void writeData();
};

#endif // REFRIGERATOR_H
