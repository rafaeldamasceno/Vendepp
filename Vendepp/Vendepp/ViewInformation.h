#pragma once

#include "Menu.h"

class ViewAllCustomers : public Menu {
public:
	ViewAllCustomers();

	ExitHandler exitHandler;
};

class ViewCustomers : public Menu {
public:
	ViewCustomers();

	ViewAllCustomers viewAllCustomers;
	ExitHandler exitHandler;
};

class ViewTransactions : public Menu {
public:
	ViewTransactions();

	ExitHandler exitHandler;
};

class ViewInformation : public Menu {
public:
	ViewInformation();

	ViewCustomers viewCustomers;
	ViewTransactions viewTransactions;
	ExitHandler exitHandler;
};