#include <iostream>
#include <string>

#include "User.h"
#include "Driver.h"

using namespace std;

//Delivery Driver

//Constructors
DeliveryDriver::DeliveryDriver()
    :User(),vehicleType(""),completedDeliveries(0),totalEarnings(0){}
DeliveryDriver::DeliveryDriver(string id,string n,string phone,string vehicleType,int completedDel,double totalEarnings)
    : User(id,n,phone),vehicleType(vehicleType),completedDeliveries(completedDel),totalEarnings(totalEarnings) {}


//Override Functions
void DeliveryDriver::displayInfo(){
    //Parent Info
    cout<<"User ID: "<<userId<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Phone: "<<phoneNumber<<endl;
    //Delivery Driver Info
    cout<<"Vehicle Type: "<<vehicleType<<endl;
    cout<<"Completed Deliveries: "<<completedDeliveries<<endl;
    cout<<"Total Earnings: "<<totalEarnings<<endl;
}

double DeliveryDriver::calcEarnings() { 
    return totalEarnings;
}

//Setters
void DeliveryDriver::setVehicleType(string v){ 
    vehicleType = v;
}

void DeliveryDriver::setCompDels(int c) { 
    completedDeliveries = c;
}

void DeliveryDriver::setTotalEarns(double t) { 
    totalEarnings = t;
}

//Getters
string DeliveryDriver:: getVehicleType(){ 
    return vehicleType; 
}

int DeliveryDriver::getCompDels() { 
    return completedDeliveries;
}

double DeliveryDriver:: getTotalEarns() { 
    return totalEarnings;
}

//Method
void DeliveryDriver::completeDelivery(double orderValue){
    totalEarnings += 0.15 * orderValue;
}

//Operators Overloading
    //Prefix
DeliveryDriver& DeliveryDriver::operator++(){
    completedDeliveries++;
    return *this;
}

    //Postfix
DeliveryDriver DeliveryDriver::operator++(int){
    DeliveryDriver temp = *this;
    completedDeliveries++;
    return temp;
}
