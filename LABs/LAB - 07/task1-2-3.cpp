#include "CDLinkedList.h"

int main()
{
    // =========================================
    // TASK 1: MERGE TWO SORTED LISTS
    // =========================================
    cout << "===== TASK 1: MERGE =====" << endl;

    CDLinkedList list1, list2, list3;

    list1.insertAtTail(4);
    list1.insertAtTail(7);
    list1.insertAtTail(10);
    list1.insertAtTail(12);

    list2.insertAtTail(1);
    list2.insertAtTail(3);
    list2.insertAtTail(6);
    list2.insertAtTail(8);
    list2.insertAtTail(9);
    list2.insertAtTail(15);

    cout << "List 1: ";
    list1.display();

    cout << "List 2: ";
    list2.display();

    list3.merge(list1, list2);

    cout << "Merged list: ";
    list3.display();

    cout << "List 1 after merge: ";
    list1.display();

    cout << "List 2 after merge: ";
    list2.display();

    // =========================================
    // TASK 2: SPLIT INTO TWO HALVES
    // =========================================
    cout << "\n===== TASK 2: SPLIT =====" << endl;

    CDLinkedList original, leftHalf, rightHalf;

    original.insertAtTail(1);
    original.insertAtTail(3);
    original.insertAtTail(5);
    original.insertAtTail(6);
    original.insertAtTail(8);
    original.insertAtTail(12);
    original.insertAtTail(14);

    cout << "Original list: ";
    original.display();

    original.splitList(leftHalf, rightHalf);

    cout << "Left half: ";
    leftHalf.display();

    cout << "Right half: ";
    rightHalf.display();

    cout << "Original after split: ";
    original.display();

    // =========================================
    // TASK 3A: COMBINE IN O(1)
    // =========================================
    cout << "\n===== TASK 3A: COMBINE =====" << endl;

    CDLinkedList a, b, combined;

    a.insertAtTail(2);
    a.insertAtTail(4);
    a.insertAtTail(6);

    b.insertAtTail(8);
    b.insertAtTail(10);

    cout << "List A: ";
    a.display();

    cout << "List B: ";
    b.display();

    combined.combine(a, b);

    cout << "Combined list: ";
    combined.display();

    cout << "List A after combine: ";
    a.display();

    cout << "List B after combine: ";
    b.display();

    // =========================================
    // TASK 3B: SHUFFLE MERGE
    // =========================================
    cout << "\n===== TASK 3B: SHUFFLE MERGE =====" << endl;

    CDLinkedList x, y, shuffled;

    x.insertAtTail(2);
    x.insertAtTail(6);
    x.insertAtTail(4);

    y.insertAtTail(8);
    y.insertAtTail(1);
    y.insertAtTail(3);

    cout << "List X: ";
    x.display();

    cout << "List Y: ";
    y.display();

    shuffled.shuffleMerge(x, y);

    cout << "Shuffled list: ";
    shuffled.display();

    cout << "List X after shuffle: ";
    x.display();

    cout << "List Y after shuffle: ";
    y.display();

    return 0;
}

