#include "BinaryTree.h"

using namespace std;

int main()
{
    BinaryTree<int> tree;

    tree.setRoot(10);

    tree.setLeftChild(10, 20);
    tree.setRightChild(10, 30);

    tree.setLeftChild(20, 40);
    tree.setRightChild(20, 50);

    tree.setLeftChild(30, 60);
    tree.setRightChild(30, 70);

    tree.setLeftChild(40, 80);
    tree.setRightChild(40, 90);

    cout << "\nPreorder Traversal: ";
    tree.PreOrderPrint();

    cout << "\nInorder Traversal: ";
    tree.InOrderPrint();

    cout << "\nPostorder Traversal: ";
    tree.PostOrderPrint();

    cout << "\nLevel Order Traversal: ";
    tree.LevelOrderPrint();

    cout << "\n\nParenthesized View: ";
    tree.displayParenthesizedView();

    cout << "\nRoot: " << tree.getRoot() << endl;

    cout << "\nParent of 80: " << tree.getParent(80) << endl;

    cout << "Sibling of 80: " << tree.findNodeSiblings(80) << endl;

    cout << "\nIs 20 an Internal Node? ";
    cout << (tree.isInternalNode(20) ? "Yes" : "No") << endl;

    cout << "Is 80 an External Node? ";
    cout << (tree.isExternalNode(80) ? "Yes" : "No") << endl;

    cout << "\nTotal Nodes: " << tree.countNodes() << endl;

    cout << "Internal Nodes: " << tree.countInternalNodes() << endl;

    cout << "External Nodes: " << tree.countExternalNodes() << endl;

    tree.getHeight();

    cout << "\nDescendants of 20: ";
    tree.displayDescendents(20);

    cout << "Ancestors of 80: ";
    tree.displayAncestors(80);

    BinaryTree<int> mirror = tree.getMirrorImage();

    cout << "\nMirror Image (Level Order): ";
    mirror.LevelOrderPrint();

    cout << "\nMirror Image (Parenthesized): ";
    mirror.displayParenthesizedView();

    BinaryTree<int> copy(tree);

    cout << "\nCopied Tree (Level Order): ";
    copy.LevelOrderPrint();

    BinaryTree<int> assigned;

    assigned = tree;

    cout << "\nAssigned Tree (Level Order): ";
    assigned.LevelOrderPrint();

    cout << "\n\nRemoving node 20 and its subtree...\n";

    //tree.remove(20);

    cout << "Tree after removal (Level Order): ";
    tree.LevelOrderPrint();

    cout << "\nWidth of Tree is : " << tree.widthOfTree() << endl;

    cout << "\nMax in tree : " << tree.findMax() << endl;
    cout << "\nMin in tree : " << tree.findMin() << endl;

    cout << "\nisFullBinaryTree : " << tree.isFullBinaryTree() << endl;
    cout << "\nisCompleteBinaryTree : " << tree.isCompleteBinaryTree() << endl;

    cout << "\ncountSmaller : " << tree.countSmaller(40) << endl;
    cout << "\ncountEqual : " << tree.countEqual(40) << endl;
    cout << "\ncountInRange : " << tree.countInRange(10,30) << endl;
    cout << "\nsumGreater : " << tree.sumGreater(70) << endl;
    cout << "\ncountNodesAtLevel : " << tree.countNodesAtLevel(2) << endl;

    return 0;
}

