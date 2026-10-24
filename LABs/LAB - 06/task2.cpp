#include "LinkedList.h"

int main()
{
    LinkedList<int> list1;
    LinkedList<int> list2;
    LinkedList<int> list3;

    list3.insertAtTail(7);
    list3.insertAtTail(3);
    list3.insertAtTail(4);
    list3.insertAtTail(2);
    list3.insertAtTail(5);
    list3.insertAtTail(9);

    cout << "Original List: ";
    list3.display();

    list3.split(list1, list2);

    cout << "List 1 (Odd positions): ";
    list1.display();

    cout << "List 2 (Even positions): ";
    list2.display();

    cout << "Original List after split: ";
    list3.display();

    return 0;
}

