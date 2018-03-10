// CSE 330 Data Structures Lab
// Name: George Suarez
// Term: Winter 2018
// Section: Monday
// Lab 7: Update on Mlist and Mtree
// File: Mtree.h

#pragma once

#ifndef MTREE_H
#define MTREE_H

template <typename T>
class Tnode
{
  public:
    Tnode *lptr;
    Tnode *rptr;
    T data;
};

template <typename T>
class Mtree
{
  public:
    Mtree();
    void add(T x);
    bool find(T x);
    void printTree() const;

  private:
    Tnode<T> *root;
    int tsize;
    void add(Tnode<T> *ptr, T x);
    bool find(Tnode<T> *ptr, T x);
    void printTree(Tnode<T> *ptr) const;
};

template <typename T>
Mtree<T>::Mtree() : root(nullptr), tsize(0)
{
}

template <typename T>
void Mtree<T>::add(T x)
{
    if (tsize == 0)
    {
        Tnode<T> *ptr = new Tnode<T>(); // New Root
        ptr->lptr = nullptr;
        ptr->rptr = nullptr;
        ptr->data = x;
        root = ptr;
        tsize++;
        return;
    }
    else
    {
        add(root, x);
    }
    tsize++;
}

template <typename T>
void Mtree<T>::add(Tnode<T> *ptr, T x)
{
    if (ptr->lptr == nullptr && x <= ptr->data)
    {
        Tnode<T> *node = new Tnode<T>();
        ptr->lptr = node;
        node->data = x;
        node->lptr = nullptr;
        node->rptr = nullptr;
        return;
    }
    else if (ptr->rptr == nullptr && x > ptr->data)
    {
        Tnode<T> *node = new Tnode<T>();
        ptr->rptr = node;
        node->data = x;
        node->lptr = nullptr;
        node->rptr = nullptr;
        return;
    }
    
    if (x <= ptr->data)
    {
        add(ptr->lptr, x);
    }
    else
    {
        add(ptr->rptr, x);
    }
}

template <typename T>
bool Mtree<T>::find(T x)
{
    if (root->data == x) // Found in the root
    {
        return true;
    }
    else
    {
        find(root, x);
    }
}

template <typename T>
bool Mtree<T>::find(Tnode<T> *ptr, T x)
{
    if (ptr == nullptr)
    {
        return false;
    }
    else if (x < ptr->data)
    {
        return find(ptr->lptr, x);
    }
    else if (x > ptr->data)
    {
        return find(ptr->rptr, x);
    }
    else
    {
        return true;
    }
}

template <typename T>
void Mtree<T>::printTree() const
{
    if (tsize == 0)
    {
        return;
    }
    else
    {
        printTree(root);
    }
    std::cout << std::endl;
}

template <typename T>
void Mtree<T>::printTree(Tnode<T> *ptr) const
{
    if (ptr != nullptr)
    {
        printTree(ptr->lptr);
        std::cout << ptr->data << " ";
        printTree(ptr->rptr);
    }
}

#endif // MTREE_H