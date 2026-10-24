#include "LinkedList.h"

int main()
{
    cout << "===== TASK 3: ALTERNATE MERGE =====" << endl;

    LinkedList<int> list1;
    LinkedList<int> list2;
    LinkedList<int> list3;

    list1.insertAtTail(2);
    list1.insertAtTail(6);
    list1.insertAtTail(4);

    list2.insertAtTail(8);
    list2.insertAtTail(1);
    list2.insertAtTail(3);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    list3.alternateMerge(list1, list2);

    cout << "Merged List: ";
    list3.display();

    cout << "List 1 after merge: ";
    list1.display();

    cout << "List 2 after merge: ";
    list2.display();

    cout << "\n===== TASK 4: REVERSE LIST =====" << endl;

    LinkedList<int> list4;

    list4.insertAtTail(10);
    list4.insertAtTail(20);
    list4.insertAtTail(30);
    list4.insertAtTail(40);

    cout << "Original List: ";
    list4.display();

    list4.reverseList();

    cout << "Reversed List: ";
    list4.display();

    cout << "\n===== TASK 5: REMOVE DUPLICATES =====" << endl;

    LinkedList<int> list5;

    list5.insertAtTail(23);
    list5.insertAtTail(5);
    list5.insertAtTail(4);
    list5.insertAtTail(23);
    list5.insertAtTail(6);
    list5.insertAtTail(78);
    list5.insertAtTail(4);
    list5.insertAtTail(5);

    cout << "Original List: ";
    list5.display();

    list5.removeDuplicates();

    cout << "List after removing duplicates: ";
    list5.display();

    return 0;
}

