#include <iostream>
#include <ctime>
#include <vector>
#include "Mtree.h"

int main()
{

    srand(time(nullptr));
    clock_t start, finish;

    start = clock();

    // Step 1: Create an Mtree
    Mtree<int> tree = Mtree<int>();

    // Step 2: Add random integers to the Mtree
    for (int i = 0; i < 10000; i++)
    {
        tree.add(rand());
    }
    
    // Step 3: Apply the inorder transveesal algorithm to sort the integers
    std::vector<int> v = tree.inorder();

    finish = clock();

    std::cout << "cpu time= " << finish - start << std::endl;
}