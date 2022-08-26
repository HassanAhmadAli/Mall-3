#include <iostream>
#include "Mall.h"
#include "Node.h"
#include<string>
#include <list>

//hassan ali and laith asaad in 2021-12-11

using namespace std;
int main()
{/*
	list<int> x;
	
	Mall mall;
	string name, parcode;
	int x, z, id, amount;
	cout << "		Hello!\n";
	while (true)
	{

		cout << "	Choose Number:" << endl
			<< "1. Add Product to mall" << endl
			<< "2. Add client to queue" << endl
			<< "3. Add product to cart of client" << endl
			<< "4. Serve client" << endl
			<< "5. show all Clients" << endl
			<< "0. exit" << endl;       
		cin >> x;

		if (x == 0)
		{
			cout << "Good bye." << endl;
			break;

		}
		else if (x == 1)
		{
			cout << "Enter Parcode, Name, Amount of product" << endl;
			cin >> parcode >> name >> amount;
			mall.PushProduct( new Product(parcode, name, amount));

		}
		else if (x == 2)
		{
			Cart NewCart;
			cout << "Enter id of client,number of his products " << endl;
			cin >> id >> z;
			while (z > 0)
			{
				cout << "Enter ( Parcode, Amount ) of product" << endl;
				cin >> parcode >>  amount;
				Product* temp = new Product(parcode, " ", amount);
				NewCart.Push(temp);
				z--;
			}

			mall.Accounting->Push(new Client(id, &NewCart));

		}
		else if (x == 3)
		{
			cout << "Enter id of client " << endl;
			cin >> id;
			cout << "Enter (Parcode, Amount) of product" << endl;
			cin >> parcode >> amount;
			Product* temp = new Product(parcode, " ", amount);
			mall.Accounting->FindClient(id)->PushProduct(temp);


		}
		else if (x == 4)
		{
			cout << "Enter id of client " << endl;
			cin >> id;
			mall.Accounting->ServiceClient(mall.Accounting->FindClient(id));

		}
		else if (5)
		{
			cout << "Print all client in mall:" << endl;
			mall.Accounting->Print();

		}

		cout << endl;
	}

	*/


}