#include "Queue.h"
#include "Order.h"

class OrderManager{

private:

    Queue<Order> q;
    int timeQuantum;

public:

    OrderManager( Order arr[], int len, int tq );
    
    void processOrders();
};
