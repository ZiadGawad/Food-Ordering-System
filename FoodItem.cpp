#include <iostream>
#include <string>
#include <iomanip>

#include "FoodItem.h"
using namespace std;

//Constructors
FoodItem::FoodItem():itemName(""),price(0),quantity(0){}
FoodItem::FoodItem(string name, double p, int q):itemName(name),price(p),quantity(q){}

//Getters
string FoodItem::getItemName() const {
    return itemName;
}

double FoodItem::getPrice() const { 
    return price;
}

int FoodItem::getQuantity() const {
    return quantity;
}

//Setters
void FoodItem::setItemName(string itemName) { 
    this->itemName = itemName;
}

void FoodItem::setPrice(double price){
    this->price = price;
}

void FoodItem::setQuantity(int quantity){
    this->quantity = quantity;
}

//Class Functions
double FoodItem::calculateItemTotal() const {
    return price * quantity;
}

void FoodItem::displayItem() const {
    cout<<itemName<<" x"<<quantity
    <<" @ "<<fixed<<setprecision(2)<<price
    <<" EGP = "<<fixed<<setprecision(2)<<calculateItemTotal()<<" EGP"<<endl;
}

