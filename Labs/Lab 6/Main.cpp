// CSE 330 Data Structures Lab
// Name: George Suarez
// Term: Winter 2018
// Section: Monday
// Lab 6: Trees
// File: Main.cpp

#include <iostream>
#include <ctime>
#include "Mlist.h"
#include "Mtree.h"

int main()
{
    srand(time(nullptr));
    Mtree<int> tree = Mtree<int>();

    for (int i = 0; i < 10; i++)
    {
        tree.add(rand() % 100 + 1);
    }

    tree.add(0);

    tree.printTree();
    
    if (tree.find(0))
    {
        std::cout << "Element 0 has been found!" << std::endl;
    }
    else
    {
        std::cout << "Element 0 has not been found!" << std::endl;
    }

}