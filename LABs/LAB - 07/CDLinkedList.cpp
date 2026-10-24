#include "CDLinkedList.h"

// =============================================
// DNode CONSTRUCTOR
// =============================================
DNode::DNode(int val)
{
    data = val;
    next = nullptr;
    prev = nullptr;
}

// =============================================
// CDLinkedList CONSTRUCTOR
// =============================================
CDLinkedList::CDLinkedList()
{
    head = nullptr;
}

// =============================================
// DESTRUCTOR
// =============================================
CDLinkedList::~CDLinkedList()
{
    if (head == nullptr)
        return;

    DNode *current = head->next;

    while (current != head)
    {
        DNode *temp = current;
        current = current->next;
        delete temp;
    }

    delete head;
    head = nullptr;
}

// =============================================
// INSERT AT HEAD
// =============================================
void CDLinkedList::insertAtHead(int val)
{
    DNode *newNode = new DNode(val);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    DNode *tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;

    head = newNode;
}

// =============================================
// INSERT AT TAIL
// =============================================
void CDLinkedList::insertAtTail(int val)
{
    DNode *newNode = new DNode(val);

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    DNode *tail = head->prev;

    newNode->next = head;
    newNode->prev = tail;

    tail->next = newNode;
    head->prev = newNode;
}

// =============================================
// REMOVE AT HEAD
// =============================================
void CDLinkedList::removeAtHead()
{
    if (head == nullptr)
        return;

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    DNode *temp = head;
    DNode *tail = head->prev;

    head = head->next;

    head->prev = tail;
    tail->next = head;

    delete temp;
}

// =============================================
// REMOVE AT TAIL
// =============================================
void CDLinkedList::removeAtTail()
{
    if (head == nullptr)
        return;

    if (head->next == head)
    {
        delete head;
        head = nullptr;
        return;
    }

    DNode *tail = head->prev;
    DNode *newTail = tail->prev;

    newTail->next = head;
    head->prev = newTail;

    delete tail;
}

// =============================================
// REMOVE FIRST NODE CONTAINING VALUE
// =============================================
void CDLinkedList::remove(int val)
{
    if (head == nullptr)
        return;

    DNode *current = head;

    do
    {
        if (current->data == val)
        {
            // Only one node
            if (current->next == current)
            {
                delete current;
                head = nullptr;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == head)
                head = current->next;

            delete current;
            return;
        }

        current = current->next;

    } while (current != head);
}

// =============================================
// SEARCH
// =============================================
bool CDLinkedList::search(int key)
{
    if (head == nullptr)
        return false;

    DNode *current = head;

    do
    {
        if (current->data == key)
            return true;

        current = current->next;

    } while (current != head);

    return false;
}

// =============================================
// UPDATE FIRST MATCHING VALUE
// =============================================
void CDLinkedList::update(int key, int val)
{
    if (head == nullptr)
        return;

    DNode *current = head;

    do
    {
        if (current->data == key)
        {
            current->data = val;
            return;
        }

        current = current->next;

    } while (current != head);
}

// =============================================
// COUNT NODES
// =============================================
int CDLinkedList::countNodes()
{
    if (head == nullptr)
        return 0;

    int count = 0;
    DNode *current = head;

    do
    {
        count++;
        current = current->next;

    } while (current != head);

    return count;
}

// =============================================
// DISPLAY LIST
// =============================================
void CDLinkedList::display()
{
    if (head == nullptr)
    {
        cout << "List is empty." << endl;
        return;
    }

    DNode *current = head;

    do
    {
        cout << current->data << " ";
        current = current->next;

    } while (current != head);

    cout << endl;
}

// =============================================
// HELPER: REMOVE FIRST NODE WITHOUT DELETING IT
// =============================================
DNode *CDLinkedList::popFront(CDLinkedList &list)
{
    if (list.head == nullptr)
        return nullptr;

    DNode *node = list.head;

    // Only one node
    if (node->next == node)
    {
        list.head = nullptr;
    }
    else
    {
        DNode *tail = list.head->prev;

        list.head = list.head->next;
        list.head->prev = tail;
        tail->next = list.head;
    }

    // Detach the node
    node->next = nullptr;
    node->prev = nullptr;

    return node;
}

