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

	bool existsCustomer(const unsigned int & id) const;
	bool existsProduct(const string & name) const;
	Product * fetchProduct(const string & name);
	Customer * GetCustomerThroughID(unsigned int ID);
	Product * fetchProductbyposicion(unsigned int pos);


private:
	list <Customer> customers;
	list <Product> products;
	list <Transaction> transactions;
	map <unsigned int, Customer *> customersIdPointer;
	map <string, Customer *> customersNamePointer;
	map <string, Product *> productsnamePointer;
	map <unsigned int, Product *> productspositionpointer;
	string fileNames[2]; // 0 is customers, 1 is products and 2 is transactions
};