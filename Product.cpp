#include "Product.h"
#include"Mall.h"

Product::Product(string _Parcode, string _Name, int _Amount) :Parcode(_Parcode), Name(_Name), Amount(_Amount)
{
	;
}

bool Product::operator==(Product& rhs) const
{
	return (Parcode == rhs.Parcode);
}

bool Product::operator==(string _Name)const
{
	return (Parcode == _Name);
}

const string& Product::GetName() const
{
	return Name;
}
const string& Product::GetParcode() const
{
	return Parcode;
}

int Product::GetAmount() const
{
	return Amount;
}

void Product::SetAmount(int _Amount)
{
	if (_Amount > 0)
	{
		Amount = _Amount;
	}
	else
	{
		Amount = 0;
	}
}

void Product::Print()const
{
	cout << "Product Name is: " << Name << endl;
	cout << "Parcode of " << Name << "is: " << Parcode << endl;
	cout << "Amount of " << Name << "is: " << Amount << endl;
}
Cart::Cart()
{
	;
}

void Cart::Push(Product* pro)
{

	Node<Product>* MallTemp = Mall::MallProducts->First;
	Node<Product>* CartTemp = CartProducts.First;
	bool isExist = false;
	int MallAmount = 0;
	while (MallTemp != 0)
	{
		if (MallTemp->Content)
			if (MallTemp->Content->GetParcode() == pro->GetParcode())
			{
				isExist = true;
				MallAmount = MallTemp->Content->GetAmount();
				break;
			}
			else
				MallTemp = MallTemp->Next;
	}
	if (isExist)
	{
		while (CartTemp)
		{
			if (CartTemp->Content)
				if (CartTemp->Content->GetParcode() == pro->GetParcode())
				{
					int ADD = (MallAmount >= pro->GetAmount() ? pro->GetAmount() : MallAmount);
					CartTemp->Content->SetAmount(CartTemp->Content->GetAmount() + ADD);
					MallTemp->Content->SetAmount(MallTemp->Content->GetAmount() - ADD);
					if (MallAmount < pro->GetAmount())
						cout << "the amount is not exiestd in the mall returned only " << MallAmount;
					break;
				}
				else if (CartTemp->Next != 0)
					CartTemp = CartTemp->Next;
				else
				{

					CartProducts.Push(new Product(pro->GetParcode(), MallTemp->Content->GetName(), CartTemp->Content->GetAmount() + (MallAmount >= pro->GetAmount() ? pro->GetAmount() : MallAmount)));
					MallTemp->Content->SetAmount(MallTemp->Content->GetAmount() - (MallAmount >= pro->GetAmount() ? pro->GetAmount() : MallAmount));
					if (MallAmount < pro->GetAmount())
						cout << "the amount is not exiestd in the mall returned only " << MallAmount;
				}
		}
		cout << "the product is not existed in the mall\n";
	}
	else
	{
		cout << "This product is not exist in mall." << endl;
	}
}




bool Cart::IsEmpty()
{
	return CartProducts.IsEmpty();
}

void Cart::Print() const
{
	Node<Product>* temp = CartProducts.First;
	while (temp) {
		temp->Content->Print();
		cout << endl;
		temp = temp->Next;
	}
}



Cart::~Cart()
{
	CartProducts.~LIFOList();
}