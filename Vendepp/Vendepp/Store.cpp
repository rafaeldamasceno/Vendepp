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
	writeCustomers();
	//writeProducts();
	writeTransactions();
}

void Store::writeTransactions()
{
	ofstream transactionsFile(fileNames[2]);
	transactionsFile << transactions.size() << endl;
	for (const Transaction & i : transactions)
	{
		transactionsFile << i << endl;
	}
}

void Store::writeCustomers()
{
	ofstream customersFile(fileNames[0]);
	customersFile << customers.size() - inactiveCustomers << endl;
	for (const Customer & i : customers)
	{
		if (i.getActiveStatus())
		{
			customersFile << i << endl;
		}
	}
}

void Store::readCustomers()
{
	ifstream customersFile(fileNames[0]);
	Customer customer;
	unsigned int n;

	customersFile >> n;
	customersFile.ignore(INT64_MAX, '\n');

	for (size_t i = 0; i < n; i++)
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
	Product product;
	unsigned int n;

	productsFile >> n;
	productsFile.ignore(INT64_MAX, '\n');

	for (size_t i = 0; i < n; i++)
	{
		productsFile >> product;
		productsFile.ignore(INT64_MAX, '\n');
		products.push_back(product);
		productsNamePointer[product.getName()] = productsPositionPointer[i] = &(*products.rbegin());
	}

}

void Store::readTransactions()
{
	ifstream transactionsFile(fileNames[2]);
	unsigned int n;

	transactionsFile >> n;
	transactionsFile.ignore(INT64_MAX, '\n');

	for (size_t i = 0; i < n; i++)
	{
		unsigned int id;
		Customer * customer;
		Date date;
		string productsLine, product;
		stringstream ss;

		transactionsFile >> id;
		transactionsFile.ignore(3);

		if (existsCustomer(id))
		{
			customer = fetchCustomer(id);
		}
		else
		{
			addCustomer(Customer(id, "", Date(1, 1, 0), 0.0, false));
			customer = &(*customers.rbegin());
		}

		transactionsFile >> date;

		transactionsFile.ignore(3);

		getline(transactionsFile, productsLine);
		ss << productsLine;

		transactions.push_back(Transaction(*customer, date));

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
	}
}

void Store::addCustomer(const Customer & c)
{
	customers.push_back(c);
	customersIdPointer[c.getId()] = customersNamePointer[c.getName()] = &(*customers.rbegin());
	if (!c.getActiveStatus())
	{
		inactiveCustomers++;
	}
	writeCustomers();
}

bool Store::existsCustomer(const unsigned int & id) const
{
	return customersIdPointer.find(id) != customersIdPointer.end();
}

bool Store::existsProduct(const string & name) const
{
	return productsNamePointer.find(name) != productsNamePointer.end();
}

void Store::askFileNames()
{
	cout << "Customers file: ";
	cin >> fileNames[0];
	cout << "Products file: ";
	cin >> fileNames[1];
	cout << "Transactions file: ";
	cin >> fileNames[2];
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

const map <unsigned int, Product*> & Store::getProductsIdMap()
{
	return productsPositionPointer;
}

const map <unsigned int, Customer*> & Store::getCustomersIdMap()
{
	return customersIdPointer;
}

const map <string, Customer*> & Store::getCustomersNameMap()
{
	return customersNamePointer;
}

const list <Customer> & Store::getAllCustomers()
{
	return customers;
}

const list <Transaction>& Store::getAllTransactions()
{
	return transactions;
}

Product * Store::fetchProduct(const unsigned int & pos)
{
	return productsPositionPointer.at(pos);
}