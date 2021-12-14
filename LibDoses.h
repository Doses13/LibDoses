#pragma once
#include <iostream>
template <class T>
class dynArray
{
protected:
	T* m_array;		// The actual array
	int m_size;		// How many elements are in the array
public:
	// Tors
	dynArray();							// Default
	dynArray(T Init, unsigned Size);	// Initialize value, size
	dynArray(T* Init, unsigned Size);	// Initialize array, size
	dynArray(const dynArray& Original);	// Copy
	//~dynArray();						// Destructor

	// Data managment
	void push_back(T Data);
	void push_back(const T* Data, unsigned Length);
	void push_front(T Data);
	T& pop_back();
	T& pop_front();
	T& top();
	T& bottom();
	virtual void resize(int Amount, T Init);
	T& operator[](int Index);

	// Other
	int size() const;
	void purge();
	T* getPtr() const;
	
};
class str : public dynArray<char>
{
public:
	// Tors
	str();						// Default
	str(const str& Original);	// Copy
	str(const char* Init);		// Init

	void resize(int Amount, char Init = '\0') override;
	void display(const char* Post = "\n", const char* Between = "", const char* Pre = "");

	// ops
	str& operator+(const str& rhs);
	str& operator+(const char* rhs);
	str& operator=(const str& rhs);
	str& operator=(const char* rhs);
};

#include "LibDoses.cpp"