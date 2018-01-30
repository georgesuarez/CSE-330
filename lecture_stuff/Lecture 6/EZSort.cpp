#include <iostream>
#include <vector>

// Sort v from i to v.end() - 1 ( or v.back() )
void ez_sort(std::vector<int> &v, int i)
{
    if (v.size() == 0)
    {
        return;
    }
    else if (i == v.size())
    {
        return;
    }
    else
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            // std::cout << "Index: " << j << '\n';
            if (v[j] < v[i])
            {
                std::cout << "Swapped: " << v[j] << " with " << v[i] << '\n';
                std::swap(v[j], v[i]);
            }
        }
        ez_sort(v, i + 1);
    }
}

int main()
{
    srand(time(nullptr));
    std::vector<int> data;

    for (int i = 0; i < 10; i++)
    {
        data.push_back(rand() % 100 + 1);
    }

    ez_sort(data, 0);

    for (int i = 0; i < data.size(); i++)
    {
        std::cout << data[i] << ' ';
    }

    return 0;
}