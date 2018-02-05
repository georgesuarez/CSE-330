#include <iostream>
#include <cassert>

template <typename T>
class MyVector
{
  public:
    MyVector();
    MyVector(unsigned int n);
    void push_back();
    void pop_back();
    void clear();
    void insert(int i, T x);
    void erase(int i);
    T operator[](unsigned int i);
    int size() const;

  private:
    int vsize;  // number of elements in use in the array v
    int vcap;   // actual size of the array v
    T *v;
    void reserve(unsigned int n);
};

template <typename T>
MyVector<T>::MyVector() 
{
    vsize = 0;
    vcap = 10;
    T *NewV = new T[vcap];
    v = NewV;
}

template <typename T>
MyVector<T>::MyVector(unsigned int n) 
{
    assert(n >= 0)

    vsize = n;
    vcap = vsize * 2;
    T *NewV = new T[vcap];
    v = NewV;
}


int main()
{
    return 0;
}
