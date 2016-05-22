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
	//void writeProducts();
	void writeTransactions();

	void addCustomer(const Customer & c);
	void addTransaction(const Transaction & t);

	bool existsCustomer(const unsigned int & id) const;
	bool existsProduct(const string & name) const;
	Product * fetchProduct(const string & name);
	Product * fetchProduct(const unsigned int & pos);
	Customer * fetchCustomer(const unsigned int & id);

	const map <Product *, unsigned int> & getProductsPointerMap();
	const map <unsigned int, Product *> & getProductsIdMap();
	const map <unsigned int, Customer *> & getCustomersIdMap();
	const map <string, Customer *> & getCustomersNameMap();
	const list <Customer> & getAllCustomers();
	const list <Transaction> & getAllTransactions();

	void deleteCustomer(Customer * customer);

	void askFileNames();
	void askFileNames(const string & a, const string & b, const string & c);

	unsigned int getAvailableId() const;

private:
	unsigned int inactiveCustomers = 0;
	list <Customer> customers;
	list <Product> products;
	list <Transaction> transactions;
	map <unsigned int, Customer *> customersIdPointer;
	map <string, Customer *> customersNamePointer;
	map <unsigned int, Product *> productsPositionPointer;
	map <Product *, unsigned int> productsPointerPosition;
	map <string, Product *> productsNamePointer;
	string fileNames[3]; // 0 is customers, 1 is products and 2 is transactions
};