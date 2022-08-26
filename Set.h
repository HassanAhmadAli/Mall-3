#pragma once
#include "LIFOList.h"
template <class T>
class Set :LIFOList<T>
{
	Set();
	virtual void push(T* Value);
	virtual void Pop();
	virtual T* get();
};

template<class T>
Set<T>::Set() :  LIFOList<T>()
{

}

template<class T>
void Set<T>::push(T* Value)
{
	Node<T>* temp = List<T>::First;

}