// =============================================
// HELPER: APPEND AN EXISTING NODE TO THIS LIST
// =============================================
void CDLinkedList::appendNode(DNode *node, DNode *&resultTail)
{
    if (node == nullptr)
        return;

    if (head == nullptr)
    {
        head = node;
        resultTail = node;

        node->next = node;
        node->prev = node;
    }
    else
    {
        node->prev = resultTail;
        node->next = head;

        resultTail->next = node;
        head->prev = node;

        resultTail = node;
    }
}

// =============================================
// TASK 1: MERGE TWO SORTED CIRCULAR LISTS
// =============================================
void CDLinkedList::merge(CDLinkedList &list1, CDLinkedList &list2)
{
    // Target list must initially be empty.
    DNode *resultTail = nullptr;

    // Select the smaller front node each time.
    while (list1.head != nullptr &&
           list2.head != nullptr)
    {
        if (list1.head->data <= list2.head->data)
        {
            DNode *node = popFront(list1);
            appendNode(node, resultTail);
        }
        else
        {
            DNode *node = popFront(list2);
            appendNode(node, resultTail);
        }
    }

    // Append remaining nodes from list1.
    while (list1.head != nullptr)
    {
        DNode *node = popFront(list1);
        appendNode(node, resultTail);
    }

    // Append remaining nodes from list2.
    while (list2.head != nullptr)
    {
        DNode *node = popFront(list2);
        appendNode(node, resultTail);
    }
}

// =============================================
// TASK 2: SPLIT LIST INTO TWO HALVES
// Left half receives the extra node if odd.
// =============================================
void CDLinkedList::splitList(CDLinkedList &leftHalf, CDLinkedList &rightHalf)
{
    if (head == nullptr)
        return;

    int n = countNodes();
    int leftCount = (n + 1) / 2;

    DNode *leftHead = head;
    DNode *leftTail = head;

    // Find the final node of the left half.
    for (int i = 1; i < leftCount; i++)
    {
        leftTail = leftTail->next;
    }

    // Only one node: right half stays empty.
    if (leftCount == n)
    {
        leftHalf.head = head;
        head = nullptr;
        return;
    }

    DNode *rightHead = leftTail->next;
    DNode *oldTail = head->prev;

    // Close the left circular list.
    leftTail->next = leftHead;
    leftHead->prev = leftTail;

    // Close the right circular list.
    oldTail->next = rightHead;
    rightHead->prev = oldTail;

    leftHalf.head = leftHead;
    rightHalf.head = rightHead;

    // Original list becomes empty.
    head = nullptr;
}

// =============================================
// TASK 3: COMBINE LISTS IN O(1)
// Result: list1 followed by list2
// =============================================
void CDLinkedList::combine(CDLinkedList &list1, CDLinkedList &list2)
{
    if (list1.head == nullptr && list2.head == nullptr)
    {
        head = nullptr;
    }
    else if (list1.head == nullptr)
    {
        head = list2.head;
    }
    else if (list2.head == nullptr)
    {
        head = list1.head;
    }
    else
    {
        DNode *first1 = list1.head;
        DNode *tail1 = first1->prev;

        DNode *first2 = list2.head;
        DNode *tail2 = first2->prev;

        // Connect list1's tail to list2's head.
        tail1->next = first2;
        first2->prev = tail1;

        // Connect list2's tail to list1's head.
        tail2->next = first1;
        first1->prev = tail2;

        head = first1;
    }

    // Both source lists become empty.
    list1.head = nullptr;
    list2.head = nullptr;
}

// =============================================
// TASK 3: SHUFFLE MERGE
// Alternate nodes from list1 and list2.
// Append leftovers if lengths differ.
// =============================================
void CDLinkedList::shuffleMerge(CDLinkedList &list1, CDLinkedList &list2)
{
    DNode *resultTail = nullptr;

    while (list1.head != nullptr ||
           list2.head != nullptr)
    {
        // Take a node from list1.
        if (list1.head != nullptr)
        {
            DNode *node = popFront(list1);
            appendNode(node, resultTail);
        }

        // Take a node from list2.
        if (list2.head != nullptr)
        {
            DNode *node = popFront(list2);
            appendNode(node, resultTail);
        }
    }
}


