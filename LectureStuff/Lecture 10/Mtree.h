#include <vector>

template <typename T>
class Tnode
{
  public:
	T data;
	Tnode *lptr;
	Tnode *rptr;
};

template <typename T>
class Mtree
{
  public:
	Mtree();
	void add(T x);
	std::vector<T> inorder();
	bool find(T x);

  private:
	void add(Tnode<T> *ptr, T x);
	Tnode<T> *root;
	std::vector<T> v;
	int tsize;
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
		Tnode<T> *ptr = new Tnode<T>(); // New root
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
		Tnode<T> *nptr = new Tnode<T>();
		ptr->lptr = nptr;
		nptr->data = x;
		nptr->lptr = nullptr;
		nptr->rptr = nullptr;
		return;
	}
	if (ptr->rptr == nullptr && x > ptr->data)
	{
		Tnode<T> *nptr = new Tnode<T>();
		ptr->rptr = nptr;
		nptr->data = x;
		notr->lptr = nullptr;
		nptr->rptr = nullptr;
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
}