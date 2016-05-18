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
		productsNamePointer[product.getName()] = &(*products.rbegin());
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
			customer = *fetchCustomer(id);
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

		transactions.push_back(Transaction(customer, date));

		Transaction & transaction = *transactions.rbegin();

		while (ss)
		{
			getline(ss, product, ',');

			if (existsProduct(product))
			{
				transaction.products.push_back(fetchProduct(product));
			}

			ss.ignore(1);
		}

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
		if (productsNamePointer.at(name))
			return true;
	}
	catch (const out_of_range &oor) {
		return false;
	}
	return false;
}

Product * Store::fetchProduct(const string & name)
{
	return productsNamePointer.at(name);
}

Customer * Store::fetchCustomer(const unsigned int & id)
{
	return customersIdPointer.at(id);
}

Product * Store::fetchProduct(const unsigned int & pos)
{
	return productsPositionPointer.at(pos);
}