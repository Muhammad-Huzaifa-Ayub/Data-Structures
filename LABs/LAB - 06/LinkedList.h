#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>

using namespace std;

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
    bool moveKthNodeToFront(int k);
    void split(LinkedList<T> &list1, LinkedList<T> &list2) ;
    void alternateMerge(LinkedList<T> &list1, LinkedList<T> &list2);
    void reverseList();
    void removeDuplicates();
    bool removeKthNode(int k, T &val);
    void combine(LinkedList<T> &list1, LinkedList<T> &list2);

};

#include "LinkedList.tpp"

#endif

