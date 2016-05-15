#pragma once

#include <list>
#include <string>

#include "Customer.h"
#include "Product.h"
#include "Transaction.h"

using namespace std;

class Store
{
public:
	Store();
	void load();
	void save();
	void readCustomers();
	void readProducts();
	void readTransactions();
	void writeCustomers();
	void writeProducts();
	void writeTransactions();

	bool existsCustomer(const unsigned int & id) const;

private:
	list <Customer> customers;
	list <Product> products;
	list <Transaction> transactions;
	string fileNames[2]; // 0 is customers, 1 is products and 2 is transactions
};