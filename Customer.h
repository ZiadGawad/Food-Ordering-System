#include <iostream>
#include <string>

#include "User.h"

using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

//Customer(inheritance)
class Customer : public User{
    private:
        string deliveryAddress;
        int loyaltyPoints;
        double totalSpent;///New
    public:
        //Constructors
        Customer();
        Customer(string id,string n,string phone,string delAdd,int Lpts);
        
        //Override Functions
        void displayInfo() override;
        double calcEarnings() override;

        //setters
        void setDelAddress(string delAdd);
        void setLoyaltyPoints(int Lpts);

        //Getters
        string getDelAddress();
        int getLoyaltyPoints();

        //Operator Overloading 
        Customer& operator +=(int points);
};

#endif