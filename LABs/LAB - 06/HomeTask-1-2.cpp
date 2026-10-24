#include "LinkedList.h"

int main()
{
    cout << "===== HOME TASK 1: REMOVE KTH NODE =====" << endl;

    LinkedList<int> list;

    list.insertAtTail(4);
    list.insertAtTail(2);
    list.insertAtTail(8);
    list.insertAtTail(1);
    list.insertAtTail(9);
    list.insertAtTail(5);
    list.insertAtTail(4);
    list.insertAtTail(6);

    cout << "Original List: ";
    list.display();

    int k = 4;
    int val = 0;

    if (list.removeKthNode(k, val))
    {
        cout << "Removed value: " << val << endl;
    }
    else
    {
        cout << "Invalid position!" << endl;
    }

    cout << "List after removal: ";
    list.display();

    cout << "\n===== HOME TASK 2: COMBINE LISTS =====" << endl;

    LinkedList<int> list1;
    LinkedList<int> list2;
    LinkedList<int> list3;

    list1.insertAtTail(7);
    list1.insertAtTail(3);
    list1.insertAtTail(4);
    list1.insertAtTail(2);

    list2.insertAtTail(5);
    list2.insertAtTail(9);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    list3.combine(list1, list2);

    cout << "Combined List: ";
    list3.display();

    cout << "List 1 after combine: ";
    list1.display();

    cout << "List 2 after combine: ";
    list2.display();

    return 0;
}

