#pragma once
template<class T> dynArray<T>::dynArray() : m_array(nullptr), m_size(0) {};
template<class T> dynArray<T>::dynArray(T Init, unsigned Size)
{
	resize(Size, Init);
}
template<class T> dynArray<T>::dynArray(T* Init, unsigned Size)
{
	push_back(Init, Size);
}
template<class T> dynArray<T>::dynArray(const dynArray& Original)
{
	push_back(Original.m_array, Original.m_size);
}
template<class T> dynArray<T>::~dynArray()
{
	purge();
}
template<class T> void dynArray<T>::push_back(T Data)
{
	T* new_array = new T[m_size + 1];
	for (int i = 0; i < m_size; i++)	// copy old array
	{
		new_array[i] = m_array[i];
	}
	new_array[m_size] = Data;			// add new element
	delete[] m_array;
	m_array = new_array;
	m_size++;
}
template<class T> void dynArray<T>::push_back(const T* Data, unsigned Length)
{
	T* new_array = new T[m_size + Length];
	for (int i = 0; i < m_size; i++)	// copy old array
	{
		new_array[i] = m_array[i];
	}
	for (int i = 0; i < Length; i++)	// add new element
	{
		new_array[i + m_size] = Data[i];
	}
	delete[] m_array;
	m_array = new_array;
	m_size += Length;
}
template<class T> void dynArray<T>::push_front(T Data)
{
	T* new_array = new T[m_size + 1];
	for (int i = 0; i < m_size; i++)
	{
		new_array[i + 1] = m_array[i];
	}
	new_array[0] = Data;
	delete[] m_array;
	m_array = new_array;
	m_size++;
}
template<class T> T& dynArray<T>::pop_back()
{
	T* new_array = new T[m_size - 1];
	for (int i = 0; i < m_size - 1; i++)
	{
		new_array[i] = m_array[i];
	}
	T* pop = new T;
	*pop = m_array[m_size - 1];
	delete[] m_array;
	m_array = new_array;
	size--;
	return pop;
}
template<class T> T& dynArray<T>::pop_front()
{
	T* new_array = new T[m_size - 1];
	for (int i = 0; i < m_size - 1; i++)
	{
		new_array[i] = m_array[i + 1];
	}
	T* pop = new T;
	*pop = m_array[0];
	delete[] m_array;
	m_array = new_array;
	size--;
	return pop;
}
template<class T> T& dynArray<T>::back()
{
	return m_array[m_size - 1];
}
template<class T> T& dynArray<T>::front()
{
	return m_array[0];
}
template<class T> void dynArray<T>::resize(int Amount, T Init)
{
	if (0 < Amount) // increase size
	{
		T* new_array = new T[m_size + Amount];
		for (int i = 0; i < m_size; i++)	// copy old array
		{
			new_array[i] = m_array[i];
		}
		for (int i = m_size; i < Amount; i++)	// Init new elements
		{
			new_array[i] = Init;
		}
		delete[] m_array;
		m_array = new_array;
		m_size += Amount;
	}
	else if (Amount < 0 && 0 < m_size - Amount) // decrease size
	{
		T* new_array = new T[m_size + Amount];
		for (int i = 0; i < m_size + Amount; i++)
		{
			new_array[i] = m_array[i];
		}
		delete[] m_array;
		m_array = new_array;
		m_size += Amount;
	}
}
template<class T> T& dynArray<T>::/*operator[]*/operator[](int Index)
{
	if (0 <= Index && Index < m_size)
	{
		return m_array[Index];
	}
}
template<class T> int dynArray<T>::size() const
{
	return m_size;
}
template<class T> void dynArray<T>::purge()
{
	delete[] m_array;
	m_array = nullptr;
	m_size = 0;
}
template<class T> T* dynArray<T>::getPtr()
{
	return m_array;
}

// str : dynArray-----------------------------
str::str() {};
str::str(const str& Original)
{
	push_back(Original.m_array, Original.m_size);
}
str::str(const char* Init)
{
	int init_length = 0 < Init[0];
	for (int i = 0; Init[i]; i++)
	{
		init_length++;
	}
	push_back(Init, init_length);
}
void str::resize(int Amount, char Init)
{
	dynArray::resize(Amount, Init);
}
void str::display(const char* Post, const char* Between, const char* Pre)
{
	std::cout << Pre;
	for (int i = 0; i < m_size - 2; i++)
	{
		std::cout << m_array[i] << Between;
	}
	std::cout << m_array[m_size - 2] << Post;
}
str& str::operator+(const char* rhs) // concat from char*
{
	resize(-1); // remove null termination
	int rhs_length = 0 < rhs[0];
	for (int i = 0; rhs[i]; i++)
	{
		rhs_length++;
	}
	push_back(rhs, rhs_length);
	return *this;
}
str& str::operator+(const str& rhs) // concat from str
{
	resize(-1);
	push_back(rhs.m_array, rhs.m_size);
	return *this;
}