#include <iostream>

using namespace std;

class Order
{
private:

    int orderId;
    string customerName;
    int preparationTime;

public:

    Order()
    {
        orderId = 0;
        customerName = "";
        preparationTime = 0;
    }
    Order(int id, string name, int time);
    int getId();
    string getName();
    int getPreparationTime();
    void setPreparationTime(int t);
};

