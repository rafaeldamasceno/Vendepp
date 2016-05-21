#include "ViewInformation.h"
#include "utils.h"

#include <iostream>
#include <iomanip>

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

PrintProducts::PrintProducts(Store & store) : 
	store(store)
{

}

MenuResult PrintProducts::handle()
{
	for (auto const & i : store.getAllProducts())
	{
		cout << "Name: ";
		cout << (*(i.second)).getName() << endl;
		cout << "Cost: ";
		cout << fixed << setprecision(2) << (*(i.second)).getCost() << endl << endl;
	}

	pause();
	return CONTINUE;
}

PrintCustomers::PrintCustomers(Store & store, SortBy sortBy) :
	store(store), sortBy(sortBy)
{
	
}

MenuResult PrintCustomers::handle()
{
	if (sortBy == ID)
	{
		for (auto const & i : store.getAllCustomersById())
		{
			if((*(i.second)).getActiveStatus())
			{
				cout << "ID: ";
				cout << (*(i.second)).getId() << endl;
				cout << "Name: ";
				cout << (*(i.second)).getName() << endl;
				cout << "Join date: ";
				cout << (*(i.second)).getJoinDate() << endl;
				cout << "Total cost: ";
				cout << fixed << setprecision(2) << (*(i.second)).getTotalCost() << endl << endl;
			}
		}
	}
	else if (sortBy == NAME)
	{
		for (auto const & i : store.getAllCustomersByName())
		{
			if ((*(i.second)).getActiveStatus())
			{
				cout << "ID: ";
				cout << (*(i.second)).getId() << endl;
				cout << "Name: ";
				cout << (*(i.second)).getName() << endl;
				cout << "Join date: ";
				cout << (*(i.second)).getJoinDate() << endl;
				cout << "Total cost: ";
				cout << fixed << setprecision(2) << (*(i.second)).getTotalCost() << endl << endl;
			}
		}
	}

	pause();
	return CONTINUE;
}