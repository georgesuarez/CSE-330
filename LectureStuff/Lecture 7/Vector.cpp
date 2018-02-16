#include <cassert>
#include <ctime>
#include <iostream>

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
  void operator--(); // prefix
  void operator--(int); // postfix
  int size() const;

 private:
  void reserve(unsigned int n) {
    T *NewV = new T[n];
    assert(NewV != nullptr);
    for (int i = 0; i < vsize; i++) {
      NewV[i] = std::move(v[i]);
    }

    vcap = n;
    std::swap(v, NewV);
    delete[] NewV;
  }

 private:
  int vsize;  // number of elements in use in the array v
  int vcap;   // actual size of the array v
  T *v;
};

template <typename T>
GVector<T>::GVector() {
  T *NewV = new T[vcap];    // Creates an array of type T w/ 2 elements
  assert(NewV != nullptr);  // Checks if a NewV is created
  vcap = 2;
  vsize = 0;
  v = NewV;
}

template <typename T>
GVector<T>::GVector(unsigned int n) {
  vsize = n;
  vcap = vsize * 2;
  T *NewV = new T[vcap];
  assert(NewV != nullptr);
  v = NewV;
}

template <typename T>
GVector<T>::~GVector() {
  delete[] v;
}

template <typename T>
T GVector<T>::operator[](unsigned int i) {
  assert(i < vsize && vsize > 0);
  return v[i];
}

template <typename T>
void GVector<T>::operator--() {
  this->pop_back();
}

template <typename T>
void GVector<T>::operator--(int) {
  this->pop_back();
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
  assert(i > 0 && i <= vsize);
  if (vsize == vcap) {
    reserve(2 * vcap);
  }
  for (int j = vsize; j > i + 1; j--) {
    v[j] = v[j - 1];
  }
  v[i] = x;
  vsize++;
}

// TODO: Finish this implementation
template <typename T>
void GVector<T>::erase(unsigned int i) {
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

int main() {
  srand(time(nullptr));
  GVector<int> v = GVector<int>();

  for (int i = 0; i < 10; i++) {
    v.push_back(rand() % 100 + 1);
  }

  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << '\n';
  }

  std::cout << v.size() << '\n';

  return 0;
}
