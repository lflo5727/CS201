#ifndef STAFF_H
#define STAFF_H
#include <string>
#include <vector>
using namespace std;

class Staff{
    private:
        //Declare all needed members
        int staffID = -1;
        string firstName = "";
        string lastName = "";

        double fallOne = -1;
        double springOne = -1;
        double fallTwo = -1;
        double springTwo = -1;
        //Set initial values to determine who has and doesn't have grades

        double s1toF1;
        double s1toF2;
    public:
        Staff(int, string, string);
        string FullName();
        void FindIncreasedPercentage();
        static bool readData(ifstream&);

        //Declare setters
        void setStaffID(int);
        void setFirstName(string);
        void setLastName(string);

        void setGrades(double, double, double, double);

        //Declare getters
        int getStaffID();
        string getFirstName();
        string getLastName();

        double getFallOne();
        double getSpringOne();
        double getFallTwo();
        double getSpringTwo();

        double getS1toF1();
        double getS1toF2();



};

#endif // STAFF_H
