#include <cassert>
#include <ctime>
#include <iostream>

template <typename T>
class Mvector
{
  public:
	typedef T *Iterator;
	Mvector();
	Mvector(unsigned int n);
	~Mvector();
	void push_back(T x);
	void pop_back();
	void clear();
	void insert(unsigned int i, T x);
	void erase(unsigned int i);
	T operator[](unsigned int i);
	Iterator begin() { return v; }
	Iterator end() { return v + vsize; }
	void insert(Iterator ix, T x);
	void erase(Iterator ix);
	int size() const;

  private:
	void reserve(unsigned int n)
	{
		T *NewV = new T[n];
		assert(NewV != nullptr);
		for (int i = 0; i < vsize; i++)
		{
			NewV[i] = std::move(v[i]);
		}

		vcap = n;
		std::swap(v, NewV);
		delete[] NewV;
	}

  private:
	int vsize; // number of elements in use in the array v
	int vcap;  // actual size of the array v
	T *v;
};

template <typename T>
Mvector<T>::Mvector()
{
	vcap = 2;
	vsize = 0;
	T *NewV = new T[vcap];   // Creates an array of type T w/ 2 elements
	assert(NewV != nullptr); // Checks if a NewV is created
	v = NewV;
}

template <typename T>
Mvector<T>::Mvector(unsigned int n)
{
	vsize = n;
	vcap = vsize * 2;
	T *NewV = new T[vcap];
	assert(NewV != nullptr);
	v = NewV;
}

template <typename T>
Mvector<T>::~Mvector()
{
	delete[] v;
}

template <typename T>
T Mvector<T>::operator[](unsigned int i)
{
	assert(i < vsize && vsize > 0);
	return v[i];
}

template <typename T>
void Mvector<T>::push_back(T x)
{
	if (vsize == vcap)
	{
		reserve(2 * vcap);
		v[vsize++] = x;
	}
	else
	{
		v[vsize++] = x;
	}
}

template <typename T>
void Mvector<T>::pop_back()
{
	assert(vsize > 0);
	vsize--;
}

template <typename T>
void Mvector<T>::clear()
{
	vcap = 2;
	vsize = 0;
}

template <typename T>
void Mvector<T>::insert(unsigned int i, T x)
{
	assert(i > 0 && i <= vsize);
	if (vsize == vcap)
	{
		reserve(2 * vcap);
	}
	for (int j = vsize; j > i + 1; j--)
	{
		v[j] = v[j - 1];
	}
	v[i] = x;
	vsize++;
}

template <typename T>
void Mvector<T>::insert(Iterator ix, T x)
{
	if (vsize == vcap - 1)
	{
		reserve(2 * vcap);
	}

	for (Iterator jx = v + vsize; jx != ix; jx--)
	{
		*jx = *(jx - 1);
	}
	*ix = x;
	vsize++;
}

template <typename T>
void Mvector<T>::erase(unsigned int i)
{
	assert(i >= 0 && i < vsize);
	for (int j = i; j < vsize - 1; j++)
	{
		v[j] = v[j + 1];
	}
	vsize--;
}

template <typename T>
void Mvector<T>::erase(Iterator ix)
{
	for (Iterator jx = ix; jx != v + vsize; jx++)
	{
		*jx = *(jx + 1);
	}
	vsize--;
}

template <typename T>
int Mvector<T>::size() const
{
	return vsize;
}

int main()
{
	Mvector<int> v = Mvector<int>();
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	Mvector<int>::Iterator ix = v.begin();

	v.erase(ix);

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
}