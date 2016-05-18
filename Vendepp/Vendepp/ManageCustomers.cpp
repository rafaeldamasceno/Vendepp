#include "ManageCustomers.h"

EditCustomer::EditCustomer(Store & store) :
	store(store)
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("Edit name", exitHandler));
}

ManageCustomers::ManageCustomers(Store & store) :
	store(store)
{
	EditCustomer editCustomer(store);

	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("Add customer", exitHandler));
	entries.push_back(MenuEntry("Edit customer", editCustomer));
	entries.push_back(MenuEntry("Remove customer", exitHandler));
}