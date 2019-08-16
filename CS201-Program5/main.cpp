//////////////////////////////
//          Liam Floyd
//      CS201 Assignment #5
//          11/5/17
//////////////////////////////
#include <iostream>
#include "Appliance.h"
#include "Refrigerator.h"
#include "Dishwasher.h"
#include "Oven.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void writeStuff(Appliance* items[], int Count, const string& targetType){
    //Call writeData function for only the objects of requested type
    cout << targetType << ":\n";
    for(int p = 0; p < Count; p++){
        if(items[p]->reportType() == targetType){
            items[p]->writeData();
        }
    }
    cout << endl;
}

int main()
{
    Appliance* inStock[100];
    ifstream filein("appliances.txt");
    int cnt = 0;

    while(filein.good()){
        char appType;
        filein >> appType;
        switch(appType){
            //Use switch to check which type each appliance is and call the proper code
            case 'R':
                inStock[cnt] = new Refrigerator;
                inStock[cnt]->readData(filein);
                break;

            case 'D':
                inStock[cnt] = new Dishwasher;
                inStock[cnt]->readData(filein);
                break;

            case 'O':
                inStock[cnt] = new Oven;
                inStock[cnt]->readData(filein);
                break;

        }
        cnt++;
    }
    cnt--;
    //Bring cnt down by 1 to use it in following code as it ends one higher than the total
    cout << "Received the following appliances (total: " << cnt << ")\n\n";
    writeStuff(inStock, cnt, "Oven");
    writeStuff(inStock, cnt, "Dishwasher");
    writeStuff(inStock, cnt, "Refrigerator");
    //Call the writeStuff function for the different types. Used cnt to avoid going through the rest of an empty array

    cout << "Cleaning the freestore . . . ";
    for(int j = 0; j < cnt; j++){
        delete inStock[j];
    }
    cout << "Done!\n";

    return 0;

}
