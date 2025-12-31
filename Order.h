#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include <iomanip>

#include "FoodItem.h"
#include "User.h"
#include "Customer.h"
#include "Driver.h"

using namespace std;

//enums
enum orderStatus{PENDING,PREPARING,OUT_FOR_DELIVERY,DELIVERED,CANCELLED};
enum userType{CUSTUMER,DRIVER};

//Order Class
class Order{
    private:
        string orderId;
        Customer* customer;
        DeliveryDriver* driver;
        FoodItem** item;
        int itemCount , capacity;
        orderStatus status;
        static int totalOrders;
    public:
        //Constructors
        Order();
        Order(string orderId,Customer* customer);
        Order(const Order& obj);

        //Destructor
        ~Order();

        //Methods
        void addItem(const FoodItem& item);
        void assignDriver(DeliveryDriver* drv);
        double calculateTotal() const;
        void updateStatus(orderStatus newStatus);
        void displayOrder();
        static int getTotalOrders();

        //Getters
        string getOrderId() const;
        Customer* getCustomer() const;
        DeliveryDriver* getDriver() const;
        orderStatus getOrderStatus() const;
        int getItemCount() const;

        //Operator Overloading
        Order& operator+=(const FoodItem& item);
        Order operator+(const Order& other);
        friend ostream& operator<<(ostream& out,const Order& obj);
        friend bool operator>(const Order& obj1,const Order& obj2);
        FoodItem& operator[](int index);
        const FoodItem& operator[](int index) const;
};

#endif