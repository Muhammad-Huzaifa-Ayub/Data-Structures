#include "Order.h"

Order::Order(int id, string name, int time)
{
    orderId = id;
    customerName = name;
    preparationTime = time;
}

int Order::getId()
{
    return orderId;
}

string Order::getName()
{
    return customerName;
}

int Order::getPreparationTime()
{
    return preparationTime;
}

void Order::setPreparationTime(int t)
{
    preparationTime = t;
}