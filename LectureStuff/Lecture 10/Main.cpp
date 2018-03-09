#include <iostream>
#include <vector>
#include <ctime>
#include "Mtree.h"

int main()
{
    srand(time(0));
    Mtree<int> my_tree = Mtree<int>();
    for (int i = 0; i < 10; i++)
    {
        my_tree.add(rand() % 100 + 1);
    }
}