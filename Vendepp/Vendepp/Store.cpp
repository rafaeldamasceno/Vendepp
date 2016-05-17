#include "Store.h"

#include <fstream>
#include <sstream>

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
	//writeCustomers();
	//writeProducts();
	//writeTransactions();
}

void Store::readCustomers()
{
	ifstream customersFile(fileNames[0]);

	customersFile.ignore(INT64_MAX, '/n');

	Customer customer;

	while (customersFile >> customer)
	{
		customers.push_back(customer);
		customersIdPointer[customer.getId()] = &customer;
		customersNamePointer[customer.getName()] = &customer;
	}
}

void Store::readProducts()
{
	ifstream productsFile(fileNames[1]);

	productsFile.ignore(INT64_MAX, '/n');

	Product product;

	while (productsFile >> product)
	{
		products.push_back(product);
		productsnamePointer[product.getName()] = &product;
	}
}

void Store::readTransactions()
{
	ifstream transactionsFile(fileNames[2]);

	transactionsFile.ignore(INT64_MAX, '/n');

	while (transactionsFile)
	{
		unsigned int id;
		Customer customer;

		transactionsFile >> id;
		transactionsFile.ignore(3);

		if (existsCustomer(id))
		{
			customer = *customersIdPointer.at(id);
		}
		else
		{
			customer = Customer(id, "", "01/01/1970", 0.0, false);
		}

		Date date;

		transactionsFile >> date;

		transactionsFile.ignore(3);

		string productsLine, product;
		stringstream ss;

		getline(transactionsFile, productsLine);
		ss << productsLine;

		list <Product *> products;

		while (ss)
		{
			getline(ss, product, ',');

			if (existsProduct(product))
			{
				products.push_back(fetchProduct(product));
			}

			ss.ignore(1);
		}

		transactions.push_back(Transaction(customer, date));
		transactionsFile.ignore(INT64_MAX, '/n');
	}
}

bool Store::existsCustomer(const unsigned int & id) const
{
	try {
		if (customersIdPointer.at(id))
			return true;
	}
	catch (const out_of_range &oor) {
		return false;
	}
	return false;
}

bool Store::existsProduct(const string & name) const
{
	try {
		if (productsnamePointer.at(name))
			return true;
	}
	catch (const out_of_range &oor) {
		return false;
	}
	return false;
}

Product * Store::fetchProduct(const string & name)
{
	return productsnamePointer.at(name);
}

Customer * Store::GetCustomerThroughID(unsigned int ID)
{
	return customersIdPointer.at(ID);
}

Product * Store::fetchProductbyposicion(unsigned int pos)
{
	return productspositionpointer.at(pos);
}