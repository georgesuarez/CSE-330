#include <iostream>
#include <ctime>
#include <vector>

void qsort(std::vector<int> &v, int lo, int hi)
{
    // Sort v between lo and hi indexes
    if (lo == hi)
    {
        return;
    }
    else
    {
        int pivot = (v[lo] + v[hi]) / 2;
        std::vector<int> v1, v2;
        for (int i = lo; i <= hi; i++)
        {
            if (v[i] <= pivot)
            {
                v1.push_back(v[i]);
            }
            else
            {
                v2.push_back(v[i]);
            }
        }
        for (int i = 0; i < v1.size(); i++)
        {
            v[lo + i] = v1[i];
        }
        for (int i = 0; i < v2.size(); i++)
        {
            v[lo + v1.size() + i] = v2[i];
        }
        qsort(v, lo, lo + v1.size() - 1);
        qsort(v, lo + v1.size(), hi);
    }
}

int main()
{
    std::vector<int> v;
    srand(time(nullptr));

    for (int i = 0; i < 10; i++)
    {
        v.push_back(rand() % 100 + 1);
    }

    qsort(v, 0, v.size() - 1);

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << std::endl;
}
