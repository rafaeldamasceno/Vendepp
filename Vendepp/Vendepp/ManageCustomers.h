#pragma once

#include "Menu.h"

class EditCustomer : public Menu {
public:
	EditCustomer(Store & store);

private:
	Store & store;
};

class ManageCustomers : public Menu {
public:
	ManageCustomers(Store & store);

private:
	Store & store;
};
