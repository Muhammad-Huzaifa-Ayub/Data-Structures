#include "BinaryTree.h"

int main()
{
    BinaryTree<int> tree(4);

    tree.SetRoot(10);

    tree.SetLeftChild(10, 20);
    tree.SetRightChild(10, 30);

    tree.SetLeftChild(20, 40);
    tree.SetRightChild(20, 50);

    tree.SetLeftChild(30, 60);
    tree.SetRightChild(30, 70);

    tree.SetLeftChild(40, 80);
    tree.SetRightChild(40, 90);

    cout << "\nRoot: " << tree.getRoot() << endl;

    cout << "\nParent of 40: " << tree.getParent(40) << endl;

    cout << "\nLeft Child of 20: " << tree.getLeftChild(20) << endl;

    cout << "\nRight Child of 20: " << tree.getRightChild(20) << endl;

    cout << "\nIndex of 50: " << tree.getIndex(50) << endl;

    cout << "\nActual Height: " << tree.getActualheight() << endl;

    cout << "\nLevel of Node 80: " << tree.findLevelOfNode(80) << endl;

    cout << "\n";

    tree.LevelOrderPrint();
    tree.PreOrderPrint();
    tree.InOrderPrint();
    tree.PostOrderPrint();

    cout << endl;

    tree.displayAncestors(80);
    tree.displayDescendents(20);

    tree.displayLevel(2);

    tree.displayParenthesizedView();

    cout << "\nTesting Copy Constructor\n";

    BinaryTree<int> tree2(tree);

    tree2.LevelOrderPrint();

    cout << "\nTesting Assignment Operator\n";

    BinaryTree<int> tree3(2);

    tree3 = tree;

    tree3.LevelOrderPrint();

    cout << "\nTesting Remove Node\n";

    tree.removeNode(20);

    tree.LevelOrderPrint();

    cout << "\nTesting Character Tree\n";

    BinaryTree<char> tree4(3);

    tree4.SetRoot('A');

    tree4.SetLeftChild('A', 'B');
    tree4.SetRightChild('A', 'C');

    tree4.SetLeftChild('B', 'D');
    tree4.SetRightChild('B', 'E');

    tree4.LevelOrderPrint();
    tree4.PreOrderPrint();
    tree4.displayParenthesizedView();

    return 0;
}
