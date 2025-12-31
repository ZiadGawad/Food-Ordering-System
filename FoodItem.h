#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

class FoodItem{
    private:
        string itemName;
        double price;
        int quantity;
    public:
        //Constructors
        FoodItem();
        FoodItem(string itemName,double price,int quantity);

        //Getters
        string getItemName() const ;
        double getPrice() const ;
        int getQuantity() const ;

        //Setters
        void setItemName(string itemName);
        void setPrice(double price);
        void setQuantity(int quantity);

        //Class Functions
        double calculateItemTotal() const;
        void displayItem() const ;
};

#endif