#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class BinaryTree
{
private:
    T *data;
    bool *status;
    int height;
    int capacity;

    void PreOrder(int i);
    void PostOrder(int i);
    void InOrder(int i);

    int getActualheight(int i);

    void remove(int index);
    void Ancestors(int index);
    void Descendents(int index);

    void displayLevel(int index, int currentLevel, int levelNo);
    void ParenthesizedView(int index);

public:
    BinaryTree(int h);
    BinaryTree(const BinaryTree<T> &obj);
    BinaryTree<T> &operator=(const BinaryTree<T> &obj);
    ~BinaryTree();

    void SetLeftChild(T p, T n);
    void SetRightChild(T p, T n);
    void SetRoot(T r);

    T getParent(T n) const;
    T getRoot() const;

    void LevelOrderPrint();
    void PreOrderPrint();
    void PostOrderPrint();
    void InOrderPrint();

    int getActualheight();

    T getLeftChild(T p);
    T getRightChild(T p);

    int getIndex(T node);
    void removeNode(T node);

    void displayAncestors(T node);
    void displayDescendents(T node);

    int findLevelOfNode(T node);
    void displayLevel(int levelNo);

    void displayParenthesizedView();
};

#include "BinaryTree.tpp"
#endif

