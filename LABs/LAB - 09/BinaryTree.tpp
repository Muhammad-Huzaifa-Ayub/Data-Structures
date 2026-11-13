#include "BinaryTree.h"

template <typename T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template <typename T>
Node<T>* BinaryTree<T>::copyTree(Node<T> *r)
{
    if (r == nullptr)
    {
        return nullptr;
    }

    Node<T> *temp = new Node<T>(r->info);

    temp->left = copyTree(r->left);
    temp->right = copyTree(r->right);

    return temp;
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &other)
{
    root = copyTree(other.root);
}

template <typename T>
BinaryTree<T> &BinaryTree<T>::operator = (const BinaryTree<T> &other)
{
    if (this == &other)
    {
        return *this;
    }

    Node<T> *newRoot = copyTree(other.root);

    destroyTree(root);

    root = newRoot;

    return *this;
}

template <typename T>
void BinaryTree<T>::setRoot(T d)
{
    if ( !root)
    {
        root = new Node<T>(d);
        return;
    }
    else
    {
        root->info = d;
    }
}

template <typename T>
T BinaryTree<T>::getRoot()
{
    if ( root == nullptr )
    {
        cout << "Root does n't exist...\n";
        return T{};
    }
    
    return root->info;
}

template <typename T>
void BinaryTree<T>::destroyTree(Node<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    destroyTree(r->left);
    destroyTree(r->right);

    delete r;
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    destroyTree(root);
}

template <typename T>
Node<T>* BinaryTree<T>::findNode(Node<T> *r, T v)
{
    if (r == nullptr)
    {
        return nullptr;
    }
    if (r->info == v)
    {
        return r;
    }
    Node<T> *l = findNode(r->left, v);
    if (l != nullptr)
    {
        return l;
    }

    return findNode(r->right, v);
}

template <typename T>
void BinaryTree<T>::setLeftChild(T p, T n)
{
    Node<T> *t =  findNode(root,p);
    if ( t == nullptr )
    {
        cout << "The Node [" << p << "] does n't exist...\n";
        return;
    }
    if ( t != nullptr && t->left == nullptr )
    {
        t->left = new Node<T>(n);
    }
}

template <typename T>
void BinaryTree<T>::setRightChild(T p, T n)
{
    Node<T> *t = findNode(root, p);
    if (t == nullptr)
    {
        cout << "The Node [" << p << "] does n't exist...\n";
        return;
    }
    if (t != nullptr && t->right == nullptr)
    {
        t->right = new Node<T>(n);
    }
}

template <typename T>
Node<T>* BinaryTree<T>::findParent(Node<T> *r, T node)
{
    if (r == nullptr)
    {
        return nullptr;
    }

    if ((r->left != nullptr && r->left->info == node) || (r->right != nullptr && r->right->info == node))
    {
        return r;
    }

    Node<T> *temp = findParent(r->left, node);

    if (temp != nullptr)
    {
        return temp;
    }

    return findParent(r->right, node);
}

template <typename T>
void BinaryTree<T>::setParent(T p, T node)
{
    Node<T> *t = findParent(root, p);

    if (t == nullptr)
    {
        cout << "Parent does n't exist...\n";
        return;
    }

    t->info = node;
}

template <typename T>
T BinaryTree<T>::getParent(T node)
{
    Node<T> *t = findParent(root, node);

    if (t == nullptr)
    {
        cout << "Parent does n't exist...\n";
        return T{};
    }

    return t->info;
}

template <typename T>
void BinaryTree<T>::PreOrder(Node<T> *r)
{
    if ( r == nullptr )
    {
        return;
    }

    cout << r->info << " ";
    PreOrder(r->left);
    PreOrder(r->right);

}

template <typename T>
void BinaryTree<T>::PreOrderPrint()
{
    if ( root == nullptr )
    {
        cout << "Root does n't exist...\n";
        return;
    }

    PreOrder(root);

}

template <typename T>
void BinaryTree<T>::PostOrder(Node<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    PostOrder(r->left);
    PostOrder(r->right);
    cout << r->info << " ";

}

template <typename T>
void BinaryTree<T>::PostOrderPrint()
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return;
    }

    PostOrder(root);
}

template <typename T>
void BinaryTree<T>::InOrder(Node<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    InOrder(r->left);
    cout << r->info << " ";
    InOrder(r->right);
}

