#pragma once

#include "Menu.h"

enum CustomerSortBy
{
	NAME, ID, DATE
};

enum TransactionSortBy
{
	ID, DATE
};

class ViewAllCustomers : public Menu {
public:
	ViewAllCustomers(Store & store);

private:
	Store & store;
};

class ViewCustomers : public Menu {
public:
	ViewCustomers(Store & store);

private:
	Store & store;
};

class ViewTransactions : public Menu {
public:
	ViewTransactions(Store & store);

private:
	Store & store;
};

class ViewInformation : public Menu {
public:
	ViewInformation(Store & store);

private:
	Store & store;
};

class PrintProducts : public Menu {
public:
	PrintProducts(Store & store);

	MenuResult handle();

private:
	Store & store;
};

class PrintCustomers : public Menu
{
public:
	PrintCustomers(Store & store, CustomerSortBy sortBy);

	virtual MenuResult handle();

private:
	Store & store;
	CustomerSortBy sortBy;

};

class PrintTransactions : public Menu
{
public:
	PrintTransactions(Store & store, CustomerSortBy sortBy);

	virtual MenuResult handle();

private:
	Store & store;
	CustomerSortBy sortBy;

};