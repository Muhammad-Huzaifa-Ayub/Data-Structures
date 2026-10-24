#ifndef CDLINKEDLIST_H
#define CDLINKEDLIST_H

#include<iostream>

using namespace std;

class DNode
{
public:
    int data;
    DNode *next;
    DNode *prev;

    DNode(int val);
};

class CDLinkedList
{
private:
    DNode *head;

public:

    CDLinkedList();
    ~CDLinkedList();
    void insertAtHead(int val);
    void insertAtTail(int val);
    void removeAtHead();
    void removeAtTail();
    void remove(int val);
    bool search(int key);
    void update(int key, int val);
    int countNodes();
    void display();

    DNode *popFront(CDLinkedList &list);
    void appendNode(DNode *node, DNode *&resultTail);
    void merge(CDLinkedList &list1, CDLinkedList &list2);
    void splitList(CDLinkedList &leftHalf, CDLinkedList &rightHalf);
    void combine(CDLinkedList &list1, CDLinkedList &list2);
    void shuffleMerge(CDLinkedList &list1, CDLinkedList &list2);
    
};

#include "CDLinkedList.cpp"

#endif
