#pragma once
#include "Product.h"
#include "FIFOList.h"
class Client
{

private:
	Client();
	const int id;
public:
	Cart* ClientCart;
	Client(int);
	Client(int, Cart*);
	void PushProduct(Product*);
	int GetId()const;
	void print()const;

};

class Queue
{

public:

	Queue();
	FIFOList<Client> Clients;
	void Push(Client*);
	bool IsEmpty();
	virtual Client* GetAndPop();
	void ServiceClient(Client*);
	Client* FindClient(int);
	void Print()const;
	~Queue();
};
