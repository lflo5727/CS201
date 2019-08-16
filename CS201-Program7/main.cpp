///////////////////////////////////
//          Liam Floyd
//     CS201 - Assignment 7
//           12/8/17
///////////////////////////////////
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <iterator>
using namespace std;


int main()
{
	ifstream fin("ratings.txt");
	map<string, int> mapNumReviewers;
	map<string, float> mapSumReviews;
	//Changed to float as example output uses decimal places

	//Open the ratings.txt file. Report Fail and exit application if failed to open
	if(!fin) {
		cout << "Error opening input file!";
		return 1;
	}

    int total;
    fin >> total;
    //Read in total
    while(fin.good()){
        string resName;
        int rating;
        bool exists = false;

        //Read into the temp variables resName and rating, making sure to get the full line for resName
        fin.ignore();
        getline(fin, resName);
        fin >> rating;

        for(map<string,int>::iterator iterN = mapNumReviewers.begin(); iterN != mapNumReviewers.end(); iterN++){
            //Use iterator to find resName in the map keys
			if(iterN->first == resName){
				iterN->second++;
				exists = true;
				break;
			}
		}
        if(!exists){
            //If resName has no key match, a new map key/value is created
            mapNumReviewers.insert(pair <string, int> (resName, 1));
            mapSumReviews.insert(pair <string, int> (resName, rating));
        }else{
            for(map<string,float>::iterator iterS = mapSumReviews.begin(); iterS != mapSumReviews.end(); iterS++){
                //If it does exist, the rating is applied to it
                if(iterS->first == resName){
                    iterS->second = ((iterS->second + rating)/2);
                }
            }
        }
    }

    for(map<string,int>::iterator iterP = mapNumReviewers.begin(); iterP != mapNumReviewers.end(); iterP++){
        //Simply output the values of the maps
        cout << iterP->first << ":\t" << iterP->second << " reviewers.\tAverage of " << mapSumReviews[iterP->first] << "/5\t";

        //Stars added for rating
        int star = mapSumReviews[iterP->first];
        for(int i = 0; i < star; i++){
            cout << "*";
        }
        cout << endl;
    }




    fin.close();
	return 0;
}
