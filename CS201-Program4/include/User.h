#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
using namespace std;

class User{
    private:
        string firstName;
        string lastName;
        unsigned int idNum;
        unsigned int booksCheckedOut;
        int arraySize;
        string* bookArray;
        bool resizeArray();
    public:
        User();
        User(string, string, int);
        User(const User& other);
        const User& operator=(const User& rhs);

        const int getIDNumber();
        const string getFirstName();
        const string getLastName();
        const string getFullName();

        void setIDNumber(int);
        void setFirstName(string);
        void setLastName(string);

        const int checkoutCount();
        bool CheckOut(const string& BookIDCode);
        bool CheckIn(const string& BookIDCode);
        const bool HasCheckedOut(const string& BookIDCode);
        void Clear();
        ~User();

        friend istream& operator >>(istream& in, User& item);
        friend ostream& operator<<(ostream& out, const User& item);
        const User operator+(string rhs);
        void operator+=(string rhs);
        bool operator==(User rhs);
        bool operator!=(User rhs);

};

#endif // USER_H
