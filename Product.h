#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include"LIFOList.h"
using namespace std;

class Product
{

public:
	Product(string _Parcode, string _Name, int _Amount = 0);
	bool operator==(Product& rhs)const;
	bool operator==(string _Name)const;
	const string& GetName()const;
	const string& GetParcode()const;
	int GetAmount()const;
	void SetAmount(int _Amount);
	void Print()const;
private:
	const string Name;
	const string Parcode;
	int Amount;
};


class Cart
{
public:

	Cart();
	LIFOList<Product> CartProducts;
	void Push(Product*);
	bool IsEmpty();
	void Print()const;
	~Cart();

};
