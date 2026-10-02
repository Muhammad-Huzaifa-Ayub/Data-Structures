#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename T>
class Stack {

private:

    T *data;
    int capacity;
    int top;

public:

    Stack(int c = 1);
    Stack(const Stack &ref);
    Stack &operator=(const Stack &ref);
    ~Stack();
    void push(T e);
    T pop();
    T peek() const;
    bool isEmpty() const;
    int size() const;
    void clear();
    bool isFull() const;
    int GetCapacity() const;
    void reSize();
    void display() const;
    Stack reverse();
    bool contains(const T e) const;
    void sort() const;

};

#include "Stack.tpp"
#endif

