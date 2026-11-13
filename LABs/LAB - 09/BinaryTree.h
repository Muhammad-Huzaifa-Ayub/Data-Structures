#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<iostream>
#include<queue>

using namespace std;

template <typename T>
class Node{

public:

    T info;
    Node<T> *left;
    Node<T> *right;

    Node() : info{}, left(nullptr), right(nullptr){}
    Node(T n) : info(n), left(nullptr), right(nullptr){}
};

template <typename T>
class BinaryTree{

    Node<T> *root;

    Node<T>* copyTree(Node<T> *r);
    void destroyTree(Node<T> *r);
    void PreOrder(Node<T> *r);
    void PostOrder(Node<T> *r);
    void InOrder(Node<T> *r);
    void LevelOrder(Node<T> *r);
    Node<T>* findParent(Node<T> *r, T node);
    int countNodes(Node<T> *r);
    int countInternals(Node<T> *r);
    int countExternals(Node<T> *r);
    int height(Node<T> *r);
    void Parenthesized(Node<T> *r);
    Node<T>* mirrorTree(Node<T> *r);
    void displayDescendents(Node<T> *r);
    void displayAncestors(Node<T> *r);
    Node<T>* findParentPointer(Node<T> *r, Node<T> *target);
    T maxfinder(Node<T> *r, T cur_max);
    T minfinder(Node<T> *r, T cur_min);
    bool isFullBinary(Node<T> *r);
    bool isCompleteBinary(Node<T> *r);
    int Smaller(Node<T> *r, T k);
    int Equal(Node<T> *r, T k);
    int countRange(Node<T> *r, T a, T b);
    T sum_greater(Node<T> *r, T k);
    int countNodesAtLevel(Node<T> *r, int L, int curLevel);

public:

    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree<T> &other);
    BinaryTree<T> &operator = (const BinaryTree<T> &other);
    void setRoot(T d);
    T getRoot();
    Node<T>* findNode(Node<T> *r, T v);
    void setLeftChild(T p,T n);
    void setRightChild(T p, T n);
    void setParent(T p, T node);
    T getParent(T node);
    void PreOrderPrint();
    void PostOrderPrint();
    void InOrderPrint();
    void LevelOrderPrint();
    void remove(T node);
    T findNodeSiblings(T node);
    bool isInternalNode(T node);
    bool isExternalNode(T node);
    int countNodes();
    int countInternalNodes();
    int countExternalNodes();
    void getHeight();
    void displayParenthesizedView();
    BinaryTree<T> getMirrorImage();
    void displayDescendents(T node);
    void displayAncestors(T node);
    int widthOfTree();
    T findMax();
    T findMin();
    bool isFullBinaryTree();
    bool isCompleteBinaryTree();
    int countSmaller(T k);
    int countEqual(T k);
    int countInRange(T a, T b);
    T sumGreater(T k);
    int countNodesAtLevel(int L);
    
};


#include "BinaryTree.tpp"
#endif 
