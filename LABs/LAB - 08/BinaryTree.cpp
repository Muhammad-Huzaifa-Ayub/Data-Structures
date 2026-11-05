#include "BinaryTree.h"

BinaryTree::BinaryTree(int h)
{
    height= h;
    capacity = pow(2, height) - 1;
    data = new int[capacity];
    status = new bool[capacity];

    for ( int i = 0; i < capacity; i++ )
    {
        status[i] = 0;
        data[i] = 0;
    }
}

BinaryTree::BinaryTree(const BinaryTree &obj)
{
    height = obj.height;
    capacity = obj.capacity;

    data = new int[capacity];
    status = new bool[capacity];

    for (int i = 0; i < capacity; i++)
    {
        data[i] = obj.data[i];
        status[i] = obj.status[i];
    }
}

BinaryTree &BinaryTree::operator = (const BinaryTree &obj)
{
    if (this == &obj)
    {
        return *this;
    }

    delete[] data;
    delete[] status;

    height = obj.height;
    capacity = obj.capacity;

    data = new int[capacity];
    status = new bool[capacity];

    for (int i = 0; i < capacity; i++)
    {
        data[i] = obj.data[i];
        status[i] = obj.status[i];
    }

    return *this;
}

BinaryTree::~BinaryTree()
{
    delete[] data;
    delete[] status;
}

void BinaryTree::SetLeftChild(int p, int n)
{
    for ( int i = 0; i < capacity; i++ )
    {
        if ( data[i] == p && status[i] == 1 && ((2 * i) + 1) < capacity && status[(2 * i) + 1] == 0 )
        {
            data[(2 * i) + 1] = n;
            status[(2 * i) + 1] = 1;
            break;
        }
    }
}

void BinaryTree::SetRightChild(int p, int n)
{
    for ( int i = 0; i < capacity; i++ )
    {
        if ( data[i] == p && status[i] == 1 && ((2 * i) + 2) < capacity && status[(2 * i) + 2] == 0 )
        {
            data[(2 * i) + 2] = n;
            status[(2 * i) + 2] = 1;
            break;
        }
    }
}

void BinaryTree::SetRoot(int r)
{
    if ( status[0] == 0 )
    {
        data[0] = r;
        status[0] = 1;
    }
    else
    {
        cout << "\nRoot is already set...\n";
    }
}

int BinaryTree::getParent(int n) const
{
    for ( int i = 1; i < capacity; i++ )
    {
        if ( data[i] == n && status[i] == 1 )
        {
            int parent = (i - 1) / 2;

            if ( status[parent] == 1 )
            {
                return data[parent];
            }
        }
    }
    cout << "\nThe Parent of Node = " << n << " does n't exist...\n";

    return 0;
}

int BinaryTree::getRoot() const
{
    if ( status[0] == 1 )
    {
        return data[0];
    }
    else
    {
        cout << "\nRoot does n't exist...\n";
        return 0;
    }
}

void BinaryTree::LevelOrderPrint()
{
    cout << "Level Order Print : ";
    for ( int i = 0; i < capacity; i++ )
    {
        if ( status[i] == 1 )
        {
            cout << data[i] << " ";
        }
    }
    cout << "\n";
}

void BinaryTree::PreOrder(int i)
{
    if ( i >= capacity || status[i] == 0 )
    {
        return;
    }

    cout << data[i] << " ";

    PreOrder((2 * i) + 1);
    PreOrder((2 * i) + 2);

}

void BinaryTree::PreOrderPrint()
{
    cout << "Pre-Order Print : ";
    if ( status[0] == 1 )
    {
        PreOrder(0);
    }
    cout << "\n";
}

void BinaryTree::PostOrder(int i)
{
    if (i >= capacity || status[i] == 0)
    {
        return;
    }

    PostOrder((2 * i) + 1);
    PostOrder((2 * i) + 2);
    cout << data[i] << " ";
}

void BinaryTree::PostOrderPrint()
{
    cout << "Post-Order Print : ";
    if (status[0] == 1)
    {
        PostOrder(0);
    }
    cout << "\n";
}

void BinaryTree::InOrder(int i)
{
    if (i >= capacity || status[i] == 0)
    {
        return;
    }

    InOrder((2 * i) + 1);
    cout << data[i] << " ";
    InOrder((2 * i) + 2);
}

void BinaryTree::InOrderPrint()
{
    cout << "In-Order Print : ";
    if (status[0] == 1)
    {
        InOrder(0);
    }
    cout << "\n";
}

int BinaryTree::getActualheight(int i)
{
    if (i >= capacity || status[i] == 0)
    {
        return 0;
    }

    int l = getActualheight((2 * i) + 1);
    int r = getActualheight((2 * i) + 2);

    if (l > r)
    {
        return l + 1;
    }
    else
    {
        return r + 1;
    }
}

