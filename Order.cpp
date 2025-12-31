#include <iostream>
#include <string>
#include <iomanip>

#include "Order.h"
#include "FoodItem.h"
#include "User.h"
#include "Customer.h"
#include "Driver.h"


using namespace std;

//Initialize static member
int Order::totalOrders = 0;

//Define static function
int Order::getTotalOrders(){
    return totalOrders;
}

//Constructors
Order::Order():orderId(""),customer(nullptr),driver(nullptr),capacity(5),
            itemCount(0),status(PENDING){
            item = new FoodItem* [capacity];
            totalOrders++;
}

Order::Order(string orderId,Customer* customer)
            :orderId(orderId),customer(customer),
            driver(nullptr),capacity(5),itemCount(0),status(PENDING){
                item = new FoodItem*[capacity];
                totalOrders++;
}

Order::Order(const Order& obj)
            :orderId(obj.orderId),customer(obj.customer),
            driver(obj.driver),capacity(obj.capacity),itemCount(obj.itemCount),
            status(obj.status){
                item = new FoodItem*[capacity];
                for(int i = 0; i < itemCount; i++){
                    item[i] = new FoodItem(*(obj.item[i]));
                }
            totalOrders++;
}

//Destructor
Order::~Order(){
    for(int i = 0; i < itemCount; i++){
        delete item[i];
    }
    delete[] item;
    item = nullptr;
}

//Methods
void Order::addItem(const FoodItem& item){
    if(itemCount == capacity){
        int newCapacity;
        newCapacity = 2 * capacity;
        FoodItem** temp = new FoodItem*[newCapacity];
        for(int i = 0; i < itemCount; i++){
            temp[i] = this->item[i];
        }
        delete[] this->item;
        this->item = temp;
        capacity = newCapacity;
    }
    this->item[itemCount] = new FoodItem(item);
    itemCount++;
}

void Order::assignDriver(DeliveryDriver* drv){
    this->driver = drv;
}

double Order::calculateTotal() const{
    double total = 0;
    for(int i = 0; i < itemCount; i++){
        total += item[i]->calculateItemTotal();
    }
    return total;
}

void Order::updateStatus(orderStatus newStatus){
    this->status = newStatus;
    if(this->status == DELIVERED){
        double total = calculateTotal();
        //Update Driver
        if(driver != nullptr){
        ++(*driver);
        driver->completeDelivery(total);
        }
        //Update Customer
        if(customer != nullptr){
            double total = calculateTotal();
            int points = static_cast<int>(total / 10);
            *customer += points;
        }
    }
}

void Order::displayOrder(){
    cout<<"Order ID: "<<orderId<<endl;
    cout<<"Status: ";
    switch(status){
        case PENDING: cout<<"PENDING"; break;
        case PREPARING: cout<<"PREPARING"; break;
        case OUT_FOR_DELIVERY: cout<<"OUT FOR DELIVERY"; break;
        case DELIVERED: cout<<"DELIVERED"; break;
        case CANCELLED: cout<<"CANCELLED"; break;
    }
    cout<<endl;
    if(customer != nullptr){
        customer->displayInfo();
    }
    if(driver != nullptr){
        driver->displayInfo();
    }
    else{
        cout<<"Driver not assigned yet."<<endl;
    }
    cout<<"Items: "<<endl;
    for(int i = 0; i < itemCount; i++){
        item[i]->displayItem();
    }
    cout<<"Total Price: "<<fixed<<setprecision(2)<<calculateTotal()<<" EGP"<<endl;
}

//Getters
string Order::getOrderId() const{
    return orderId;
}

Customer* Order::getCustomer() const{
    return customer;
}

DeliveryDriver* Order::getDriver() const{
    return driver;
}

orderStatus Order::getOrderStatus() const{
    return status;
}

int Order::getItemCount() const{
    return itemCount;
}

//Operator Overloading
Order& Order::operator+=(const FoodItem& item){
    this->addItem(item);
    return *this;
}

Order Order::operator+(const Order& other){
    Order newOrder;
    newOrder.customer = this->customer;
    for(int i = 0; i < this->itemCount; i++){
        newOrder.addItem(*item[i]);
    }
    for(int i = 0; i < other.itemCount; i++){
        newOrder.addItem(*(other.item[i]));
    }
    return newOrder;
}

ostream& operator<<(ostream& out,const Order& obj){
    out<<"Order ID: "<<obj.orderId<<endl;
    out<<"Order Status: ";
    switch(obj.status){
        case PENDING: out<<"PENDING"; break;
        case PREPARING: out<<"PREPARING"; break;
        case OUT_FOR_DELIVERY: out<<"OUT FOR DELIVERY"; break;
        case DELIVERED: out<<"DELIVERED"; break;
        case CANCELLED: out<<"CANCELLED"; break;
    }
    out<<"Items: "<<endl;
    for(int i = 0; i < obj.itemCount; i++){
        obj.item[i]->displayItem();
    }
    out<<"Total Price: "<<obj.calculateTotal()<<" EGP";
    return out;
}

bool operator>(const Order& obj1,const Order& obj2){
    return obj1.calculateTotal() > obj2.calculateTotal();
}

FoodItem& Order::operator[](int index){
    if(index < 0 || index >= this->itemCount){
        cout<<"Inex Out of bounds";
            return *item[0];
    }
    return *(item[index]);
}

const FoodItem& Order::operator[](int index) const{
    if(index < 0 || index >= this->itemCount){
        cout<<"Inex Out of bounds";
            return *item[0];
    }
    return *(item[index]);
}