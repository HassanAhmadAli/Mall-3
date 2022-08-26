#pragma once
#include "Client.h"
#include "Product.h"
class Mall
{
public:
	Mall();
	static LIFOList<Product>* MallProducts;
	Queue* Accounting;
	void PushProduct(Product*);
	void PushClient(Client*);
};