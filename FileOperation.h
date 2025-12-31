#ifndef FILE_OPERATION_H
#define FILE_OPERATION_H

#include <fstream>
#include <iomanip>
#include "Order.h"
using namespace std;


void saveCompletedOrder(Order* orders[],int count);
void saveDriverStats(DeliveryDriver* drivers[],int count);

#endif