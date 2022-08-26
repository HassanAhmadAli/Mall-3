#pragma once
#include<iostream>
#include"List.h"

template<typename T>
class LIFOList :public List<T>
{
private:
public:
	LIFOList();
	virtual void Pop();
	virtual T* get();

	~LIFOList();
};

template<typename T>
LIFOList<T>::LIFOList() {}

template<typename T>
void LIFOList<T>::Pop()
{
	if (List<T>::First == 0) {
		return;
	}

	Node<T>* temp = List<T>::First;
	
	List<T>::First = List<T>::First->Next;

	temp->Next = 0;

	temp->Content = 0;

	delete temp;

	if (List<T>::First != 0) {
		List<T>::First->Previuse = 0;
	}
}

template<typename T>
T* LIFOList<T>::get()
{
	return  List<T>::Last->Content;
}

template<typename T>
LIFOList<T>::~LIFOList() {  }