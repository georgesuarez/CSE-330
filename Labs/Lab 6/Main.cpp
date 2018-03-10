#include <iostream>
#include <ctime>
#include "Mlist.h"

int main()
{
    srand(time(nullptr));
    Mlist<int> list = Mlist<int>();

    for (int i = 0; i < 10; i++)
    {
        list.add(rand() % 100 + 1);
    }

    list.print();

    std::cout << "Front of the list: " << list.getfront() << std::endl;
    std::cout << "Back of the list: " << list.getback() << std::endl;
    std::cout << "Using the [] operator to get an element from a random position in the list: " << list[rand() % 10] << std::endl;
}