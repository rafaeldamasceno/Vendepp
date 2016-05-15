#include "ViewInformation.h"

ViewAllCustomers::ViewAllCustomers()
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("Sort by ID", exitHandler));
	entries.push_back(MenuEntry("Sort by Name", exitHandler));
}

ViewCustomers::ViewCustomers()
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("View single customer", exitHandler));
	entries.push_back(MenuEntry("View all customers", viewAllCustomers));
	entries.push_back(MenuEntry("View Bottom10", exitHandler));
}

ViewTransactions::ViewTransactions()
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("View customer transactions", exitHandler));
	entries.push_back(MenuEntry("View day transactions", exitHandler));
	entries.push_back(MenuEntry("View period transactions", exitHandler));
	entries.push_back(MenuEntry("View all transactions", exitHandler));
}

ViewInformation::ViewInformation()
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("View customers", viewCustomers));
	entries.push_back(MenuEntry("View products", exitHandler));
	entries.push_back(MenuEntry("View transactions", viewTransactions));
}