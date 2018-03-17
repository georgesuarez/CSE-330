#include <iostream>
#include <vector>
#include <ctime>
#include "Mtree.h"

int main()
{
    Mtree<int> tree = Mtree<int>();

    tree.add(22);
    tree.add(3);
    tree.add(5);
    tree.add(6);
    tree.add(1);
    tree.add(10);
    tree.add(11);
    tree.add(20);
    tree.add(16);
    tree.add(17);

    std::vector<int> v = tree.inorder();

    tree.printTree();
}