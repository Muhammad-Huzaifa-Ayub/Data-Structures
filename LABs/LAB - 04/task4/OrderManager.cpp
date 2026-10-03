#include "OrderManager.h"

OrderManager::OrderManager(Order arr[], int len, int tq)
{
    timeQuantum = tq;
    for ( int i = 0; i < len; i++ )
    {
        q.enqueue(arr[i]);
    }

}

void OrderManager::processOrders()
{

    while ( !q.isEmpty() )
    {
        Order temp = q.dequeue();
        temp.setPreparationTime( temp.getPreparationTime() - 5 );

        if ( temp.getPreparationTime() == timeQuantum || temp.getPreparationTime() <= 0 )
        {
            cout << "\nOrder completed : " << temp.getId() << " " << temp.getName() << endl << endl;
        }
        else if ( temp.getPreparationTime() >  timeQuantum )
        {
            cout << "\nOrder prcessing : " << temp.getId() << " " << temp.getName() << " " << temp.getPreparationTime() << endl << endl;
            q.enqueue(temp);
        }
    }   
}