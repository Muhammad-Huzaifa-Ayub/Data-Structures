#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree(int h)
{
    height = h;
    capacity = (h > 0) ? (pow(2, h) - 1) : 0;

    data = new T[capacity];
    status = new bool[capacity];

    for (int i = 0; i < capacity; i++)
    {
        status[i] = false;
        data[i] = T();
    }
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &obj)
{
    height = obj.height;
    capacity = obj.capacity;

    data = new T[capacity];
    status = new bool[capacity];

    for (int i = 0; i < capacity; i++)
    {
        data[i] = obj.data[i];
        status[i] = obj.status[i];
    }
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator=(const BinaryTree<T> &obj)
{
    if (this == &obj)
        return *this;

    T *newData = new T[obj.capacity];
    bool *newStatus = new bool[obj.capacity];

    for (int i = 0; i < obj.capacity; i++)
    {
        newData[i] = obj.data[i];
        newStatus[i] = obj.status[i];
    }

    delete[] data;
    delete[] status;

    data = newData;
    status = newStatus;

    height = obj.height;
    capacity = obj.capacity;

    return *this;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete[] data;
    delete[] status;
}

template <typename T>
void BinaryTree<T>::SetLeftChild(T p, T n)
{
    for (int i = 0; i < capacity; i++)
    {
        int left = (2 * i) + 1;

        if (data[i] == p && status[i] == true &&
            left < capacity && status[left] == false)
        {
            data[left] = n;
            status[left] = true;
            break;
        }
    }
}

template <typename T>
void BinaryTree<T>::SetRightChild(T p, T n)
{
    for (int i = 0; i < capacity; i++)
    {
        int right = (2 * i) + 2;

        if (data[i] == p && status[i] == true &&
            right < capacity && status[right] == false)
        {
            data[right] = n;
            status[right] = true;
            break;
        }
    }
}

template <typename T>
void BinaryTree<T>::SetRoot(T r)
{
    if (capacity == 0)
        return;

    if (status[0] == false)
    {
        data[0] = r;
        status[0] = true;
    }
    else
    {
        cout << "\nRoot is already set...\n";
    }
}

template <typename T>
T BinaryTree<T>::getParent(T n) const
{
    for (int i = 1; i < capacity; i++)
    {
        if (data[i] == n && status[i] == true)
        {
            int parent = (i - 1) / 2;

            if (status[parent] == true)
                return data[parent];
        }
    }

    cout << "\nThe Parent of Node = " << n
         << " does not exist...\n";

    return T();
}

template <typename T>
T BinaryTree<T>::getRoot() const
{
    if (capacity > 0 && status[0] == true)
        return data[0];

    cout << "\nRoot does not exist...\n";
    return T();
}

template <typename T>
void BinaryTree<T>::LevelOrderPrint()
{
    cout << "Level Order Print : ";

    for (int i = 0; i < capacity; i++)
    {
        if (status[i] == true)
            cout << data[i] << " ";
    }

    cout << "\n";
}

template <typename T>
void BinaryTree<T>::PreOrder(int i)
{
    if (i >= capacity || status[i] == false)
        return;

    cout << data[i] << " ";

    PreOrder((2 * i) + 1);
    PreOrder((2 * i) + 2);
}

template <typename T>
void BinaryTree<T>::PreOrderPrint()
{
    cout << "Pre-Order Print : ";

    if (capacity > 0 && status[0] == true)
        PreOrder(0);

    cout << "\n";
}

template <typename T>
void BinaryTree<T>::PostOrder(int i)
{
    if (i >= capacity || status[i] == false)
        return;

    PostOrder((2 * i) + 1);
    PostOrder((2 * i) + 2);

    cout << data[i] << " ";
}

template <typename T>
void BinaryTree<T>::PostOrderPrint()
{
    cout << "Post-Order Print : ";

    if (capacity > 0 && status[0] == true)
        PostOrder(0);

    cout << "\n";
}

template <typename T>
void BinaryTree<T>::InOrder(int i)
{
    if (i >= capacity || status[i] == false)
        return;

    InOrder((2 * i) + 1);

    cout << data[i] << " ";

    InOrder((2 * i) + 2);
}

template <typename T>
void BinaryTree<T>::InOrderPrint()
{
    cout << "In-Order Print : ";

    if (capacity > 0 && status[0] == true)
        InOrder(0);

    cout << "\n";
}

template <typename T>
int BinaryTree<T>::getActualheight(int i)
{
    if (i >= capacity || status[i] == false)
        return 0;

    int l = getActualheight((2 * i) + 1);
    int r = getActualheight((2 * i) + 2);

    return (l > r) ? l + 1 : r + 1;
}

template <typename T>
int BinaryTree<T>::getActualheight()
{
    if (capacity > 0 && status[0] == true)
        return getActualheight(0);

    return 0;
}

template <typename T>
T BinaryTree<T>::getLeftChild(T p)
{
    for (int i = 0; i < capacity; i++)
    {
        int left = (2 * i) + 1;

        if (data[i] == p && status[i] == true &&
            left < capacity && status[left] == true)
        {
            return data[left];
        }
    }

    cout << "\nThe Left-child of Node = " << p
         << " does not exist...\n";

    return T();
}

template <typename T>
T BinaryTree<T>::getRightChild(T p)
{
    for (int i = 0; i < capacity; i++)
    {
        int right = (2 * i) + 2;

        if (data[i] == p && status[i] == true &&
            right < capacity && status[right] == true)
        {
            return data[right];
        }
    }

    cout << "\nThe Right-child of Node = " << p
         << " does not exist...\n";

    return T();
}

template <typename T>
int BinaryTree<T>::getIndex(T node)
{
    for (int i = 0; i < capacity; i++)
    {
        if (data[i] == node && status[i] == true)
            return i;
    }

    cout << "\nThe Node = " << node
         << " does not exist...\n";

    return -1;
}

template <typename T>
void BinaryTree<T>::remove(int index)
{
    if (index < 0 || index >= capacity || status[index] == false)
        return;

    data[index] = T();
    status[index] = false;

    remove((2 * index) + 1);
    remove((2 * index) + 2);
}

template <typename T>
void BinaryTree<T>::removeNode(T node)
{
    int index = getIndex(node);

    if (index == -1)
        return;

    remove(index);
}

template <typename T>
void BinaryTree<T>::Ancestors(int index)
{
    if (index <= 0 || index >= capacity)
        return;

    int parentIndex = (index - 1) / 2;

    if (status[parentIndex] == false)
        return;

    cout << data[parentIndex] << " ";

    Ancestors(parentIndex);
}

template <typename T>
void BinaryTree<T>::displayAncestors(T node)
{
    int index = getIndex(node);

    if (index == -1)
        return;

    cout << "All Ancestors are : ";

    Ancestors(index);

    cout << "\n";
}

template <typename T>
void BinaryTree<T>::Descendents(int index)
{
    if (index < 0 || index >= capacity || status[index] == false)
        return;

    cout << data[index] << " ";

    Descendents((2 * index) + 1);
    Descendents((2 * index) + 2);
}

template <typename T>
void BinaryTree<T>::displayDescendents(T node)
{
    int index = getIndex(node);

    if (index == -1)
        return;

    cout << "All Descendents are : ";

    Descendents((2 * index) + 1);
    Descendents((2 * index) + 2);

    cout << "\n";
}

template <typename T>
int BinaryTree<T>::findLevelOfNode(T node)
{
    int index = getIndex(node);

    if (index == -1)
        return -1;

    int level = 0;

    while (index != 0)
    {
        index = (index - 1) / 2;
        level++;
    }

    return level;
}

template <typename T>
void BinaryTree<T>::displayLevel(int index, int currentLevel, int levelNo)
{
    if (index >= capacity || status[index] == false)
        return;

    if (currentLevel == levelNo)
    {
        cout << data[index] << " ";
        return;
    }

    displayLevel((2 * index) + 1, currentLevel + 1, levelNo);
    displayLevel((2 * index) + 2, currentLevel + 1, levelNo);
}

template <typename T>
void BinaryTree<T>::displayLevel(int levelNo)
{
    if (levelNo < 0)
    {
        cout << "Invalid level...\n";
        return;
    }

    cout << "Nodes at Level " << levelNo << " : ";

    if (capacity > 0 && status[0] == true)
        displayLevel(0, 0, levelNo);

    cout << "\n";
}

template <typename T>
void BinaryTree<T>::ParenthesizedView(int index)
{
    if (index >= capacity || status[index] == false)
        return;

    cout << data[index];

    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if ((left < capacity && status[left] == true) ||
        (right < capacity && status[right] == true))
    {
        cout << "(";

        if (left < capacity && status[left] == true)
            ParenthesizedView(left);

        if (right < capacity && status[right] == true)
        {
            cout << ",";
            ParenthesizedView(right);
        }

        cout << ")";
    }
}

template <typename T>
void BinaryTree<T>::displayParenthesizedView()
{
    cout << "Parenthesized View : ";

    if (capacity > 0 && status[0] == true)
        ParenthesizedView(0);

    cout << "\n";
}
