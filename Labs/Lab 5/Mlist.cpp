// CSE 330 Data Structures Lab
// Name: George Suarez
// Section: Monday
// Term: Winter 2018
// Lab 5: Iterators and Lists
// File: Mlist.cpp

#include <iostream>
#include <ctime>
#include <cassert>

template <typename T>
class Lnode
{
  public:
    T data;
    Lnode *lptr;
    Lnode *rptr;
};

template <typename T>
class Mlist
{
  public:
    Mlist();
    void add(T x);
    void insert(int i, T x);
    void del(T x);
    void erase(int i);
    void print() const;
    T getfront();
    T getback();
    T operator[](unsigned int i);

  private:
    Lnode<T> *first;
    Lnode<T> *last;
    int lsize;
};

template <typename T>
Mlist<T>::Mlist() : first(nullptr), last(nullptr), lsize(0)
{
}

template <typename T>
void Mlist<T>::add(T x)
{
    Lnode<T> *ptr = new Lnode<T>();
    ptr->data = x;

    if (lsize == 0) // List is empty
    {
        ptr->lptr = nullptr;
        first = ptr;
        last = ptr;
        lsize++;
        return;
    }
    else // Add to the back
    {
        ptr->rptr = nullptr;
        ptr->lptr = last;
        last->rptr = ptr;
        last = ptr;
        lsize++;
        return;
    }
}

template <typename T>
void Mlist<T>::insert(int i, T x)
{
    if (i == 0) // Inserting to the front of the list
    {
        Lnode<T> *ptr = new Lnode<T>();
        ptr->data = x;
        ptr->lptr = nullptr;
        ptr->rptr = first;
        first->lptr = ptr;
        first = ptr;
        lsize++;
        return;
    }
    else if (i == lsize - 1) // Inserting to the back of the list
    {
        Lnode<T> *ptr = new Lnode<T>();
        ptr->data = x;
        ptr->rptr = nullptr;
        ptr->lptr = last;
        last->rptr = ptr;
        last = ptr;
        lsize++;
        return;
    }

    Lnode<T> *node = new Lnode<T>();
    node->data = x;
    Lnode<T> *iter = first;

    for (int j = 0; j < i; j++)
    {
        iter = iter->rptr;
    }
    
    iter->rptr->lptr = node;
    node->rptr = iter->rptr;

    iter->rptr = node;
    node->lptr = iter;

    lsize++;
}

template <typename T>
void Mlist<T>::del(T x)
{
    if (lsize == 0)
    {
        return;
    }

    Lnode<T> *iter = first;
    while (iter != nullptr)
    {
        if (iter->data == x)
        {
            Lnode<T> *next = iter->rptr;
            Lnode<T> *prev = iter->lptr;

            if (prev == nullptr && next == nullptr) // Deleting one element
            {
                delete first;
                first = nullptr;
                last = nullptr;
                lsize--;
                return;
            }
            else if(next == nullptr) // Delete last element
            {
                last = prev;
                last->rptr = nullptr;
                delete iter;
                lsize--;
                return;
            }
            else if(prev == nullptr) // Delete first element
            {
                first = iter->rptr;
                first->lptr = nullptr;
                delete iter;
                lsize--;
                return;
            }
            else
            {
                prev->rptr = iter->rptr;
                next->lptr = iter->lptr;
                delete iter;
                lsize--;
            }
        }
        else
        {
            iter = iter->rptr;
        }
    }
}

template <typename T>
void Mlist<T>::erase(int i)
{
    Lnode<T> *iter = first;
    for (int j = 0; j < i; j++)
    {
        iter = iter->rptr;
    }

    Lnode<T> *next = iter->rptr;
    Lnode<T> *prev = iter->lptr;

    if (prev == nullptr && next == nullptr) // Erasing just one element
    {
        delete first;
        first = nullptr;
        last = nullptr;
        lsize--;
        return;
    }
    else if (next == nullptr) // Erasing the last element
    {
        last = prev;
        last->rptr = nullptr;
        delete iter;
        lsize--;
        return;
    }
    else if (prev == nullptr)
    {
        first = iter->rptr;
        first->lptr = nullptr;
        delete iter;
        lsize--;
        return;
    }
    else
    {
        prev->rptr = iter->rptr;
        next->lptr = iter->lptr;
        delete iter;
        lsize--;
    }
}

template <typename T>
void Mlist<T>::print() const
{
    Lnode<T> *iter = first;
    while (iter != nullptr)
    {
        std::cout << iter->data << " ";
        iter = iter->rptr;
    }
    std::cout << std::endl;
}

template <typename T>
T Mlist<T>::getfront()
{
    assert(lsize > 0);
    return first->data;
}

template <typename T>
T Mlist<T>::getback()
{
    assert(lsize > 0);
    return last->data;
}

template <typename T>
T Mlist<T>::operator[](unsigned int i)
{
	assert(lsize > 0);
	Lnode<T> *ptr = first;
	for (int j = 0; j < i; j++)
	{
		ptr = ptr->rptr;
	}
	return ptr->data;
}


int main()
{
	srand(time(nullptr));
	Mlist<int> list = Mlist<int>();

	for (int i = 0; i < 10; i++)
	{
		list.add(rand() % 100 + 1);
	}

	std::cout << "Mlist contains: ";
	list.print();

	std::cout << "Front of the list: " << list.getfront() << std::endl;
	std::cout << "Back of the list: " << list.getback() << std::endl;

	std::cout << "Inserting 20 at position 9." << std::endl;
	list.insert(9, 20);

	std::cout << "Mlist contains: ";
	list.print();

	std::cout << "Deleting 20 from the list." << std::endl;
	list.del(20);

	std::cout << "Mlist contains: ";
	list.print();

	std::cout << "Deleting position 0 from the list." << std::endl;
	list.erase(0);

	std::cout << "Mlist contains: ";
	list.print();
}