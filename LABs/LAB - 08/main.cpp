#include "BinaryTree.h"

int main()
{
    BinaryTree t(4);
    t.SetRoot(100);
    t.SetLeftChild(100,50);
    t.SetRightChild(100,90);
    t.SetLeftChild(50,5);
    t.SetLeftChild(90,70);
    t.SetRightChild(90,80);
    t.SetLeftChild(70,3);

    t.LevelOrderPrint();
    t.PreOrderPrint();
    t.PostOrderPrint();
    t.InOrderPrint();
    cout << t.getActualheight() << endl;

    t.removeNode(50);
    t.LevelOrderPrint();
    t.displayAncestors(3);
    t.displayDescendents(90);






    return 0;
}