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
    Mlist<int> list = Mlist<int>();

    
    Mtree<int> tree = Mtree<int>();

    for (int i = 0; i < 10; i++)
    {
        tree.add(rand() % 100 + 1);
        list.add(rand() % 100 + 1);
    }

     std::cout << "======Mlist Testing======" << std::endl;

    list.print();

    int random_index = list.size() % 9;

    std::cout << "Back of the list: " << list.getback() << std::endl;
    int random_element = list[random_index];

    list.del(random_element);
    std::cout << "Deleting element " << random_element << std::endl;

    random_index = list.size() % 9;
    list.erase(random_index);

    std::cout << "Erasing position " << random_index << std::endl;

    list.print();

    std::cout << "======Mtree Testing======" << std::endl;

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