#include "LinkedList.h"

int main()
{
    LinkedList<int> list;

    list.insertAtTail(4);
    list.insertAtTail(2);
    list.insertAtTail(8);
    list.insertAtTail(1);
    list.insertAtTail(9);
    list.insertAtTail(5);
    list.insertAtTail(6);

    cout << "Original List: ";
    list.display();

    int k;
    cout << "Enter the position of the node to move: ";
    cin >> k;

    if (list.moveKthNodeToFront(k))
    {
        cout << "Node moved successfully!" << endl;
    }
    else
    {
        cout << "Invalid position!" << endl;
    }

    cout << "Updated List: ";
    list.display();

    return 0;
}

