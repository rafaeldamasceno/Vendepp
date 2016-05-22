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

class AddCustomer : public Menu {

public:
	AddCustomer(Store & store);

	virtual MenuResult handle();
private:
	Store & store;

};

class RemoveCustomer : public Menu {

public:
	RemoveCustomer(Store & store);

	virtual MenuResult handle();
private:
	Store & store;

};

class EditCustomerName : public Menu {

public:
	EditCustomerName(Store & store);

	virtual MenuResult handle();
private:
	Store & store;

};
