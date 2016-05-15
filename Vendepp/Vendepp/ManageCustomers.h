#pragma once

#include "Menu.h"

class EditCustomer : public Menu {
public:
	EditCustomer();

	ExitHandler exitHandler;
};

class ManageCustomers : public Menu {
public:
	ManageCustomers();

	EditCustomer editCustomer;
	ExitHandler exitHandler;
};
