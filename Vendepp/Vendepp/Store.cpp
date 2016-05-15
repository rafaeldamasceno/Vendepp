#include "Store.h"

#include <fstream>

Store::Store()
{

}

void Store::load()
{
	readCustomers();
	readProducts();
	readTransactions();
}

void Store::save()
{
	writeCustomers();
	writeProducts();
	writeTransactions();
}

void Store::readCustomers()
{
	ifstream customersFile(fileNames[0]);

	unsigned int size;

	customersFile >> size;
	customersFile.ignore(INT64_MAX, '/n');

	customers.resize(size);

	for (Customer & i: customers)
	{
		customersFile >> i;
		customersFile.ignore(INT64_MAX, '/n');
	}
}

void Store::readProducts()
{
	ifstream productsFile(fileNames[1]);

	unsigned int size;

	productsFile >> size;
	productsFile.ignore(INT64_MAX, '/n');

	products.resize(size);

	for (Product & i : products)
	{
		productsFile >> i;
		productsFile.ignore(INT64_MAX, '/n');
	}
}

void Store::readTransactions()
{
	ifstream transactionsFile(fileNames[2]);

	unsigned int size;

	transactionsFile >> size;
	transactionsFile.ignore(INT64_MAX, '/n');
	unsigned int transactionID;
	for (Transaction & i : transactions)
	{
		transactionsFile >> transactionID;
		transactionsFile.ignore(3);
		if (existsCustomer(transactionID))
		{
			for (Customer & e : customers)
			{
				if (transactionID == e.getId())
				{
					i.SetCustomer(e);
					continue;
				}
			}
		}
		else
		{
			Customer voidCustomer = { transactionID, "voidcustomer", "01/01/1970", 0.00, false};
			i.SetCustomer(voidCustomer);
		}
		Date date;
		transactionsFile >> date;
		i.SetDate(date);
		transactionsFile.ignore(3);

		

	}

}

bool Store::existsCustomer(const unsigned int & id) const
{
	for (const Customer & i : customers)
	{
		if (i.getId() == id)
		{
			return true;
		}
	}
	return false;
}