//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#ifndef OVEN_H
#define OVEN_H
#include <string>
#include <fstream>
#include "Appliance.h"
using namespace std;

class Oven : public Appliance{
    private:
        float ovenSize;
        bool selfClean;
        bool convection;
    public:
        Oven();
        string reportType();
        void readData(ifstream&);
        void writeData();

};

#endif // OVEN_H
