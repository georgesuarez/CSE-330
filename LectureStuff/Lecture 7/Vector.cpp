#include <cassert>
#include <ctime>
#include <iostream>

template <typename T>
class Mvector {
 public:
  Mvector();
  Mvector(unsigned int n);
  ~Mvector();
  void push_back(const T &x);
  void pop_back();
  void clear();
  void insert(int i, T x);
  void erase(int i);
  const T &operator[](unsigned int i) const;
  int size() const;

 private:
  int vsize;  // number of elements in use in the array v
  int vcap;   // actual size of the array v
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
const T &Mvector<T>::operator[](unsigned int i) const {
  return v[i];
}

template <typename T>
void Mvector<T>::push_back(const T &x) {
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

// TODO: Finish this implementation
template <typename T>
void Mvector<T>::erase(int i) {
  assert(i >= 0);

  delete v[i];
}

template <typename T>
int Mvector<T>::size() const {
  return vsize;
}

int main() {
  srand(time(nullptr));
  Mvector<int> v = Mvector<int>();

  for (int i = 0; i < 100; i++) {
    v.push_back(rand() % 100 + 1);
  }

  for (int i = 0; i < v.size(); i++) {
    std::cout << v[i] << '\n';
  }

  return 0;
}
