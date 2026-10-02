#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class Queue{

private:

    T *data;
    int capacity;
    int NoOfElements;
    int frontIndex;
    int rear;

public:

    Queue(int c = 1);
    Queue(const Queue<T> &ref);
    Queue<T> &operator = (const Queue<T> &ref);
    ~Queue();
    void enqueue(const T &v);
    T dequeue();
    T front() const;
    T back() const;
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    int GetCapacity() const;
    void clear();
    void display() const;
    bool contains(const T &v) const;
    void reSize();
};

#include "Queue.tpp"

#endif