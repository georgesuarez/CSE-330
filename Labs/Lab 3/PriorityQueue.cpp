// CSE 330 Data Structures Lab
// Section: Monday
// Term: Winter 2018
// Name: George Suarez
// Lab 3: Priority Queue 
// File: PriorityQueue.cpp

#include <vector>
#include <iostream>

template <typename T>
class PQ
{
  public:
    PQ();
    PQ(std::vector<T> pq);
    int size() const;
    T front_of_queue() const;
    void print();
    void add(T x);
    void remove();

  private:
    void sort(std::vector<T> &v)
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
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

  private:
    std::vector<T> pq;
};

template <typename T>
PQ<T>::PQ()
{
}

template <typename T>
PQ<T>::PQ(std::vector<T> pq_)
{
    pq = pq_;
    this->sort(pq);
}

template <typename T>
int PQ<T>::size() const
{
    return pq.size();
}

template <typename T>
T PQ<T>::front_of_queue() const
{
    return pq.front();
}

template <typename T>
void PQ<T>::print()
{
    typename std::vector<T>::iterator it;
    for (it = pq.begin(); it != pq.end(); ++it)
    {
        std::cout << *it << ' ';
    }

    std::cout << '\n';
}

template <typename T>
void PQ<T>::add(T x)
{
    typename std::vector<T>::iterator it;
    for (it = pq.begin(); it != pq.end(); ++it)
    {
        if (*it >= x)
        {
            pq.insert(it, x);
            return;
        }
    }

    pq.insert(pq.end(), x);
}

template <typename T>
void PQ<T>::remove()
{
    pq.erase(pq.begin());
}

int main()
{
    srand(time(nullptr));
    PQ<int> pq = PQ<int>();

    for (int i = 0; i < 10; i++)
    {
        pq.add(rand() % 100 + 1);
    }

    pq.print();
    pq.add(rand() % 100 + 1);
    std::cout << "Front of queue: " << pq.front_of_queue() << '\n';
    std::cout << pq.front_of_queue() << " has been removed." << '\n';
    pq.remove();
    pq.print();

    return 0;
}