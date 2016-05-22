#pragma once

#include "Menu.h"

class AddCustomer : public Menu {

public:
	AddCustomer(Store & store);

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

class EditCustomer : public Menu {
public:
	EditCustomer(Store & store);

private:
	EditCustomerName editCustomerName;
};

class RemoveCustomer : public Menu {

public:
	RemoveCustomer(Store & store);

	virtual MenuResult handle();
private:
	Store & store;

};

class ManageCustomers : public Menu {
public:
	ManageCustomers(Store & store);

private:
	AddCustomer addCustomer;
	EditCustomer editCustomer;
	RemoveCustomer removeCustomer;
};
