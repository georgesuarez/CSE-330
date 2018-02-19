// CSE 330 Data Structures Lab
// Section: Monday
// Term: Winter 2018
// Name: George Suarez
// Lab 4: Vectors
// File: GVector.h

#ifndef GVECTOR_H
#define GVECTOR_H

#include <cassert>

template <typename T>
class GVector {
 public:
  GVector();
  GVector(unsigned int n);
  ~GVector();
  void push_back(T x);
  void pop_back();
  void clear();
  void insert(unsigned int i, T x);
  void erase(unsigned int i);
  T operator[](unsigned int i);
  int size() const;

 private:
  void reserve(unsigned int n) {
    T *NewV = new T[n];
    assert(NewV != NULL);

    for (int i = 0; i < vsize; i++) {
      NewV[i] = v[i];
    }
    delete[] v;
    v = NewV;
    vcap = n;
  }

 private:
  int vsize;
  int vcap;
  T *v;
};

template <typename T>
GVector<T>::GVector() {
  T *NewV = new T[vcap];
  assert(NewV != NULL);
  v = NewV;
  vcap = 2;
  vsize = 0;
}

template <typename T>
GVector<T>::GVector(unsigned int n) {
  assert(n >= 0);
  T *NewV = new T[vcap];
  assert(NewV != NULL);
  vsize = n;
  vcap = vsize * 2;
  v = NewV;
}

template <typename T>
GVector<T>::~GVector() {
  delete[] v;
}

template <typename T>
void GVector<T>::push_back(T x) {
  if (vsize == vcap) {
    reserve(2 * vcap);
    v[vsize++] = x;
  } else {
    v[vsize++] = x;
  }
}

template <typename T>
void GVector<T>::pop_back() {
  assert(vsize > 0);
  vsize--;
}

template <typename T>
void GVector<T>::clear() {
  vcap = 2;
  vsize = 0;
}

template <typename T>
void GVector<T>::insert(unsigned int i, T x) {
  assert(i >= 0 && i <= vsize);
  if (vsize == vcap) {
    reserve(2 * vcap);
  }
  for (int j = vsize; j > i + 1; j--) {
    v[j] = v[j - 1];
  }
  v[i] = x;
  vsize++;
}

template <typename t>
void GVector<t>::erase(unsigned int i) {
  assert(i >= 0 && i < vsize);
  for (int j = i; j < vsize; j++) {
    v[j] = v[j + 1];
  }
  vsize--;
}

template <typename T>
int GVector<T>::size() const {
  return vsize;
}

template <typename T>
T GVector<T>::operator[](unsigned int i) {
  assert(i < vsize && vsize > 0);
  return v[i];
}

#endif  // GVECTOR_H
  