int BinaryTree::getActualheight()
{
    if ( status[0] == 1 )
    {
        return getActualheight(0);
    }

    return 0;
}

int BinaryTree::getLeftChild(int p)
{
    for (int i = 0; i < capacity; i++)
    {
        if (data[i] == p && status[i] == 1 && ((2 * i) + 1) < capacity && status[(2 * i) + 1] == 1)
        {
            return data[(2 * i) + 1];
        }
    }
    cout << "\nThe Left-child of Node = " << p << " does n't exist...\n";
    return 0;
}

int BinaryTree::getRightChild(int p)
{
    for (int i = 0; i < capacity; i++)
    {
        if (data[i] == p && status[i] == 1 && ((2 * i) + 2) < capacity && status[(2 * i) + 2] == 1)
        {
            return data[(2 * i) + 2];
        }
    }
    cout << "\nThe Right-child of Node = " << p << " does n't exist...\n";

    return 0;
}

int BinaryTree::getIndex(int node)
{
    for ( int i = 0; i < capacity; i++ )
    {
        if ( data[i] == node && status[i] == 1 )
        {
            return i;
        }
    }
    cout << "\nThe Node = " << node << ", does n't exist...\n";

    return -1;
}

void BinaryTree::remove(int index)
{
    if ( index < 0 || index >= capacity || status[index] == 0 )
    {
        return;
    }

    data[index] = 0;
    status[index] = 0;

    remove((2 * index) + 1);
    remove((2 * index) + 2);
}

void BinaryTree::removeNode(int node)
{
    int index = getIndex(node);

    if ( index == -1 )
    {
        return;
    }

    remove(index);
}

void BinaryTree::Ancestors(int index)
{
    if (index <= 0 || index >= capacity)
    {
        return;
    }

    int parentIndex = (index - 1) / 2;

    if (status[parentIndex] == 0)
    {
        return;
    }

    cout << data[parentIndex] << " ";

    Ancestors(parentIndex);
}

void BinaryTree::displayAncestors(int node)
{
    int index = getIndex(node);

    if (index == -1)
    {
        return;
    }

    cout << "All Ancestors are : ";

    Ancestors(index);

    cout << "\n";
}

void BinaryTree::Descendents(int index)
{
    if ( index < 0 || index >= capacity || status[index] == 0 )
    {
        return;
    }

    cout << data[index] << " ";

    Descendents((2 * index) + 1);
    Descendents((2 * index) + 2);
}

void BinaryTree::displayDescendents(int node)
{
    int index = getIndex(node);

    if ( index == -1 )
    {
        return;
    }

    cout << "All Descendents are : ";

    Descendents((2 * index) + 1);
    Descendents((2 * index) + 2);

    cout << "\n";
}

int BinaryTree::findLevelOfNode(int node)
{
    int index = getIndex(node);

    if (index == -1)
    {
        return -1;
    }

    int level = 0;

    while (index != 0)
    {
        index = (index - 1) / 2;
        level++;
    }

    return level;
}

void BinaryTree::displayLevel(int index, int currentLevel, int levelNo)
{
    if (index >= capacity || status[index] == 0)
    {
        return;
    }

    if (currentLevel == levelNo)
    {
        cout << data[index] << " ";
        return;
    }

    displayLevel((2 * index) + 1, currentLevel + 1, levelNo);
    displayLevel((2 * index) + 2, currentLevel + 1, levelNo);
}

void BinaryTree::displayLevel(int levelNo)
{
    if (levelNo < 0)
    {
        cout << "Invalid level...\n";
        return;
    }

    cout << "Nodes at Level " << levelNo << " : ";

    if (status[0] == 1)
    {
        displayLevel(0, 0, levelNo);
    }

    cout << "\n";
}

void BinaryTree::ParenthesizedView(int index)
{
    if (index >= capacity || status[index] == 0)
    {
        return;
    }

    cout << data[index];

    int left = (2 * index) + 1;
    int right = (2 * index) + 2;

    if ((left < capacity && status[left] == 1) ||
        (right < capacity && status[right] == 1))
    {
        cout << "(";

        if (left < capacity && status[left] == 1)
        {
            ParenthesizedView(left);
        }

        if (right < capacity && status[right] == 1)
        {
            cout << ",";
            ParenthesizedView(right);
        }

        cout << ")";
    }
}

void BinaryTree::displayParenthesizedView()
{
    cout << "Parenthesized View : ";

    if (status[0] == 1)
    {
        ParenthesizedView(0);
    }

    cout << "\n";
}


