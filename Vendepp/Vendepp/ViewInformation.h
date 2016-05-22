#pragma once

#include "Menu.h"

enum SortBy
{
	ID, DATE, NAME, COST
};

enum ShowBy
{
	ALL, CUSTOMER, DAY, PERIOD
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

	virtual MenuResult handle();

private:
	Store & store;
};

class PrintCustomers : public Menu
{
public:
	PrintCustomers(Store & store, SortBy sortBy);
	PrintCustomers(Store & store, Customer * customer);


	virtual MenuResult handle();

private:
	Store & store;
	SortBy sortBy;
	Customer * customer = nullptr;

};

class PrintTransactions : public Menu
{
public:
	PrintTransactions(Store & store, SortBy sortBy);
	PrintTransactions(Store & store, Customer * customer);
	PrintTransactions(Store & store, const Date & date);
	PrintTransactions(Store & store, const Date & date1, const Date & date2);

	virtual MenuResult handle();

private:
	Store & store;
	SortBy sortBy;
	ShowBy showBy;
	Customer * customer = nullptr;
	Date date1, date2;
};