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

};

#include "CDLinkedList.cpp"

#endif
