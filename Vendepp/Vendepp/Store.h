#pragma once

#include <list>
#include <map>
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

	string writeTransaction();
	string writeCustomer();

	bool existsCustomer(const unsigned int & id) const;
	bool existsProduct(const string & name) const;
	Product * fetchProduct(const string & name);
	Product * fetchProduct(const unsigned int & pos);
	Customer * fetchCustomer(const unsigned int & id);

	void askFileNames();
	void askFileNames(const string & a, const string & b, const string & c);


private:
	list <Customer> customers;
	list <Product> products;
	list <Transaction> transactions;
	list <Customer *> bottom10;
	map <unsigned int, Customer *> customersIdPointer;
	map <string, Customer *> customersNamePointer;
	map <unsigned int, Product *> productsPositionPointer;
	map <string, Product *> productsNamePointer;
	string fileNames[3]; // 0 is customers, 1 is products and 2 is transactions
};