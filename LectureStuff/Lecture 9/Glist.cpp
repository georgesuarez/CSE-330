#include <iostream>
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
	void del(T x);
	void deletefront();
	T getfront();

private:
	Lnode<T> *first;
	Lnode<T> *last;
	int lsize;
};

template <typename T>
Glist::Glist()
{
	first = nullptr;
	last = nullptr;
	lsize = 0;
}

template <typename T>
void Glist::add(T x)
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
void Glist::deletefront()
{
	Lnode<T> *cur = first;
	first = first->rptr;
	delete cur;
	last->lptr = nullptr;
	lsize--;
}