template <typename T>
void BinaryTree<T>::InOrderPrint()
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return;
    }

    InOrder(root);
}

template <typename T>
void BinaryTree<T>::LevelOrder(Node<T> *r)
{
    queue<Node<T>*> q;

    q.push(r);
    while ( !q.empty() )
    {
        Node<T> *t = q.front();
        q.pop();
        cout << t->info << " ";
        if ( t->left != nullptr )
        {
            q.push(t->left);
        }
        if (t->right != nullptr)
        {
            q.push(t->right);
        }
    }
}

template <typename T>
void BinaryTree<T>::LevelOrderPrint()
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return;
    }

    LevelOrder(root);
}

template <typename T>
Node<T>* BinaryTree<T>::findParentPointer(Node<T> *r, Node<T> *target)
{
    if (r == nullptr)
    {
        return nullptr;
    }

    if (r->left == target || r->right == target)
    {
        return r;
    }

    Node<T> *temp = findParentPointer(r->left, target);

    if (temp != nullptr)
    {
        return temp;
    }

    return findParentPointer(r->right, target);
}

template <typename T>
void BinaryTree<T>::remove(T node)
{
    Node<T> *t = findNode(root, node);

    if (t == nullptr)
    {
        cout << "The Node [" << node << "] does n't exist...\n";
        return;
    }

    if (t == root)
    {
        root = nullptr;
        destroyTree(t);
        return;
    }

    Node<T> *p = findParentPointer(root, t);

    if (p == nullptr)
    {
        return;
    }

    if (p->left == t)
    {
        p->left = nullptr;
    }
    else if (p->right == t)
    {
        p->right = nullptr;
    }

    destroyTree(t);
}

template <typename T>
T BinaryTree<T>::findNodeSiblings(T node)
{
    Node<T> *t = findParent(root, node);

    if (t == nullptr)
    {
        cout << "Parent does n't exist...\n";
        return T{};
    }

    if (t->left != nullptr && t->left->info == node)
    {
        if (t->right == nullptr)
        {
            cout << "The Node [" << node << "] has no Siblings...\n";
            return T{};
        }

        return t->right->info;
    }
    else if (t->right != nullptr && t->right->info == node)
    {
        if (t->left == nullptr)
        {
            cout << "The Node [" << node << "] has no Siblings...\n";
            return T{};
        }

        return t->left->info;
    }

    return T{};
}

template <typename T>
bool BinaryTree<T>::isInternalNode(T node)
{
    Node<T> *t = findNode(root, node);

    if (t == nullptr)
    {
        return false;
    }

    return (t->left != nullptr || t->right != nullptr);
}

template <typename T>
bool BinaryTree<T>::isExternalNode(T node)
{
    Node<T> *t = findNode(root, node);

    if (t == nullptr)
    {
        return false;
    }

    return (t->left == nullptr && t->right == nullptr);
}

template <typename T>
int BinaryTree<T>::countNodes(Node<T> *r)
{
    if (r == nullptr)
    {
        return 0;
    }

    return 1 + countNodes(r->left) + countNodes(r->right);
}

template <typename T>
int BinaryTree<T>::countNodes()
{
    return countNodes(root);
}

template <typename T>
int BinaryTree<T>::countInternals(Node<T> *r)
{
    if (r == nullptr)
    {
        return 0;
    }

    int count = 0;

    if (r->left != nullptr || r->right != nullptr)
    {
        count = 1;
    }

    return count + countInternals(r->left) + countInternals(r->right);
}

template <typename T>
int BinaryTree<T>::countInternalNodes()
{
    if (root == nullptr)
    {
        return 0;
    }

    return countInternals(root);
}

template <typename T>
int BinaryTree<T>::countExternals(Node<T> *r)
{
    if (r == nullptr)
    {
        return 0;
    }

    if (r->left == nullptr && r->right == nullptr)
    {
        return 1;
    }

    return countExternals(r->left) + countExternals(r->right);
}

template <typename T>
int BinaryTree<T>::countExternalNodes()
{
    if (root == nullptr)
    {
        return 0;
    }

    return countExternals(root);
}

template <typename T>
int BinaryTree<T>::height(Node<T> *r)
{
    if (r == nullptr)
    {
        return -1;
    }

    int leftHeight = height(r->left);
    int rightHeight = height(r->right);

    if (leftHeight > rightHeight)
    {
        return 1 + leftHeight;
    }
    else
    {
        return 1 + rightHeight;
    }
}

