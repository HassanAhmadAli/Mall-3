#include "Mall.h"
using namespace std;

LIFOList<Product>* Mall::MallProducts = new LIFOList<Product>();

Mall::Mall()
{
	Accounting = new Queue();
	if (MallProducts == 0)
		Mall::MallProducts = new LIFOList<Product>();
}

void Mall::PushProduct(Product* _PRO)
{
	Node<Product>* MallTemp = Mall::MallProducts->First;
	bool isExist = false;
	while (MallTemp)
	{
		if (MallTemp->Content->GetParcode() == _PRO->GetParcode())
		{
			isExist = true;
			MallTemp->Content->SetAmount(MallTemp->Content->GetAmount() + _PRO->GetAmount());
			break;
		}
		else
			MallTemp = MallTemp->Next;
	}
	if (isExist)
	{
		return;
	}
	else
	{
		if (Mall::MallProducts->Last) {
			Mall::MallProducts->Last->Next = new Node<Product>(_PRO, Mall::MallProducts->Last , 0);
			Mall::MallProducts->Last = Mall::MallProducts->Last->Next;
		}
		else {
			Mall::MallProducts->First = Mall::MallProducts->Last = new Node<Product>(_PRO , 0 , 0 );
		}
	}
}

void Mall::PushClient(Client* _Client)
{
	Accounting->Push(_Client);
}
