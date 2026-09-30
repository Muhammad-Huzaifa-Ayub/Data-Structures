template <typename T>
Queue<T>::Queue(int c)
{
    if (c <= 0)
    {
        cout << "Invalid Capacity\n";
        exit(0);
    }

    data = new T[c];

    capacity = c;
    NoOfElements = 0;
    frontIndex = -1;
    rear = -1;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &ref)
{
    capacity = ref.capacity;
    NoOfElements = ref.NoOfElements;
    frontIndex = ref.frontIndex;
    rear = ref.rear;

    data = new T[capacity];

    for (int i = 0; i < capacity; i++)
    {
        data[i] = ref.data[i];
    }
}

template <typename T>
Queue<T> &Queue<T>::operator = (const Queue<T> &ref)
{
    if (this == &ref)
    {
        return *this;
    }

    delete[] data;

    capacity = ref.capacity;
    NoOfElements = ref.NoOfElements;
    frontIndex = ref.frontIndex;
    rear = ref.rear;

    data = new T[capacity];

    for (int i = 0; i < capacity; i++)
    {
        data[i] = ref.data[i];
    }

    return *this;
}

template <typename T>
Queue<T>::~Queue()
{
    delete[] data;
    data = nullptr;
}

template <typename T>
void Queue<T>::enqueue(const T &v)
{
    if (isFull())
    {
        reSize();
    }

    rear = (rear + 1) % capacity;
    data[rear] = v;
    NoOfElements++;
}

template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        exit(0);
    }

    frontIndex = (frontIndex + 1) % capacity;

    T value = data[frontIndex];

    NoOfElements--;

    if (NoOfElements == 0)
    {
        frontIndex = -1;
        rear = -1;
    }

    return value;
}

template <typename T>
T Queue<T>::front() const
{
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        exit(0);
    }

    return data[(frontIndex + 1) % capacity];
}

template <typename T>
bool Queue<T>::isEmpty() const
{
    return NoOfElements == 0;
}

template <typename T>
bool Queue<T>::isFull() const
{
    return NoOfElements == capacity;
}

template <typename T>
int Queue<T>::size() const
{
    return NoOfElements;
}

template <typename T>
int Queue<T>::GetCapacity() const
{
    return capacity;
}

template <typename T>
void Queue<T>::clear()
{
    NoOfElements = 0;
    frontIndex = -1;
    rear = -1;
}

template <typename T>
void Queue<T>::reSize()
{
    int newCapacity = capacity * 2;

    T *temp = new T[newCapacity];

    for (int i = 0; i < NoOfElements; i++)
    {
        int index = (frontIndex + 1 + i) % capacity;
        temp[i] = data[index];
    }

    delete[] data;

    data = temp;
    capacity = newCapacity;

    if (NoOfElements == 0)
    {
        frontIndex = -1;
        rear = -1;
    }
    else
    {
        frontIndex = -1;
        rear = NoOfElements - 1;
    }
}

template <typename T>
void Queue<T>::display() const
{
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        return;
    }

    for (int i = 0; i < NoOfElements; i++)
    {
        int index = (frontIndex + 1 + i) % capacity;

        cout << data[index] << " ";
    }

    cout << endl;
}

template <typename T>
bool Queue<T>::contains(const T &v) const
{
    for (int i = 0; i < NoOfElements; i++)
    {
        int index = (frontIndex + 1 + i) % capacity;

        if (data[index] == v)
        {
            return true;
        }
    }

    return false;
}

template <typename T>
T Queue<T>::back() const
{
    if (isEmpty())
    {
        cout << "Queue is Empty\n";
        exit(0);
    }

    return data[rear];
}