template <typename T>
void BinaryTree<T>::getHeight()
{
    cout << "Height of Tree: " << height(root) << endl;
}

template <typename T>
void BinaryTree<T>::Parenthesized(Node<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    cout << r->info;

    if (r->left != nullptr || r->right != nullptr)
    {
        cout << "(";

        if (r->left != nullptr)
        {
            Parenthesized(r->left);
        }

        cout << ",";

        if (r->right != nullptr)
        {
            Parenthesized(r->right);
        }

        cout << ")";
    }
}

template <typename T>
void BinaryTree<T>::displayParenthesizedView()
{
    if (root == nullptr)
    {
        cout << "Tree is empty...\n";
        return;
    }

    Parenthesized(root);
    cout << endl;
}

template <typename T>
Node<T> *BinaryTree<T>::mirrorTree(Node<T> *r)
{
    if (r == nullptr)
    {
        return nullptr;
    }

    Node<T> *temp = new Node<T>(r->info);

    temp->left = mirrorTree(r->right);
    temp->right = mirrorTree(r->left);

    return temp;
}

template <typename T>
BinaryTree<T> BinaryTree<T>::getMirrorImage()
{
    BinaryTree<T> mirror;

    mirror.root = mirrorTree(root);

    return mirror;
}

template <typename T>
void BinaryTree<T>::displayDescendents(Node<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    cout << r->info << " ";

    displayDescendents(r->left);
    displayDescendents(r->right);
}

template <typename T>
void BinaryTree<T>::displayDescendents(T node)
{
    Node<T> *t = findNode(root, node);

    if (t == nullptr)
    {
        cout << "Node does n't exist...\n";
        return;
    }

    displayDescendents(t->left);
    displayDescendents(t->right);

    cout << endl;
}

template <typename T>
void BinaryTree<T>::displayAncestors(Node<T> *r)
{
    if (r == nullptr)
    {
        return;
    }

    cout << r->info << " ";

    displayAncestors(findParent(root, r->info));
}

template <typename T>
void BinaryTree<T>::displayAncestors(T node)
{
    Node<T> *t = findParent(root, node);

    if (t == nullptr)
    {
        cout << "Node has no Ancestors...\n";
        return;
    }

    displayAncestors(t);

    cout << endl;
}

template <typename T>
int BinaryTree<T>::widthOfTree()
{
    if (root == nullptr)
    {
        return 0;
    }

    queue<Node<T> *> q;

    int width = 0;

    q.push(root);

    while (!q.empty())
    {
        int levelCount = q.size();

        if (levelCount > width)
        {
            width = levelCount;
        }

        for (int i = 0; i < levelCount; i++)
        {
            Node<T> *t = q.front();
            q.pop();

            if (t->left != nullptr)
            {
                q.push(t->left);
            }

            if (t->right != nullptr)
            {
                q.push(t->right);
            }
        }
    }

    return width;
}

template <typename T>
T BinaryTree<T>::maxfinder(Node<T> *r,T cur_max)
{
    if ( r == nullptr )
    {
        return cur_max;
    }

    if ( cur_max < r->info )
    {
        cur_max = r->info;
    }

    T max1 = maxfinder(r->left,cur_max);
    T max2 = maxfinder(r->right,cur_max);

    if ( max1 > max2 )
    {
        return max1;
    }

    return max2;
}

template <typename T>
T BinaryTree<T>::findMax()
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return T{};
    }

    T cur_max = root->info;
    return maxfinder(root,cur_max);

}

template <typename T>
T BinaryTree<T>::minfinder(Node<T> *r, T cur_min)
{
    if (r == nullptr)
    {
        return cur_min;
    }

    if (cur_min > r->info)
    {
        cur_min = r->info;
    }

    T min1 = minfinder(r->left, cur_min);
    T min2 = minfinder(r->right, cur_min);

    if ( min1 < min2 )
    {
        return min1;
    }

    return min2;
}

template <typename T>
T BinaryTree<T>::findMin()
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return T{};
    }

    T cur_min = root->info;
    return minfinder(root,cur_min);

}

