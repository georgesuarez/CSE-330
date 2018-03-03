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
	void add(T x);
	void add(int i, T x);
	void del(T x);
	void erase(int i);
	void print();
	T getfront();
	T getback();
	T operator[](unsigned int i);

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
void Glist<T>::add(int i, T x)
{
	if (i == 0 || i == lsize - 1)
	{
		add(x);
	}

	Lnode<T> *ptr = new Lnode<T>();
	ptr->data = x;

	Lnode<T> *iter = first;

	for (int j = 0; j < i - 1; j++)
	{
		iter = iter->rptr;
	}

	iter->rptr->lptr = ptr;
	ptr->rptr = iter->rptr;

	iter->rptr = ptr;
	ptr->lptr = iter;

	lsize++;
}

template <typename T>
void Glist<T>::del(T x)
{
	Lnode<T> *iter = first;
	lsize--;

	if (x == getfront())
	{
		Lnode<T> *ptr = first;
		first = first->rptr;
		delete ptr;
		return;
	}

	if (x == getback())
	{
		Lnode<T> *ptr = last;
		last = last->lptr;
		delete ptr;
		return;
	}

	for (iter = iter->rptr; iter->rptr != nullptr; iter++)
	{
		if (iter->data == x)
		{
			iter->lptr->rptr = iter->rptr;
			iter->rptr->lptr = iter->lptr;
			delete iter;
			return;
		}
	}
}

template <typename T>
void Glist<T>::erase(int i)
{
	Lnode<T> *iter = first;
	lsize--;

	if (i == 0)
	{
		Lnode<T> *ptr = first;
		first = first->rptr;
		delete ptr;
		return;
	}

	if (i == lsize - 1)
	{
		Lnode<T> *ptr = last;
		last = last->lptr;
		delete ptr;
		return;
	}

	for (int j = 0; j < i; j++)
	{
		iter = iter->rptr;
	}

	iter->lptr->rptr = iter->rptr;
	iter->rptr->lptr = iter->lptr;

	delete iter;
}

template <typename T>
void Glist<T>::print()
{
	Lnode<T> *iter = first;
	while (iter->rptr != nullptr)
	{
		std::cout << iter->data << ' ';
		iter = iter->rptr;
	}
	std::cout << std::endl;
}

template <typename T>
T Glist<T>::getfront()
{
	assert(lsize > 0);
	return first->data;
}

template <typename T>
T Glist<T>::getback()
{
	assert(lsize > 0);
	return last->data;
}

template <typename T>
T Glist<T>::operator[](unsigned int i)
{
	assert(lsize > 0);
	Lnode<T> *ptr;
	ptr = first;
	for (int j = 0; j < i; j++)
	{
		ptr = ptr->rptr;
	}
	return ptr->data;
}

int main()
{
	srand(time(nullptr));
	Glist<int> list = Glist<int>();
	for (int i = 0; i < 10; i++)
	{
		list.add(rand() % 100 + 1);
	}

	list.print();
}