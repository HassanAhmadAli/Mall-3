#include "Client.h"


Client::Client(int Id) :id(Id) {

	ClientCart = new Cart();
}

Client::Client(int I, Cart* cart) : id(I)
{
	if (cart !=  0)
	{
		ClientCart = cart;
	}
	else
	{
		ClientCart = new Cart();
	}
}
void Client::PushProduct(Product* pro)
{
	if ( ClientCart != 0)
		 ClientCart->Push(pro);
	else
	{
		 ClientCart = new Cart();
		ClientCart->Push(pro);
	}

}

int Client::GetId() const
{
	return id;
}


void Client::print()const
{
	cout << "Client\'s ID " << GetId() << endl;
	cout << "Client\'s Cart:" << endl;
	ClientCart->Print();
}


Queue::Queue()
{
	;
}

void Queue::Push(Client* cln)
{
	Clients.Push(cln);
}

bool Queue::IsEmpty()
{
	return Clients.IsEmpty();
}

Client* Queue::GetAndPop()
{
	return Clients.GetAndPop();
}

void Queue::ServiceClient(Client* cln)
{
	if (cln) {
		delete cln->ClientCart;
		cln->ClientCart = new Cart();
	}
}

Client* Queue::FindClient(int id)
{
	Node<Client>* dump = Clients.First;
	while (dump)
	{

		if (dump->Content)
		{
			if (dump->Content->GetId() == id)
				return dump->Content;
		}
		else
			dump = dump->Next;
	}
	return 0;
}

void Queue::Print() const
{
	Node<Client>* dump =  Clients.First;
	while (dump) {
		dump->Content->print();
		dump = dump->Next;
	}
}

Queue::~Queue()
{
	Clients.~FIFOList();
}