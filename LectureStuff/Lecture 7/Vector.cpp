#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
class MyVector
{
  public:
    MyVector();
    MyVector(unsigned int n);
    void push_back(const T &x);
    void pop_back();
    void clear();
    void insert(int i, T x);
    void erase(int i);
    T &operator[](unsigned int i);
    int size() const;

  private:
    int vsize; // number of elements in use in the array v
    int vcap;  // actual size of the array v
    T *v;
    void reserve(unsigned int n)
    {
        if (n < vsize)
        {
            return;
        }

        T *NewV = new T[n];

        for (int i = 0; i < vsize; i++)
        {
            NewV[i] = std::move(v[i]);
        }

        vcap = n;
        std::swap(v, NewV);
        delete [] NewV;
    }
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
    assert(n >= 0);

    vsize = n;
    vcap = vsize * 2;
    T *NewV = new T[vcap];
    v = NewV;
}

template <typename T>
T &MyVector<T>::operator[](unsigned int i)
{
    return v[i];
}

template <typename T>
void MyVector<T>::push_back(const T &x)
{
    if (vsize == vcap)
    {
        reserve(2 * vcap + 1);
    }
    else
    {
        v[vsize++] = x;
    }
}

template <typename T>
void MyVector<T>::pop_back()
{
    vsize--;
}

// TODO: Finish this implementation
template <typename T>
void MyVector<T>::clear()
{
    delete [] v;
}

// TODO: Finish this implementation
template <typename T>
void MyVector<T>::insert(int i, T x)
{
    v[i] = x;
}

// TODO: Finish this implementation
template <typename T>
void MyVector<T>::erase(int i)
{
    T *NewV = new T[vcap];
    for (int k = 0; k < vsize; k++)
    {
        NewV[k] = v[k];
        if (k == i)
        {
            continue;
        }
    }
    std::swap(v, NewV);
    delete [] NewV;
}

template <typename T>
int MyVector<T>::size() const
{
    return vsize;
}

int main()
{

    MyVector<int> v = MyVector<int>();
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.pop_back();
    v.clear();

    std::cout << v[0] << '\n';

    return 0;
}
