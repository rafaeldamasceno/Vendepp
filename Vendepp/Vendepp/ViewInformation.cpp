#include "ViewInformation.h"

ViewAllCustomers::ViewAllCustomers(Store & store) :
	store(store)
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("Sort by ID", exitHandler));
	entries.push_back(MenuEntry("Sort by Name", exitHandler));
}

ViewCustomers::ViewCustomers(Store & store) :
	store(store)
{
	ViewAllCustomers viewAllCustomers(store);

	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("View single customer", exitHandler));
	entries.push_back(MenuEntry("View all customers", viewAllCustomers));
	entries.push_back(MenuEntry("View Bottom10", exitHandler));
}

ViewTransactions::ViewTransactions(Store & store) :
	store(store)
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("View customer transactions", exitHandler));
	entries.push_back(MenuEntry("View day transactions", exitHandler));
	entries.push_back(MenuEntry("View period transactions", exitHandler));
	entries.push_back(MenuEntry("View all transactions", exitHandler));
}

ViewInformation::ViewInformation(Store & store) :
	store(store)
{
	ViewCustomers viewCustomers(store);
	ViewTransactions viewTransactions(store);

	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("View customers", viewCustomers));
	entries.push_back(MenuEntry("View products", exitHandler));
	entries.push_back(MenuEntry("View transactions", viewTransactions));
}