#include <iostream>
#include <ctime>
#include <vector>
#include "Mvector.h"
#include "Mlist.h"
#include "Mtree.h"

int main()
{
    Mvector<int> v1 = Mvector<int>();
    Mvector<int> v2 = Mvector<int>();

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);

    if (v1 == v2)
    {
        std::cout << "Equal" << std::endl;
    }
    else
    {
        std::cout << "Not Equal" << std::endl;
    }
}