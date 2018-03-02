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
	void remove(int i);
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

}

template <typename T>
void Glist<T>::del(T x)
{

}

template <typename T>
void Glist<T>::remove(int i)
{

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
	Glist<int> list = Glist<int>();
	list.add(10);
	list.add(20);
	list.add(30);
	list.add(40);
	list.add(50);
	std::cout << "Front of the list: " << list.getfront() << std::endl;
	std::cout << "Back of the list: " << list.getback() << std::endl;
	
}