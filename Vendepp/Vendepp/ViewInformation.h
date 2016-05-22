#pragma once

#include "Menu.h"

enum SortBy
{
	ID, DATE, NAME, COST
};

enum ShowBy
{
	ALL, CUSTOMER, DAY, PERIOD, BOTTOM10
};

class PrintCustomers : public Menu
{
public:
	PrintCustomers(Store & store, SortBy sortBy);
	PrintCustomers(Store & store, Customer * customer);
	PrintCustomers(Store & store, ShowBy showBy);


	virtual MenuResult handle();

private:
	Store & store;
	SortBy sortBy;
	ShowBy showBy;
	Customer * customer = nullptr;

};

class PrintProducts : public Menu {
public:
	PrintProducts(Store & store);

	virtual MenuResult handle();

private:
	Store & store;
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

class ViewSingleCustomer : public Menu {
public:
	ViewSingleCustomer(Store & store);
	virtual MenuResult handle();
private:
	Store & store;
};

class ViewAllCustomersById : public Menu {
public:
	ViewAllCustomersById(Store & store);
	virtual MenuResult handle();
private:
	Store & store;
};

class ViewAllCustomersByName : public Menu {
public:
	ViewAllCustomersByName(Store & store);
	virtual MenuResult handle();
private:
	Store & store;
};

class ViewAllCustomers : public Menu {
public:
	ViewAllCustomers(Store & store);
private:
	ViewAllCustomersById viewAllCustomersById;
	ViewAllCustomersByName viewAllCustomersByName;
};

class ViewBottom10Customers : public Menu {
public:
	ViewBottom10Customers(Store & store);
	virtual MenuResult handle();
private:
	PrintCustomers printBottom10Customers;
};

class ViewCustomerTransactions : public Menu {
public:
	ViewCustomerTransactions(Store & store);
	virtual MenuResult handle();
private:
	Store & store;
};

class ViewDayTransactions : public Menu {
public:
	ViewDayTransactions(Store & store);
	virtual MenuResult handle();
private:
	Store & store;
};

class ViewPeriodTransactions : public Menu {
public:
	ViewPeriodTransactions(Store & store);
	virtual MenuResult handle();
private:
	Store & store;
};

class ViewAllTransactions : public Menu {
public:
	ViewAllTransactions(Store & store);
	virtual MenuResult handle();
private:
	PrintTransactions printAllTransactions;
};

class ViewCustomers : public Menu {
public:
	ViewCustomers(Store & store);

private:
	ViewSingleCustomer viewSingleCustomer;
	ViewAllCustomers viewAllCustomers;
	ViewBottom10Customers viewBottom10Customers;
};

class ViewTransactions : public Menu {
public:
	ViewTransactions(Store & store);

private:
	ViewCustomerTransactions viewCustomerTransactions;
	ViewDayTransactions viewDayTransactions;
	ViewPeriodTransactions viewPeriodTransactions;
	ViewAllTransactions viewAllTransactions;
};

class ViewInformation : public Menu {
public:
	ViewInformation(Store & store);

private:
	ViewCustomers viewCustomers;
	PrintProducts printProducts;
	ViewTransactions viewTransactions;
};