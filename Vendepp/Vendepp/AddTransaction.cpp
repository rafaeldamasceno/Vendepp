#include "AddTransaction.h"

AddTransaction::AddTransaction()
{
	BuyProducts(); //não dá porque AddTransaction é um menuhandler, e por isso deve criar um vetor de menuentrys, que o envia para outro menuhandler
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
			cin.clear();
			continue;
		}
		if (!(existsCustomer(customerID)))
		{
			cin.clear();
			cin.clear();
			continue;
		}
		return (GetCustomerThroughID(customerID));
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

