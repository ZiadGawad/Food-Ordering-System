#include <iostream>
#include <string>
using namespace std;

#ifndef USER_H
#define USER_H

//Parent Class
class User{
    protected:
        string userId,name,phoneNumber;
        static int totalUsers; 
    public:
        //Constructors
        User();
        User(string userId,string name,string phoneNumber);
        
        //Virtual pure functions
        virtual void displayInfo() = 0;
        virtual double calcEarnings() = 0;
        static int getTotalUsers();
        
        //Getters
        string getUserID();
        string getName();
        string getPhoneNumber();

        //Destructor
        virtual ~User();
};

#endif