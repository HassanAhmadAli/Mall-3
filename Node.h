#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
	Node<T>* Next;
	Node<T>* Previuse;
	T* Content;
	Node(T*, Node<T>* = 0, Node<T>* = 0);
	~Node();
};

template<class T>
Node<T>::Node(T* _Content, Node<T>* _Previuse, Node<T>* _Next)
{
	Content = _Content;
	Next = _Next;
	Previuse = _Previuse;
}



template<typename T>
Node<T>::~Node()
{
	Content = 0;
	Previuse = Next = 0;
}