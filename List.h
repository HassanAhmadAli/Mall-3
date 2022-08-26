#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class List
{
protected:
public:
	Node<T>* Last;
	Node<T>* First;

	List();
	bool IsEmpty();
	virtual void Push(T*);
	virtual void Pop();
	virtual T* get();
	T* GetAndPop();
	~List();
};

template<typename T>
List<T>::List()
{
	First = Last = 0;

}

template<typename T>
bool List<T>::IsEmpty()
{
	return (First == 0);
}

template<typename T>
void List<T>::Push(T* Value)
{

	if (First != 0)
	{
		First = new Node<T>(Value , 0 , 0);
	}
	else
	{
		
		Node<T>* temp1 = new Node<T>(Value, Last, 0);
		First = Last = temp1;

	}
}

template<typename T>
void List<T>::Pop()
{
	if (Last == 0) {
		return;
	}

	Node<T>* temp = Last;
	
	Last = Last->Previuse;

	temp->Previuse = 0;

	temp->Content = 0;

	delete temp;

	if (Last != 0) {
		Last->Next = 0;
	}
}

template<typename T>
T* List<T>::get()
{
	return  Last->Content;
}

template<typename T>
T* List<T>::GetAndPop()
{
	T* dump = get();
	Pop();
	return dump;
}

template<typename T>
List<T>::~List()
{
	delete First;
	delete Last;
}
