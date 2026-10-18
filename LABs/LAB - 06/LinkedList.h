#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>

template <typename T>
class Node{

    public:

    T value;
    Node<T> *next;

    Node()
    {
        next = nullptr;
    }

    Node(T v)
    {
        value = v;
        next = nullptr;
    }
};

template <typename T>
class LinkedList{

    private:

    Node<T> *head;

    public:

    LinkedList();
    ~LinkedList();

    void insertAtHead(T v);
    void insertAtTail(T v);
    bool search(T key);
    void insertAfter(T v, T key);
    void insertBefore(T v, T key);
    void removeAtHead();
    void removeAtTail();
    void remove(T v);

    void display();
    int getSize();
    bool isEmpty();
    T getHead();
    T getTail();
    void clear();
    int count(T key);
    LinkedList<T> reversed();
};

#include "LinkedList.tpp"

#endif

