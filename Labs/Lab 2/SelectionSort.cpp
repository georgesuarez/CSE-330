// CSE 330 Data Structures Lab
// Section: Monday
// Term: Winter 2018
// Name: George Suarez
// Lab 2: Complexity Analysis
// File: SelectionSort.cpp

#include <cstdlib>
#include <vector>
#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void selSort(std::vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
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

    std::cout << "Enter size of input: "
              << " ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        v.push_back(rand() % 100 + 1);
    }

    start = clock();
    selSort(v);
    finish = clock();

    double cpu_time_used = ((double) (finish - start)) / CLOCKS_PER_SEC;

    std::cout << "Time = " << cpu_time_used << '\n';

    return 0;
}