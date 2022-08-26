#pragma once
#include<iostream>
#include"List.h"

template<typename T>
class FIFOList :public List<T>
{
public:
	FIFOList();
	~FIFOList();
	virtual void Pop();
	virtual T* get();
};



template<typename T>
void FIFOList<T>::Pop()
{
	List<T>::Pop();
}

template<typename T>
T* FIFOList<T>::get()
{
	return  List<T>::get();
}

template<typename T>
FIFOList<T>::FIFOList()
{
}

template<typename T>
FIFOList<T>::~FIFOList()
{

}