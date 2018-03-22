#ifndef MTREE_H
#define MTREE_H

#include <vector>

template <typename T>
class Tnode {
 public:
  T data;
  Tnode* lptr;
  Tnode* rptr;
};

template <typename T>
class Mtree {
 public:
  Mtree();
  void add(T x);
  std::vector<T> preorder();
  std::vector<T> inorder();
  std::vector<T> postorder();
  bool find(T x);
  void printTree() const;
  void del(T x);

 private:
  void add(Tnode<T>* ptr, T x);
  bool find(Tnode<T>* ptr, T x);
  void del(Tnode<T>* ptr, T x);
  void preorder(Tnode<T>* ptr);
  void inorder(Tnode<T>* ptr);
  void postorder(Tnode<T>* ptr);
  void printTree(Tnode<T>* ptr) const;
  Tnode<T>* root;
  std::vector<T> v;
  int tsize;
};

template <typename T>
Mtree<T>::Mtree() : root(nullptr), tsize(0) {}

template <typename T>
void Mtree<T>::add(T x) {
  if (tsize == 0) {
    Tnode<T>* ptr = new Tnode<T>();  // New root
    ptr->lptr = nullptr;
    ptr->rptr = nullptr;
    ptr->data = x;
    root = ptr;
  } else {
    add(root, x);
  }
  tsize++;
}

template <typename T>
void Mtree<T>::add(Tnode<T>* ptr, T x) {
  if (ptr->lptr == nullptr && x <= ptr->data) {
    Tnode<T>* nptr = new Tnode<T>();
    ptr->lptr = nptr;
    nptr->data = x;
    nptr->lptr = nullptr;
    nptr->rptr = nullptr;
    return;
  }
  if (ptr->rptr == nullptr && x > ptr->data) {
    Tnode<T>* nptr = new Tnode<T>();
    ptr->rptr = nptr;
    nptr->data = x;
    nptr->lptr = nullptr;
    nptr->rptr = nullptr;
    return;
  }
  if (x <= ptr->data) {
    add(ptr->lptr, x);
  } else {
    add(ptr->rptr, x);
  }
}

template <typename T>
bool Mtree<T>::find(T x) {
  if (root->data == x)  // Found in the root
  {
    return true;
  } else {
    find(root, x);
  }
}

template <typename T>
bool Mtree<T>::find(Tnode<T>* ptr, T x) {
  if (ptr == nullptr) {
    return false;
  } else if (x < ptr->data) {
    return find(ptr->lptr, x);
  } else if (x > ptr->data) {
    return find(ptr->rptr, x);
  } else {
    return true;
  }
}

template <typename T>
void Mtree<T>::del(T x) {
  del(root, x);
}

template <typename T>
void Mtree<T>::del(Tnode<T>* ptr, T x) {
  if (ptr == root && ptr->data == x && ptr->lptr == nullptr &&
      ptr->rptr == nullptr) {
    // Delete Root
    delete ptr;
    tsize--;
    root = nullptr;
    return;
  } else if (ptr->lptr->data == x && ptr->lptr->lptr == nullptr &&
             ptr->lptr->rptr == nullptr) {
    delete ptr->lptr;
    ptr->lptr = nullptr;
    tsize--;
    return;
  } else if (ptr->rptr->data == x && ptr->rptr->lptr == nullptr &&
             ptr->rptr->rptr == nullptr) {
    delete ptr->rptr;
    ptr->rptr = nullptr;
    tsize--;
    return;
  } else if (x <= ptr->data && ptr->lptr != nullptr) {
    del(ptr->lptr, x);
  } else if (ptr->rptr != nullptr)

  {
    del(ptr->rptr, x);
  }
}

template <typename T>
std::vector<T> Mtree<T>::preorder() {
  v.clear();

  if (tsize == 0) {
    return v;
  } else {
    preorder(root);
    return v;
  }
}

template <typename T>
void Mtree<T>::preorder(Tnode<T>* ptr) {
  if (ptr != nullptr) {
    v.push_back(ptr->data);
    preorder(ptr->lptr);
    preorder(ptr->rptr);
  }
}

template <typename T>
std::vector<T> Mtree<T>::inorder() {
  v.clear();
  if (tsize == 0) {
    return v;
  } else {
    inorder(root);
    return v;
  }
}

template <typename T>
void Mtree<T>::inorder(Tnode<T>* ptr) {
  if (ptr != nullptr) {
    inorder(ptr->lptr);
    v.push_back(ptr->data);
    inorder(ptr->rptr);
  }
}

template <typename T>
std::vector<T> Mtree<T>::postorder() {
  v.clear();

  if (tsize == 0) {
    return v;
  } else {
    postorder(root);
    return v;
  }
}

template <typename T>
void Mtree<T>::postorder(Tnode<T>* ptr) {
  if (ptr != nullptr) {
    postorder(ptr->lptr);
    postorder(ptr->rptr);
    v.push_back(ptr->data);
  }
}

template <typename T>
void Mtree<T>::printTree() const {
  if (tsize == 0) {
    return;
  } else {
    printTree(root);
  }
  std::cout << std::endl;
}

template <typename T>
void Mtree<T>::printTree(Tnode<T>* ptr) const {
  if (ptr != nullptr) {
    printTree(ptr->lptr);
    std::cout << ptr->data << " ";
    printTree(ptr->rptr);
  }
}

#endif  // MTREE_H