#include "BinaryTree.h"

int main()
{
    BinaryTree<int> t(4);
    t.SetRoot(100);
    t.SetLeftChild(100,50);
    t.SetRightChild(100,90);
    t.SetLeftChild(50,5);
    t.SetLeftChild(90,70);
    t.SetRightChild(90,80);
    t.SetLeftChild(70,3);
    //t.SetRightChild(80,40);

    t.LevelOrderPrint();
    t.PreOrderPrint();
    t.PostOrderPrint();
    t.InOrderPrint();
    cout << t.getActualheight() << endl;

    //t.removeNode(50);
    t.LevelOrderPrint();
    t.displayAncestors(3);
    t.displayDescendents(90);
    cout << "\n\n";
    cout << "isLeaf : " << t.isLeaf(3) << endl;
    cout << "getSibling : " << t.getSibling(70);
    cout << "\ncountNodes : " << t.countNodes() << endl;
    t.LevelOrderPrint();
    cout << "\ncountLeaves : " << t.countLeaves();
    cout << "\ncountInternalNodes : " << t.countInternalNodes();
    cout << "\ncountNodesWithOneChild : " << t.countNodesWithOneChild();
    cout << "\ndisplayLeaves : "; t.displayLeaves();
    cout << "\nreverseLevelOrder : "; t.reverseLevelOrder();
    cout << "\ndisplayPath : "; t.displayPath(3);
    cout << "\nSpiralOrder : "; t.spiralOrder();


    return 0;
}