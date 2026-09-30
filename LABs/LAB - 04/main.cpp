#include "Queue.h"

int main()
{
    Queue<int> q(3);

    cout << "Initial Queue:" << endl;
    q.display();

    cout << "\nEnqueue:" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    cout << "\nSize: " << q.size() << endl;
    cout << "Capacity: " << q.GetCapacity() << endl;

    cout << "\nPeek: " << q.peek() << endl;

    cout << "\nDequeue: " << q.dequeue() << endl;
    q.display();

    cout << "\nEnqueue after dequeue:" << endl;
    q.enqueue(40);
    q.display();

    cout << "\nContains 20: ";
    cout << (q.contains(20) ? "Yes" : "No") << endl;

    cout << "Contains 100: ";
    cout << (q.contains(100) ? "Yes" : "No") << endl;

    cout << "\nSize: " << q.size() << endl;
    cout << "Capacity: " << q.GetCapacity() << endl;

    cout << "\nCopy Constructor:" << endl;
    Queue<int> q2(q);
    q2.display();

    cout << "\nAssignment Operator:" << endl;
    Queue<int> q3(5);
    q3.enqueue(100);
    q3.enqueue(200);

    q3 = q;
    q3.display();

    cout << "\nClear q:" << endl;
    q.clear();
    q.display();

    cout << "\nIs q Empty: ";
    cout << (q.isEmpty() ? "Yes" : "No") << endl;

    cout << "\nDouble Queue:" << endl;
    Queue<double> q4(3);

    q4.enqueue(1.5);
    q4.enqueue(2.5);
    q4.enqueue(3.5);

    q4.display();

    cout << "\nPeek: " << q4.peek() << endl;

    cout << "Dequeue: " << q4.dequeue() << endl;
    q4.display();

    return 0;
}