#include <vector>
#include <iostream>

// Best case is O(1)
// Worst case is O(n)
int find(std::vector<int> &v, int x)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == x)
        {
            return i;
        }
    }

    return -1;
}

// Insertion Sort
void sort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)  // n + 1
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[j] < v[i])
            {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main()
{
    std::vector<int> data;
    data.push_back(1);
    data.push_back(6);
    data.push_back(15);
    data.push_back(10);
    data.push_back(2);
    data.push_back(4);
    data.push_back(8);

    sort(data);

    for (size_t i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }                   

    return 0;             
}