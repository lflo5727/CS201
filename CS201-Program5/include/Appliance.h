//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#ifndef APPLIANCE_H
#define APPLIANCE_H
#include <string>
#include <fstream>
using namespace std;

class Appliance{
    private:
        string modelNumber;
        string serialNumber;
    public:
        Appliance();
        //Setters
        void setModelNumber(string);
        void setSerialNumber(string);
        //Getters
        string getModelNumber();
        string getSerialNumber();
        //Virtual functions
        virtual string reportType();
        virtual void readData(ifstream&);
        virtual void writeData();


};

#endif // APPLIANCE_H
