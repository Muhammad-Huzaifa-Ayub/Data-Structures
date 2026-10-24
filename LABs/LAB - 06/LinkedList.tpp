#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
void LinkedList<T>::insertAtHead(T v)
{
    Node<T> *temp = new Node<T>(v);

    temp->next = head;
    head = temp;
}

template <typename T>
void LinkedList<T>::insertAtTail(T v)
{
    Node<T> *temp = new Node<T>(v);

    if (head == nullptr)
    {
        head = temp;
        return;
    }

    Node<T> *current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = temp;
}

template <typename T>
bool LinkedList<T>::search(T key)
{
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (temp->value == key)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

template <typename T>
void LinkedList<T>::insertAfter(T v, T key)
{
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (temp->value == key)
        {
            Node<T> *temp2 = new Node<T>(v);

            temp2->next = temp->next;
            temp->next = temp2;
            return;
        }

        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::insertBefore(T v, T key)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->value == key)
    {
        insertAtHead(v);
        return;
    }

    Node<T> *previous = head;
    Node<T> *temp = head->next;

    while (temp != nullptr)
    {
        if (temp->value == key)
        {
            Node<T> *temp2 = new Node<T>(v);

            temp2->next = temp;
            previous->next = temp2;
            return;
        }

        previous = temp;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::removeAtHead()
{
    if (head == nullptr)
    {
        return;
    }

    Node<T> *temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::removeAtTail()
{
    if (head == nullptr)
    {
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node<T> *previous = head;
    Node<T> *temp = head;

    while (temp->next != nullptr)
    {
        previous = temp;
        temp = temp->next;
    }

    previous->next = nullptr;
    delete temp;
}

template <typename T>
void LinkedList<T>::remove(T v)
{
    if (head == nullptr)
    {
        return;
    }

    if (head->value == v)
    {
        removeAtHead();
        return;
    }

    Node<T> *previous = head;
    Node<T> *temp = head->next;

    while (temp != nullptr)
    {
        if (temp->value == v)
        {
            previous->next = temp->next;
            delete temp;
            return;
        }

        previous = temp;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::display()
{
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }

    cout << endl;
}

template <typename T>
int LinkedList<T>::getSize()
{
    int count = 0;
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
T LinkedList<T>::getHead()
{
    if (head == nullptr)
    {
        return T();
    }

    return head->value;
}

template <typename T>
T LinkedList<T>::getTail()
{
    if (head == nullptr)
    {
        return T();
    }

    Node<T> *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    return temp->value;
}

template <typename T>
void LinkedList<T>::clear()
{
    while (head != nullptr)
    {
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
int LinkedList<T>::count(T key)
{
    int total = 0;
    Node<T> *temp = head;

    while (temp != nullptr)
    {
        if (temp->value == key)
        {
            total++;
        }

        temp = temp->next;
    }

    return total;
}

template <typename T>
LinkedList<T> LinkedList<T>::reversed()
{
    LinkedList<T> result;

    Node<T> *temp = head;

    while (temp != nullptr)
    {
        result.insertAtHead(temp->value);
        temp = temp->next;
    }

    return result;
}

template <typename T>
bool LinkedList<T>::moveKthNodeToFront(int k)
{
    if ( head == nullptr || k < 1 )
    {
        return false;
    }

    if ( k == 1 )
    {
        return true;
    }

    Node<T> *previous = head;
    Node<T> *current = head->next;

    int position = 2;

    while ( current != nullptr && position < k )
    {
        previous = current;
        current = current->next;
        position++;
    }

    if ( current == nullptr )
    {
        return false;
    }

    previous->next = current->next;
    current->next = head;
    head = current;

    return true;
}

template <typename T>
void LinkedList<T>::split(LinkedList<T> &list1, LinkedList<T> &list2)
{
    Node<T> *current = head;

    int position = 1;

    while (current != nullptr)
    {
        Node<T> *nextNode = current->next;

        if (position % 2 != 0)
        {
            if (list1.head == nullptr)
            {
                list1.head = current;
            }
            else
            {
                Node<T> *temp = list1.head;

                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }

                temp->next = current;
            }
        }
        else
        {
            if (list2.head == nullptr)
            {
                list2.head = current;
            }
            else
            {
                Node<T> *temp = list2.head;

                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }

                temp->next = current;
            }
        }

        current->next = nullptr;
        current = nextNode;
        position++;
    }

    head = nullptr;
}

template <typename T>
void LinkedList<T>::alternateMerge(LinkedList<T> &list1,
                                   LinkedList<T> &list2)
{
    Node<T> *first = list1.head;
    Node<T> *second = list2.head;
    Node<T> *tail = nullptr;

    while (first != nullptr && second != nullptr)
    {
        Node<T> *nextFirst = first->next;
        Node<T> *nextSecond = second->next;

        if (tail == nullptr)
        {
            head = first;
        }
        else
        {
            tail->next = first;
        }

        tail = first;
        tail->next = second;
        tail = second;

        first = nextFirst;
        second = nextSecond;
    }

    if (tail != nullptr)
    {
        tail->next = nullptr;
    }

    list1.head = nullptr;
    list2.head = nullptr;
}

template <typename T>
void LinkedList<T>::reverseList()
{
    Node<T> *previous = nullptr;
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *nextNode = current->next;

        current->next = previous;

        previous = current;
        current = nextNode;
    }

    head = previous;
}

template <typename T>
void LinkedList<T>::removeDuplicates()
{
    Node<T> *current = head;

    while (current != nullptr)
    {
        Node<T> *previous = current;
        Node<T> *temp = current->next;

        while (temp != nullptr)
        {
            if (temp->value == current->value)
            {
                previous->next = temp->next;
                delete temp;
                temp = previous->next;
            }
            else
            {
                previous = temp;
                temp = temp->next;
            }
        }

        current = current->next;
    }
}

template <typename T>
bool LinkedList<T>::removeKthNode(int k, T &val)
{
    if (k < 1 || head == nullptr)
    {
        return false;
    }

    Node<T> *current = head;

    if (k == 1)
    {
        val = current->value;
        head = head->next;
        delete current;
        return true;
    }

    Node<T> *previous = nullptr;
    int position = 1;

    while (current != nullptr && position < k)
    {
        previous = current;
        current = current->next;
        position++;
    }

    if (current == nullptr)
    {
        return false;
    }

    val = current->value;
    previous->next = current->next;
    delete current;

    return true;
}

template <typename T>
void LinkedList<T>::combine(LinkedList<T> &list1,LinkedList<T> &list2)
{
    if (list1.head == nullptr)
    {
        head = list2.head;
    }
    else
    {
        head = list1.head;

        Node<T> *current = list1.head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = list2.head;
    }

    list1.head = nullptr;
    list2.head = nullptr;
}

