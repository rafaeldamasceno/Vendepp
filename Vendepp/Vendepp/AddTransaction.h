#pragma once

#include <iostream>
#include "Menu.h"


class AddTransaction : public Menu {
public:
	AddTransaction(Store & store);

	MenuResult handle();
	ExitHandler exitHandler;
private:
	Store & store;
};

//class BuyProducts : public Store
//{
//public:
//	BuyProducts();
//	Customer * GetCustomer(unsigned int ID);
//	Date GetDate();
//	void PrintProducts();
//	list <Product *> Getproducts();
//	void ShowTransaction();
//};