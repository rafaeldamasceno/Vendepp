#include "Store.h"

#include <fstream>
#include <sstream>
#include <iostream>

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

	customersFile.ignore(INT64_MAX,'\n');

	Customer customer;

	while (customersFile)
	{
		customersFile >> customer;
		customersFile.ignore(INT64_MAX, '\n');
		customers.push_back(customer);
		customersIdPointer[customer.getId()] = customersNamePointer[customer.getName()] = &(*customers.rbegin());
	}
}

void Store::readProducts()
{
	ifstream productsFile(fileNames[1]);

	productsFile.ignore(INT64_MAX, '\n');

	Product product;

	while (productsFile)
	{
		productsFile >> product;
		productsFile.ignore(INT64_MAX, '\n');
		products.push_back(product);
		productsNamePointer[product.getName()] = &(*products.rbegin());
	}
}

void Store::readTransactions()
{
	ifstream transactionsFile(fileNames[2]);

	transactionsFile.ignore(INT64_MAX, '\n');

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
			customer = Customer(id, "", Date(1,1,1970), 0.0, false);
		}

		Date date;
		string datestring;

		transactionsFile >> datestring;
		date = Date(datestring);

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

		transactionsFile.ignore(INT64_MAX, '\n');
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

void Store::askFileNames()
{
	cout << "Customers file: ";
	cin >> fileNames[0];
	cout << "Products file: ";
	cin >> fileNames[1];
	cout << "Transactions file: ";
	cin >> fileNames[2];
	//system("cls");
}
void Store::askFileNames(const string & a, const string & b, const string & c)
{
	fileNames[0] = a;
	fileNames[1] = b;
	fileNames[2] = c;
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