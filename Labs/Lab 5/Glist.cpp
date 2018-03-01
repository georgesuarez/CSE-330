// CSE 330 Data Structures Lab
// Name: George Suarez
// Section: Monday
// Term: Winter 2018
// Lab 5: Iterators and Lists
// File: Glist.cpp

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
class Glist
{
  public:
	Glist();
	typedef Lnode<T> *Iterator;
	Iterator front() { return first; }
	Iterator back() { return last;  }
	void add(T x);
	void add(unsigned int index, T x);
	void del(T x);
	void del(unsigned int index);
	void print();
	T getfront();
	T getBack();
	T operator[](unsigned int);

  private:
	Lnode<T> *first;
	Lnode<T> *last;
	int lsize;
};

template <typename T>
Glist<T>::Glist()
{
	first = nullptr;
	last = nullptr;
	lsize = 0;
}

template <typename T>
void Glist<T>::add(T x)
{
	Lnode<T> *ptr = new Lnode<T>();
	ptr->data = x;

	if (lsize == 0)
	{
		ptr->lptr = nullptr;
		ptr->rptr = nullptr;
		first = ptr;
		last = ptr;
	}
	else
	{
		ptr->lptr = last;
		ptr->rptr = nullptr;
		last->rptr = ptr;
		last = ptr;
	}
	lsize++;
}

template <typename T>
void Glist<T>::add(unsigned int i, T x)
{

}


template <typename T>
T Glist<T>::operator[](unsigned int index)
{
	assert(lsize > 0);
	Lnode<T> *ptr;
	ptr = first;
	for (int j = 0; j < index; j++)
	{
		ptr = ptr->rptr;
	}
	return ptr->data;
}

template <typename T>
void Glist<T>::del(T x) 
{

}

template <typename T>
void Glist<T>::del(unsigned int index)
{

}

int main()
{
	Glist<int> list = Glist<int>();
	list.add(10);
	std::cout << list[0] << '\n';
}