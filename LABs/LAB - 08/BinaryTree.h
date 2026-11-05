#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <math.h>

using namespace std;

class BinaryTree{
    
    private:

    int *data;
    bool *status;
    int height;
    int capacity;

    void PreOrder(int i);
    void PostOrder(int i);
    void InOrder(int i);
    int getActualheight(int i);
    void remove(int index);
    void Ancestors(int node);
    void Descendents(int node);
    void displayLevel(int index, int currentLevel, int levelNo);
    void ParenthesizedView(int index);

public:

    BinaryTree(int h);
    BinaryTree(const BinaryTree &obj);
    BinaryTree &operator = (const BinaryTree &obj);
    ~BinaryTree();
    void SetLeftChild(int p, int n);
    void SetRightChild(int p, int n);
    void SetRoot(int r);
    int getParent(int n) const;
    int getRoot() const;
    void LevelOrderPrint();
    void PreOrderPrint();
    void PostOrderPrint();
    void InOrderPrint();
    int getActualheight();
    int getLeftChild(int p);
    int getRightChild(int p);
    int getIndex(int node);
    void removeNode(int node);
    void displayAncestors(int node);
    void displayDescendents(int node);
    int findLevelOfNode(int node);
    void displayLevel(int levelNo);
    void displayParenthesizedView();
};

#include "BinaryTree.cpp"
#endif
