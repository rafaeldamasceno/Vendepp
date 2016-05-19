#pragma once

#include "Menu.h"

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