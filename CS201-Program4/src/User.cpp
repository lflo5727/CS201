#include "User.h"
#include <string>
#include <fstream>

using namespace std;

User::User(){
    //Default constructor
    idNum = 0;
    firstName = "";
    lastName = "";
    booksCheckedOut = 0;
    arraySize = 5;
}

User::User(string first, string last, int id){
    //Constructor
    firstName = first;
    lastName = last;
    idNum = id;
    booksCheckedOut = 0;
    arraySize = 0;
}

User::User(const User& other){
    string* booksCopy;
    booksCopy = new string;
   *booksCopy = *other.bookArray;
}

bool User::resizeArray(){
    //Creates a new array that is larger and deletes the old one
    string* newArray = new string[arraySize];
    for(int i = 0; i < booksCheckedOut; i++){
        newArray[i] = bookArray[i];
    }
    delete[] bookArray;
    bookArray = newArray;
    return true;
}

//Getters
const int User::getIDNumber(){
    return idNum;
}
const string User::getFirstName(){
    return firstName;
}
const string User::getLastName(){
    return lastName;
}
const string User::getFullName(){
    return (lastName + ", " + firstName);
}

//Setters
void User::setIDNumber(int id){
    idNum = id;
}
void User::setFirstName(string first){
    firstName = first;
}
void User::setLastName(string last){
    lastName = last;
}


const int User::checkoutCount(){
    return booksCheckedOut;
}
bool User::CheckOut(const string& BookIDCode){
    //Checks if the book is in stock, and if it is then it checks it out and adjusts the array
    string temp;
    ifstream checkoutFile("checkouts.txt");
    bool isInStock = true;
    int bookIndex = booksCheckedOut;
    while(checkoutFile.good()){
        checkoutFile >> temp;
        if(temp == BookIDCode)
            isInStock = false;
    }
    checkoutFile.close();
    if(isInStock){
        booksCheckedOut++;
        if(booksCheckedOut == arraySize){
            arraySize *= 2;
            if(!resizeArray())
                return false;
        }
        bookArray[bookIndex] = BookIDCode;
        return true;
    }
    return false;
}


bool User::CheckIn(const string& BookIDCode){
    //Removes a book from the checked out array
    for(int i = 0; i < booksCheckedOut; i++){
        if(bookArray[i] == BookIDCode){
            for(;i < (booksCheckedOut-1); i++){
                bookArray[i] = bookArray[i+1];
            }
            booksCheckedOut -= 1;
            bookArray[booksCheckedOut] = "";

            if(booksCheckedOut == 0)
                delete[] bookArray;
            return true;
        }
    }
    return false;
}

const bool User::HasCheckedOut(const string& BookIDCode){
    //Checks if a user has checked out a particular book
    for(int i = 0; i < booksCheckedOut; i++){
        if(bookArray[i] == BookIDCode)
            return true;
    }
    return false;
}


void User::Clear(){
    //Clears out the object
    firstName = "";
    lastName = "";
    idNum = 0;
    booksCheckedOut = 0;
    bookArray = NULL;
    delete[] bookArray;
}

User::~User(){
    bookArray = NULL;
    delete[] bookArray;
}

//Overloaded operators
istream& operator>>(istream& input, User& item){
    //Inputs from the file creating the array based on number of books
    input >> item.idNum >> item.firstName >> item.lastName >> item.booksCheckedOut;
    if(item.booksCheckedOut == 1)
        item.bookArray = new string[5];
    else
        item.bookArray = new string[item.booksCheckedOut * 2];
    for(int i = 0; i < item.booksCheckedOut; i++){
        input >> item.bookArray[i];
    }
    return input;
}

ostream& operator<<(ostream& output, const User& item){
    //Outputs in format stated in the assignment
    output << item.idNum << " " << item.firstName << " " << item.lastName << endl << item.booksCheckedOut << "\n ";
    for(int i = 0; i < item.booksCheckedOut; i++){
        output << item.bookArray[i] << "\n ";
    }
    output << "\n\n";
    return output;
}

const User User::operator+(string rhs){
    //Create a copy of the user and have it checkout the book
    User newUser(firstName, lastName, idNum);
    newUser.booksCheckedOut = booksCheckedOut;
    newUser.bookArray = bookArray;
    newUser.CheckOut(rhs);
    return newUser;

}
void User::operator+=(string rhs){
    //Calls the checkout function to add the book
    CheckOut(rhs);
}

bool User::operator==(User rhs){
    //Checks IDs and returns true if equal
    if(idNum == rhs.getIDNumber()){
        return true;
    }else{
        return false;
    }
}

bool User::operator!=(User rhs){
    //Checks IDs and returns true if unequal
    if(idNum == rhs.getIDNumber()){
        return false;
    }else{
        return true;
    }
}
