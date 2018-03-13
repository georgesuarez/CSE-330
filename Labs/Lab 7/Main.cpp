// CSE 330 Data Structures Lab
// Name: George Suarez
// Term: Winter 2018
// Section: Monday
// Lab 7: Update on Mlist and Mtree
// File: Main.cpp

#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Mlist.h"
#include "Mtree.h"

int main()
{
    srand(time(nullptr));
    Mtree<int> tree = Mtree<int>();
    std::vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        tree.add(rand() % 100 + 1);
        v.push_back(rand() % 100 + 1);
    }

    std::sort(v.begin(), v.end());

    std::cout << "v contains: ";
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Tree contains: ";
    tree.printTree();
}