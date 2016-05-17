#pragma once

#include <iostream>
#include "Menu.h"


class AddTransaction : public Menu {
public:
	ExitHandler exitHandler;
	MenuResult handle();
};

class BuyProducts : public Store
{
public:
	BuyProducts();
	Customer * GetCustomer(unsigned int ID);
	Date GetDate();
	void PrintProducts();
	list <Product *> Getproducts();
	void ShowTransaction();
};