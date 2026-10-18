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



