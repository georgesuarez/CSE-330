#ifndef MVECTOR_H
#define MVECTOR_H

#include <algorithm>
#include <cassert>

template <typename T>
class Mvector {
 public:
  Mvector();
  Mvector(unsigned int n);
  ~Mvector();
  void push_back(T x);
  void pop_back();
  void clear();
  void insert(int i, T x);
  void erase(int i);
  T operator[](unsigned int i);
  int size() const;

 private:
  int vsize;
  int vcap;
  T *v;
  void reserve(unsigned int n) {
    if (n < vsize) {
      return;
    }

    T *NewV = new T[n];

    for (int i = 0; i < vsize; ++i) {
      NewV[i] = std::move(v[i]);
    }

    vcap = n;
    std::swap(v, NewV);
    delete[] NewV;
  }
};

template <typename T>
Mvector<T>::Mvector() {
  vsize = 0;
  vcap = 10;
  T *NewV = new T[vcap];
  v = NewV;
}

template <typename T>
Mvector<T>::Mvector(unsigned int n) {
  assert(n >= 0);

  vsize = n;
  vcap = vsize * 2;
  T *NewV = new T[vcap];
  v = NewV;
}

template <typename T>
Mvector<T>::~Mvector() {
  delete[] v;
}

template <typename T>
void Mvector<T>::push_back(T x) {
  if (vsize == vcap) {
    reserve(2 * vcap + 1);
  } else {
    v[vsize++] = x;
  }
}

template <typename T>
void Mvector<T>::pop_back() {
  vsize--;
}

template <typename T>
void Mvector<T>::clear() {
  vcap = 10;
  vsize = 0;
}

template <typename T>
void Mvector<T>::insert(int i, T x) {
  v[i] = x;
}

// TODO: Finish me!
template <typename t>
void mvector<t>::erase(int i) {
  assert(i >= 0);

  delete v[i];
}

template <typename T>
int Mvector<T>::size() const {
  return vsize;
}

template <typename T>
T Mvector<T>::operator[](unsigned int i) {
  return v[i];
}

#endif