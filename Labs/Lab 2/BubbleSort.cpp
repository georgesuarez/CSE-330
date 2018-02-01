// CSE 330 Data Structures Lab
// Section: Monday
// Term: Winter 2018
// Name: George Suarez
// Lab 2: Complexity Analysis
// File: BubbleSort.cpp

#include <vector>
#include <cstdlib>
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void bubbleSort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    clock_t start, finish;
    srand(time(nullptr));
    std::vector<int> v;
    int n = 0;

    std::cout << "Enter size of input: " << ' ';
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        v.push_back(rand());
    }

    start = clock();
    bubbleSort(v);
    finish = clock();

    double cpu_time_used = ((double) (finish - start)) / CLOCKS_PER_SEC;

    std::cout << "Time = " << cpu_time_used << '\n';

    return 0;
}