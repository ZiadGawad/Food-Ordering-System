#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "Order.h"
#include "FoodItem.h"
#include "User.h"
#include "Customer.h"
#include "Driver.h"
#include "FileOperation.h"


using namespace std;

int main() {
    int choice;

    Customer* customers[100];
    int customerCount = 0 ;

    DeliveryDriver* drivers[100];
    int driverCount = 0;

    Order* orders[100];
    int orderCount = 0;

    do{

    //Layout
    cout<<"===============ElMENUS MANAGEMENT SYSTEM V1.40===============\n";
    cout<<"----------------------USER MANAGMENT-------------------------\n";
    cout<<"1. Register New Customer\n";
    cout<<"2. Register New Delivery Driver\n";
    cout<<"----------------------ORDER MANAGEMENT-----------------------\n";
    cout<<"3. Create New Order\n";
    cout<<"4. Add Items to Order\n";
    cout<<"5. Assign Driver to Order\n";
    cout<<"6. Update Order Status\n";
    cout<<"7. Display Order Details\n";
    cout<<"--------------------INFORMATION & REPORTS--------------------\n";
    cout<<"8. Display Customer Information\n";
    cout<<"9. Display Driver Information\n";
    cout<<"10. Compare Two Orders by Total\n";
    cout<<"11. Display System Statistics\n";
    cout<<"------------------------FILE OPERATIONS-----------------------\n";
    cout<<"12. Save Completed Orders to File\n";
    cout<<"13. Save Driver Statistics to File\n";
    cout<<"--------------------------------------------------------------\n";
    cout<<"0. Exit\n";
    cout<<"==============================================================\n";
    cout<<"ENTER CHOICE: ";
    cin>>choice;

    //Switch Cases
    switch(choice){
        case 1: {

            string id,name,phone,address;
            cout<<"\n---REGISTER NEW CUSTOMER---\n";
            cout<<"Enter ID: ";
            cin>>id;
            cout<<"Enter Name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter Phone Number: ";
            cin>>phone;
            cout<<"Enter Delivery Address: ";
            cin.ignore();
            getline(cin,address);

            customers[customerCount] = new Customer(id,name,phone,address,0);

            cout<<endl;
            cout<<"Customer Registered Successfully!"<<endl;
            
            customerCount++;
            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 2: {
            string id,name,phone,vehicle;
            cout<<"\n---REGISTER NEW DRIVER---\n";
            cout<<"Enter ID: ";
            cin>>id;
            cout<<"Enter Name: ";
            cin.ignore();
            getline(cin,name);
            cout<<"Enter Phone Number: ";
            cin>>phone;
            cout<<"Enter Vehicle Type: ";
            cin.ignore();
            getline(cin,vehicle);

            drivers[driverCount] = new DeliveryDriver(id,name,phone,vehicle,0,0);

            cout<<endl;
            cout<<"Driver Registered Successfully!"<<endl;
            
            driverCount++;
            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 3: {
            cout<<"\n---CREATE NEW ORDER---\n";

            string orderId;
            int index;

            if(customerCount == 0){
                cout<<"No customers found. Register a customer first.\n";
                break;
            }

            cout<<"Enter Order ID: ";
            cin>>orderId;

            cout<<"Choose Customer (0 to "<<customerCount-1<<" ): ";
            cin>>index;

            if(index < 0 || index >= customerCount){
                cout<<"Invalid customer index! Order Not created.\n";
                break;
            }

            orders[orderCount] = new Order(orderId,customers[index]);

            cout<<"Order Created Successfully!\n";
            orderCount++;
            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 4: {
            int index , quantity;
            string name;
            double price;

            cout<<"\n---ADD ITEMS TO ORDER---\n";

            if(orderCount == 0){
                cout<<"No orders found. Create an order first.\n";
                break;
            }

            cout<<"Choose Order(0 to "<<orderCount-1<<" ): ";
            cin>>index;
            if(index < 0 || index >= orderCount){
                cout<<"Invalid order index!\n";
                break;
            }
            
            cin.ignore();
            cout<<"Item Name: ";
            getline(cin,name);
            cout<<"Price: ";
            cin>>price;
            cout<<"Quantity: ";
            cin>>quantity;

            FoodItem newItem(name,price,quantity);
            orders[index]->addItem(newItem);

            cout<<"Item Added Successfully!\n";
            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 5: {
            cout<<"\n---ASSIGN DRIVER TO ORDER---\n";
            
            if(orderCount == 0){
                cout<<"No Orders Found. Create an Order First.\n";
                break;
            }

            if(driverCount == 0){
                cout<<"No Drivers Found. Register a Driver First.\n";
                break;
            }

            int orderIndex,driverIndex;

            cout<<"Choose Order (0 to "<<orderCount - 1<<"): ";
            cin>>orderIndex;
            
            if(orderIndex < 0 || orderIndex >= orderCount){
                cout<<"Invalid order index!\n";
                break;
            }

            cout<<"Choose Driver (0 to "<<driverCount - 1<<"): ";
            cin>>driverIndex;

            if(driverIndex < 0 || driverIndex >= driverCount){
                cout<<"Invalid driver index!\n";
                break;
            }

            orders[orderIndex]->assignDriver(drivers[driverIndex]);

            cout<<"Driver Assigned Successfully!\n";

            cout<<"--------------------------------------------------------------\n";
            cout<<endl;

            break;
        }
        case 6: {
            cout<<"\n---UPDATE ORDER STATUS---\n";
            int orderIndex,newStatus;

            cout<<"Choose Order (0 to "<<orderCount-1<<"): ";
            cin>>orderIndex;
            if(orderIndex < 0 || orderIndex >= orderCount){
                cout<<"Invalid order index!.\n";
                break;
            }

            cout<<"Choose New Status: \n";
            cout<<"0 - PENDING\n";
            cout<<"1 - PREPARING\n";
            cout<<"2 - OUT FOR DELIVERY\n";
            cout<<"3 - DELIVERED\n";
            cout<<"4 - CANCELLED\n";
            cout<<"Enter: ";
            cin>>newStatus;

            if(newStatus < 0 || newStatus > 4){
                cout<<"Invalid status!\n";
                break;
            }


            orders[orderIndex]->updateStatus((orderStatus)newStatus);

            cout<<"Status updated successfully!\n";

            if(newStatus == DELIVERED){
                DeliveryDriver* d = orders[orderIndex]->getDriver();
                Customer* c = orders[orderIndex]->getCustomer();

                double total = orders[orderIndex]->calculateTotal();
            
            
                if(d){
                    d->completeDelivery(total);
                    //(*d)++;
                }

                if(c){
                    c->calcEarnings();
                }

                cout<<"\nOrder Deliverd!\n";
                cout<<"Driver and Customer stats updated.\n";
            }

            cout<<"--------------------------------------------------------------\n";
            cout<<endl;

            break;
        }
        case 7: {
            cout<<"\n---Display Order Details---\n";
        
            int index;

            cout<<"Choose order from (0 to "<<orderCount - 1<<"): ";
            cin>>index;

            if(index < 0 || index >= orderCount){
                cout<<"Invalid order index.\n";
                break;
            }

            orders[index]->displayOrder();

            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 8: {
            cout<<"\n---Display Customer Information---\n";
            int index;

            cout<<"Choose customer from (0 to "<<customerCount - 1<<"): ";
            cin>>index;

            if (index < 0 || index >= customerCount){
                cout<<"Invalid customer index!\n";
                break;
            }

            customers[index]->displayInfo();

            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 9: {
            cout<<"\n---Display Driver Information---\n";
            int index;

            cout<<"Choose driver from (0 to "<<driverCount - 1<<"): ";
            cin>>index;

            if (index < 0 || index >= driverCount){
                cout<<"Invalid driver index!\n";
                break;
            }

            drivers[index]->displayInfo();

            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 10: {
            cout<<"\n---Compare Orders By Total---\n";
            int i1,i2;

            cout<<"Choose Order 1 & Order 2 from (0 to "<<orderCount - 1<<"): ";
            cin>>i1>>i2;

            if (i1 < 0 || i2 < 0 || i1 >= orderCount || i2 >= orderCount){
                cout<<"Invalid Orders Index!\n";
                break;
            }

            if(orders[i1]->calculateTotal() > orders[i2]->calculateTotal()){
                cout<<"Order 1 > Order 2\n";
                break;
            }
            else if (orders[i2]->calculateTotal() > orders[i1]->calculateTotal()){
                cout<<"Order 2 > Order 1\n";
                break;
            }
            else{
                cout<<"Order 1 = Order2\n";
                break;
            }

            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 11: {
            cout<<"\n---Display System Statistics---\n";
            cout<<"Total Users: "<<User::getTotalUsers()<<endl;
            cout<<"Total Customers: "<<customerCount<<endl;;
            cout<<"Total Driver: "<<driverCount<<endl;;
            cout<<"Total Orders: "<<orderCount<<endl;

            double totalRevenue = 0;
            int completedOrders = 0;
            for(int i = 0; i < orderCount; i++){
                if(orders[i]->getOrderStatus() == DELIVERED){
                    totalRevenue += orders[i]->calculateTotal();
                    completedOrders++;
                }
            }

            cout<<"Completed Orders: "<<completedOrders<<endl;
            cout<<"Total Revenue: "<<fixed<<setprecision(2)<<totalRevenue<<" EGP\n";
            
            cout<<"--------------------------------------------------------------\n";
            cout<<endl;
            break;
        }
        case 12: {
            if(orderCount == 0){
                cout<<"No Orders found.\n";
            }
            saveCompletedOrder(orders,orderCount);
            cout<<"Completed orders saved to completed_orders.txt\n";
            break;
        }
        case 13: {
            if(driverCount == 0){
                cout<<"No drivers found.\n";
                break;
            }
            saveDriverStats(drivers,driverCount);
            cout<<"Driver statistics saved to diver_stats.txt\n";
            break;
        }
        case 0: {
            cout<<"Exiting Program...\n";
            break;
        }
        default: {
            cout<<"Invalid Choice!"<<endl;
            break;
        }

    }
}while(choice != 0);
    cout<<"\nCleaning up memory....\n";

    for(int i = 0; i < orderCount; i++){
        delete orders[i];
    }

    for(int i = 0; i < customerCount; i++){
        delete customers[i];
    }

    for(int i = 0; i < driverCount; i++){
        delete drivers[i];
    }

    cout<<"Memory Cleaned.!\n";

    return 0;
}
