#include <iostream>
#include <vector>

template <typename T>
class MyList
{
  public:
    MyList();
    void add(T x);
    void remove();
    T find(int i);  // Returns q[i]
    int find_index(T x);    // Find index at x in q
  private:
    std::vector<T> q;
};