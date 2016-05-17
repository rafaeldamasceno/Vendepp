#include "AddTransaction.h"

MenuResult AddTransaction::handle()
{
	BuyProducts();
	return CONTINUE;
}

BuyProducts::BuyProducts()
{
	Customer * GetCustomer(unsigned int id);
	Date GetDate();
	void PrintProducts();
	list <Product *> Getproducts();
	void ShowTransaction();
}

Customer * BuyProducts::GetCustomer(unsigned int ID)
{
	cout << "Customer ID: " << endl;
	unsigned int customerID;
	while (true)
	{
		cin >> customerID;

		if (!cin.good())
		{
			cin.clear();
			cin.ignore(INT64_MAX, '\n');
			continue;
		}
		if (!(existsCustomer(customerID)))
		{
			cin.clear();
			cin.ignore(INT64_MAX, '\n');
			continue;
		}
		return (fetchCustomer(customerID));
	}
}

Date BuyProducts::GetDate()
{
	cout << "Insert date: " << endl;
	Date date;
	cin >> date;
	return date;
}

void BuyProducts::PrintProducts()
{
	cout << endl;
	//Store::writeProducts();
	cout << endl;
}

list <Product *> BuyProducts::Getproducts()
{
	unsigned int chosenProduct;
	while (true)
	{
		cin >> chosenProduct;
		//adicionar casos em que não dá nada

	}
} 

