#pragma once

#include "Menu.h"

class ViewAllCustomers : public Menu {
public:
	ViewAllCustomers(Store & store);

	ExitHandler exitHandler;
private:
	Store & store;
};

class ViewCustomers : public Menu {
public:
	ViewCustomers(Store & store);

	ExitHandler exitHandler;
private:
	Store & store;
};

class ViewTransactions : public Menu {
public:
	ViewTransactions(Store & store);

	ExitHandler exitHandler;
private:
	Store & store;
};

class ViewInformation : public Menu {
public:
	ViewInformation(Store & store);

	ExitHandler exitHandler;
private:
	Store & store;
};