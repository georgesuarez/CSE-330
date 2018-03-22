#pragma once

#ifndef MVECTOR_H
#define MVECTOR_H

#include <cassert>
#include <ctime>
#include <iostream>

template <typename T>
class Mvector
{
  public:
    typedef T *iterator;
    Mvector();
    Mvector(unsigned int n);
    ~Mvector();
    void push_back(T x);
    void pop_back();
    void clear();
    void insert(unsigned int i, T x);
    void erase(unsigned int i);

    T operator[](unsigned int i);
    void operator--(int);
    bool operator==(Mvector<T> rhs);

    iterator begin() { return v; }
    iterator end() { return v + vsize; }
    void insert(iterator ix, T x);
    void erase(iterator ix);
    int size() const;

  private:
    void reserve(unsigned int n)
    {
        T *NewV = new T[n];
        assert(NewV != nullptr);
        for (int i = 0; i < vsize; i++)
        {
            NewV[i] = std::move(v[i]);
        }

        vcap = n;
        std::swap(v, NewV);
        delete[] NewV;
    }

  private:
    int vsize; // number of elements in use in the array v
    int vcap;  // actual size of the array v
    T *v;
};

template <typename T>
Mvector<T>::Mvector()
{
    vcap = 2;
    vsize = 0;
    T *NewV = new T[vcap];   // Creates an array of type T w/ 2 elements
    assert(NewV != nullptr); // Checks if a NewV is created
    v = NewV;
}

template <typename T>
Mvector<T>::Mvector(unsigned int n)
{
    vsize = n;
    vcap = vsize * 2;
    T *NewV = new T[vcap];
    assert(NewV != nullptr);
    v = NewV;
}

template <typename T>
Mvector<T>::~Mvector()
{
    delete[] v;
}

template <typename T>
T Mvector<T>::operator[](unsigned int i)
{
    assert(i < vsize && vsize > 0);
    return v[i];
}

template <typename T>
void Mvector<T>::operator--(int unused)
{
    this->pop_back();
}

template <typename T>
bool Mvector<T>::operator==(Mvector<T> rhs)
{
    if (vsize == rhs.size())
    {
        for (int i = 0; i < vsize; i++)
        {
            if (v[i] != rhs[i])
                return false;
        }
        return true;
    }
    return false;
}

template <typename T>
void Mvector<T>::push_back(T x)
{
    if (vsize == vcap)
    {
        reserve(2 * vcap);
        v[vsize++] = x;
    }
    else
    {
        v[vsize++] = x;
    }
}

template <typename T>
void Mvector<T>::pop_back()
{
    assert(vsize > 0);
    vsize--;
}

template <typename T>
void Mvector<T>::clear()
{
    vcap = 2;
    vsize = 0;
}

template <typename T>
void Mvector<T>::insert(unsigned int i, T x)
{
    assert(i >= 0 && i <= vsize);
    if (vsize == vcap)
    {
        reserve(2 * vcap);
    }
    for (int j = vsize; j > i + 1; j--)
    {
        v[j] = v[j - 1];
    }
    v[i] = x;
    vsize++;
}

template <typename T>
void Mvector<T>::insert(iterator ix, T x)
{
    if (vsize == vcap)
    {
        reserve(2 * vcap);
    }

    for (iterator jx = v + vsize; jx != ix; jx--)
    {
        *jx = *(jx - 1);
    }
    *ix = x;
    vsize++;
}

template <typename T>
void Mvector<T>::erase(unsigned int i)
{
    assert(i >= 0 && i < vsize);
    for (int j = i; j < vsize - 1; j++)
    {
        v[j] = v[j + 1];
    }
    vsize--;
}

template <typename T>
void Mvector<T>::erase(iterator ix)
{
    for (iterator jx = ix; jx != v + vsize; jx++)
    {
        *jx = *(jx + 1);
    }
    vsize--;
}

template <typename T>
int Mvector<T>::size() const
{
    return vsize;
}

#endif // MVECTOR_H