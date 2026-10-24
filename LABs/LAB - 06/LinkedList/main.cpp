#include "LinkedList.h"

int main()
{
    LinkedList<int> list;

    cout << "Is Empty: " << boolalpha << list.isEmpty() << endl;

    list.insertAtHead(20);
    list.insertAtHead(10);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "\nList: ";
    list.display();

    cout << "Size: " << list.getSize() << endl;
    cout << "Head: " << list.getHead() << endl;
    cout << "Tail: " << list.getTail() << endl;

    cout << "\nSearch 30: " << list.search(30) << endl;
    cout << "Search 50: " << list.search(50) << endl;

    list.insertAfter(25, 20);
    cout << "\nAfter inserting 25 after 20: ";
    list.display();

    list.insertBefore(15, 20);
    cout << "After inserting 15 before 20: ";
    list.display();

    cout << "Count of 20: " << list.count(20) << endl;

    list.removeAtHead();
    cout << "\nAfter removing head: ";
    list.display();

    list.removeAtTail();
    cout << "After removing tail: ";
    list.display();

    list.remove(25);
    cout << "After removing 25: ";
    list.display();

    cout << "Size: " << list.getSize() << endl;

    list.clear();
    cout << "\nAfter clearing the list: ";
    list.display();

    cout << "Is Empty: " << list.isEmpty() << endl;

    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtTail(40);

    cout << "Original: ";
    list.display();

    LinkedList<int> rev = list.reversed();

    cout << "Reversed: ";
    rev.display();

    return 0;
}


