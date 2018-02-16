#include <iostream>

template <typename T>
class Mvector
{
public:
  typedef T *Iterator;
  Iterator begin();
  Iterator end();

private:
  T *v;
  int vsize;
};

template <typename T>
Iterator Mvector<T>::begin()
{
  return v;
}

template <typename T>
Iterator Mvector<T>::end()
{
  return v + vsize;
}