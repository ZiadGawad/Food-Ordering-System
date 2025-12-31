#include <iostream>
#include <string>

#include "User.h"
#include "Customer.h"

using namespace std;

//Customer

//Constructors
Customer::Customer():User(),deliveryAddress(""),loyaltyPoints(0){}
Customer::Customer(string id,string n,string phone,string delAdd,int Lpts)
    : User(id,n,phone),deliveryAddress(delAdd),loyaltyPoints(Lpts){}


//Override functions
void Customer::displayInfo(){
    //Parent Info
    cout<<"User ID: "<<userId<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Phone: "<<phoneNumber<<endl;
    //Customer Info
    cout<<"Delivery Address: "<<deliveryAddress<<endl;
    cout<<"Loyalty Points: "<<loyaltyPoints<<endl;
}

double Customer::calcEarnings(){
    return loyaltyPoints * 0.5;
}

//Setters
void Customer::setDelAddress(string delAdd){
    deliveryAddress = delAdd; 
}
void Customer::setLoyaltyPoints(int Lpts){ 
    loyaltyPoints = Lpts;
}

//Getters
string Customer::getDelAddress(){
    return deliveryAddress;
}
int Customer::getLoyaltyPoints(){
    return loyaltyPoints;
}

//Operator
Customer& Customer::operator+=(int points){
    this->loyaltyPoints += points;
    return *this;
}