#include <fstream>
#include <iomanip>
#include "Order.h"
using namespace std;


//Save Completed Order function to file
void saveCompletedOrder(Order* orders[],int count){
    ofstream file("completed_orders.txt",ios::app);
    if(!file){
        cout<<"Error opening completed_orders.txt"<<endl;
        return;
    }

    for(int i = 0; i < count; i++){

        if(orders[i]->getOrderStatus() != DELIVERED){
            continue;
        }

        Customer* c = orders[i]->getCustomer();
        DeliveryDriver* d = orders[i]->getDriver();

        //Print to screen
        cout<<"Order ID: "<<orders[i]->getOrderId()<<endl;
        cout<<"Customer: "<< (c? c->getName():"N/A")<<endl;
        cout<<"Driver: "<<(d? d->getName():"N/A")<<endl;

        //Save to file
        file<<"Order ID: "<<orders[i]->getOrderId()<<endl;
        file<<"Customer: "<< (c? c->getName():"N/A")<<endl;
        file<<"Driver: "<<(d? d->getName():"N/A")<<endl;

        for (int j = 0; j < orders[i]->getItemCount(); j++){
            const FoodItem& it = (*orders[i])[j];
            cout<<j+1<<"- "<< it.getItemName()<<" x"<<it.getQuantity()<<" = "<<it.calculateItemTotal()<<" EGP"<<endl;
            file<<j+1<<"- "<< it.getItemName()<<" x"<<it.getQuantity()<<" = "<<it.calculateItemTotal()<<" EGP"<<endl;
        }

        cout<<"Total: "<<fixed<<setprecision(2)
            <<orders[i]->calculateTotal()<<" EGP"<<endl;
        file<<"Total: "<<fixed<<setprecision(2)
            <<orders[i]->calculateTotal()<<" EGP"<<endl;
        cout<<"----------------------------------------"<<endl;
        file<<"----------------------------------------"<<endl;
        cout<<"Order Saved Successfully!"<<endl;
    }
    file.close();    
}

//Save Driver Statistics
void saveDriverStats(DeliveryDriver* drivers[],int count){
    ofstream file("driver_stats.txt",ios::app);
    if(!file){
        cout<<"Error opening driver_stats.txt"<<endl;
        return;
    }
    for(int i = 0; i < count; i++){
        //Print Driver Stats
        cout<<"Driver: "<<drivers[i]->getName()<<endl;
        cout<<"Total Deliveries: "<<drivers[i]->getCompDels()<<endl;
        cout<<"Total Earnings: "<<fixed<<setprecision(2)<<drivers[i]->getTotalEarns()<<" EGP"<<endl;
        //Save Driver Stats to file
        file<<"Driver: "<<drivers[i]->getName()<<endl;
        file<<"Total Deliveries: "<<drivers[i]->getCompDels()<<endl;
        file<<"Total Earnings: "<<fixed<<setprecision(2)<<drivers[i]->getTotalEarns()<<" EGP"<<endl;
    }
    file.close();
}



