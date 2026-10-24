#include "CDLinkedList.h"

// DNode constructor
DNode::DNode(int val)
{
    data = val;
    next = nullptr;
    prev = nullptr;
}

// Default constructor
CDLinkedList::CDLinkedList()
{
    head = nullptr;
}

// Destructor
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

// Insert at head
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

// Insert at tail
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

// Remove at head
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

// Remove at tail
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

// Remove the first node containing val
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

// Search for a value
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

// Update the first matching key
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

// Count nodes
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

// Display the list (extra helper)
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
