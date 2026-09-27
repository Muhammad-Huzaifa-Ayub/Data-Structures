#include "Stack.h"

template <typename T>
Stack<T>::Stack( int c )
{
    if ( c <= 0 )
    {
        cout <<"Invalid Capacity\n";
        exit(0);
    }
    capacity = c;
    data = new T[capacity];
    top = 0;
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    if ( top == 0 )
    {
        return true;
    }
    return false;
}

template <typename T>
void Stack<T>::push( T e)
{
    if ( isFull() )
    {
        reSize();
    }
    data[top] = e;
    top++;
}

template <typename T>
T Stack<T>::pop()
{
    if ( isEmpty() )
    {
        cout << "Stack is Empty\n";
        exit(0);
    }

    top--;
    return data[top];
}

template <typename T>
int Stack<T>::size() const
{
    return top;
}

template <typename T>
T Stack<T>::peek() const
{
    if ( isEmpty() )
    {
        cout << "Stack is Empty\n";
        exit(0);
    }
    return data[top - 1];
}

template <typename T>
void Stack<T>::clear()
{
    top = 0;
}

template <typename T>
Stack<T>::Stack(const Stack &ref)
{
    capacity = ref.capacity;
    top = ref.top;

    data = nullptr;
    data = new T[capacity];

    for ( int i = 0; i < top; i++ )
    {
        data[i] = ref.data[i];
    }
}

template <typename T>
Stack<T>::~Stack()
{   
    delete[] data;
    data = nullptr;
}

template <typename T>
Stack<T> &Stack<T>::operator = ( const Stack<T> &ref)
{
    if ( this == &ref )
    {
        return *this;
    }

    capacity = ref.capacity;
    top = ref.top;

    delete[] data;
    data = new T[capacity];

    for ( int i = 0; i < top; i++ )
    {
        data[i] = ref.data[i];
    }

    return *this;
}

template <typename T>
bool Stack<T>::isFull() const
{
    return capacity == top;
}

template <typename T>
int Stack<T>::GetCapacity() const
{
    return capacity;
}

template <typename T>
void Stack<T>::reSize()
{
    if ( isFull() )
    {
        int newCapacity = 2 * capacity;
        capacity = newCapacity;

        T *temp = new T[newCapacity];

        for ( int i = 0; i < top; i++ )
        {
            temp[i] = data[i];
        }

        delete[] data;
        data = temp;

    }
}

template <typename T>
void Stack<T>::display() const
{
    for ( int i = 0; i < top; i++ )
    {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <typename T>
Stack<T> Stack<T>::reverse()
{
    Stack<T> tempStack(capacity);

    for ( int i = top - 1; i >= 0; i-- )
    {
        tempStack.push(data[i]);
    }

    return tempStack;
}

template <typename T>
bool Stack<T>::contains( const T e ) const
{
    for ( int i = 0; i < top; i++ )
    {
        if ( data[i] == e )
        {
            return true;
        }
    }

    return false;
}

template <typename T>
void Stack<T>::sort() const
{
    for ( int i = 0; i < top -1; i++ )
    {
        for ( int j = 0; j < top -1; j++ )
        {
            if ( data[j] < data[j+1])
            {
                swap(data[j],data[j+1]);
            }
        }   
    }
}