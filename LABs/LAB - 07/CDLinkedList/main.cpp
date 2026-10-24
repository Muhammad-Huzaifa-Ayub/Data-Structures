#include "CDLinkedList.h"

int main()
{
    CDLinkedList list;

    // Insertions
    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Original list: ";
    list.display();

    // Search
    cout << "Search 30: ";
    if (list.search(30))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    cout << "Search 50: ";
    if (list.search(50))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    // Update
    list.update(30, 35);

    cout << "After updating 30 to 35: ";
    list.display();

    // Count
    cout << "Number of nodes: " << list.countNodes() << endl;

    // Remove a specific value
    list.remove(20);

    cout << "After removing 20: ";
    list.display();

    // Remove head
    list.removeAtHead();

    cout << "After removing head: ";
    list.display();

    // Remove tail
    list.removeAtTail();

    cout << "After removing tail: ";
    list.display();

    cout << "Final node count: " << list.countNodes() << endl;

    return 0;
}
