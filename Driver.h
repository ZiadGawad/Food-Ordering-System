#include <iostream>
#include <string>

#include "User.h"

using namespace std;

#ifndef DRIVER_H
#define DRIVER_H

//Delivery Driver(inheritance)
class DeliveryDriver : public User{
    private: 
        string vehicleType;
        int completedDeliveries;
        double totalEarnings;
    public:
        //Constructors
        DeliveryDriver();
        DeliveryDriver(string id,string n,string phone,string vehicleType,int completedDel,double totalEarnings);
        
        //Override functions
        void displayInfo() override; 
        double calcEarnings() override;

        //Setters
        void setVehicleType(string v);
        void setCompDels(int c);
        void setTotalEarns(double t);

        //Getters
        string  getVehicleType();
        int  getCompDels();
        double  getTotalEarns();

        //Method
        void completeDelivery(double orderValue);

        //Operators OverLoading
            //Prefix
        DeliveryDriver& operator++();
            //Postfix
        DeliveryDriver operator++(int);
};


#endif