template <typename T>
bool BinaryTree<T>::isFullBinary(Node<T> *r)
{
    if (r == nullptr)
    {
        return true;
    }

    if (( r->left != nullptr && r->right == nullptr) || ( r->left == nullptr && r->right != nullptr))
    {
        return false;
    }

    return ( isFullBinary(r->left) && isFullBinary(r->right) );
}


template <typename T>
bool BinaryTree<T>::isFullBinaryTree()
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return false;
    }

    return isFullBinary(root);
}

template <typename T>
bool BinaryTree<T>::isCompleteBinary(Node<T> *r)
{
    if (r == nullptr)
    {
        return true;
    }

    queue<Node<T> *> q;
    bool flag = false;

    q.push(r);

    while (!q.empty())
    {
        Node<T> *t = q.front();
        q.pop();

        if (t->left != nullptr)
        {
            if (flag)
            {
                return false;
            }

            q.push(t->left);
        }
        else
        {
            flag = true;
        }

        if (t->right != nullptr)
        {
            if (flag)
            {
                return false;
            }

            q.push(t->right);
        }
        else
        {
            flag = true;
        }
    }

    return true;
}

template <typename T>
bool BinaryTree<T>::isCompleteBinaryTree()
{

    if (root == nullptr)
    {
        return true;
    }

    return isCompleteBinary(root);
}

template <typename T>
int BinaryTree<T>::Smaller(Node<T> *r,T k)
{
    queue<Node<T> *> q;
    int count = 0;

    q.push(r);

    while (!q.empty())
    {
        Node<T> *t = q.front();
        q.pop();
        if ( t->info < k )
        {
            count++;
        }
        if (t->left != nullptr)
        {
            q.push(t->left);
        }
        if (t->right != nullptr)
        {
            q.push(t->right);
        }
    }
    return count;
}

template <typename T>
int BinaryTree<T>::countSmaller(T k)
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return 0;
    }
    
    return Smaller(root,k);
}

template <typename T>
int BinaryTree<T>::Equal(Node<T> *r, T k)
{
    queue<Node<T> *> q;
    int count = 0;

    q.push(r);

    while (!q.empty())
    {
        Node<T> *t = q.front();
        q.pop();
        if (t->info == k)
        {
            count++;
        }
        if (t->left != nullptr)
        {
            q.push(t->left);
        }
        if (t->right != nullptr)
        {
            q.push(t->right);
        }
    }
    return count;
}

template <typename T>
int BinaryTree<T>::countEqual(T k)
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return 0;
    }
    
    return Equal(root, k);
}

template <typename T>
int BinaryTree<T>::countRange(Node<T> *r, T a, T b)
{
    queue<Node<T> *> q;
    int count = 0;

    q.push(r);

    while (!q.empty())
    {
        Node<T> *t = q.front();
        if ( t->info >= a && t->info <= b )
        {
            count++;
        }
        q.pop();
        if (t->left != nullptr)
        {
            q.push(t->left);
        }
        if (t->right != nullptr)
        {
            q.push(t->right);
        }
    }
    return count;
}

template <typename T>
int BinaryTree<T>::countInRange(T a, T b)
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return 0;
    }
    int count = countRange(root,a,b);

    return count;
}

template <typename T>
T BinaryTree<T>::sum_greater(Node<T> *r, T k)
{
    queue<Node<T> *> q;
    T sum = 0;

    q.push(r);

    while (!q.empty())
    {
        Node<T> *t = q.front();
        if ( t->info > k )
        {
            sum = sum + t->info;
        }
        q.pop();
        if (t->left != nullptr)
        {
            q.push(t->left);
        }
        if (t->right != nullptr)
        {
            q.push(t->right);
        }
    }
    return sum;
}

template <typename T>
T BinaryTree<T>::sumGreater(T k)
{
    if (root == nullptr)
    {
        cout << "Root does n't exist...\n";
        return 0;
    }

    return sum_greater(root,k);
}

template <typename T>
int BinaryTree<T>::countNodesAtLevel(Node<T> *r, int L, int curLevel)
{
    if (r == nullptr)
    {
        return 0;
    }

    if (curLevel == L)
    {
        return 1;
    }

    return countNodesAtLevel(r->left, L, curLevel + 1) + countNodesAtLevel(r->right, L, curLevel + 1);
}

template <typename T>
int BinaryTree<T>::countNodesAtLevel(int L)
{
    if (root == nullptr || L < 0)
    {
        return 0;
    }

    return countNodesAtLevel(root, L, 0);
}



