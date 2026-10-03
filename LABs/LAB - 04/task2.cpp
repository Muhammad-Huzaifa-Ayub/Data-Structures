#include "Queue.h"

int printerTime( int pages[], int n, int k )
{
    Queue<int> pageQueue(n);
    Queue<int> indexQueue(n);

    for ( int i = 0; i < n; i++ )
    {
        pageQueue.enqueue(pages[i]);
        indexQueue.enqueue(i);
    }

    int time = 0;

    while ( !pageQueue.isEmpty() )
    {
        int pagesLeft = pageQueue.dequeue();
        int index = indexQueue.dequeue();

        pagesLeft--;
        time++;

        if ( pagesLeft == 0 && index == k )
        {
            return time;
        }

        if ( pagesLeft > 0 )
        {
            pageQueue.enqueue(pagesLeft);
            indexQueue.enqueue(index);
        }
    }

    return time;
}

int main()
{
    int pages[] = {3, 3, 1, 2};
    int n = 4;
    int k = 0;

    cout << printerTime(pages, n, k) << endl;

    return 0;
}