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
	for (auto const & i : store.getProductsIdMap())
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

PrintCustomers::PrintCustomers(Store & store, Customer * customer) :
	store(store), customer(customer)
{

}

MenuResult PrintCustomers::handle()
{
	if (customer != nullptr)
	{
			cout << "ID: ";
			cout << (*customer).getId() << endl;
			cout << "Name: ";
			cout << (*customer).getName() << endl;
			cout << "Join date: ";
			cout << (*customer).getJoinDate() << endl;
			cout << "Total cost: ";
			cout << fixed << setprecision(2) << (*customer).getTotalCost() << endl << endl;
	}
	else if (sortBy == ID)
	{
		for (auto const & i : store.getCustomersIdMap())
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
		for (auto const & i : store.getCustomersNameMap())
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
	else if (sortBy == DATE)
	{
		list <Customer> customers = store.getAllCustomers();
		customers.sort([](const Customer & a, const Customer & b) { return a.getJoinDate() < b.getJoinDate(); });
		for (auto const & i : customers)
		{
			if (i.getActiveStatus())
			{
				cout << "ID: ";
				cout << i.getId() << endl;
				cout << "Name: ";
				cout << i.getName() << endl;
				cout << "Join date: ";
				cout << i.getJoinDate() << endl;
				cout << "Total cost: ";
				cout << fixed << setprecision(2) << i.getTotalCost() << endl << endl;
			}
		}
	}
	else if (sortBy == COST)
	{
		list <Customer> customers = store.getAllCustomers();
		customers.sort([](const Customer & a, const Customer & b) { return a.getTotalCost() < b.getTotalCost(); });
		size_t count = 0;

		for (const Customer & i : customers)
		{
			if (i.getActiveStatus())
			{
				cout << "ID: ";
				cout << i.getId() << endl;
				cout << "Name: ";
				cout << i.getName() << endl;
				cout << "Join date: ";
				cout << i.getJoinDate() << endl;
				cout << "Total cost: ";
				cout << fixed << setprecision(2) << i.getTotalCost() << endl << endl;
			}

			count++;

			if (count >= 10 || count >= customers.size())
			{
				break;
			}
		}
	}

	pause();
	return CONTINUE;
}

PrintTransactions::PrintTransactions(Store & store, SortBy sortBy) :
	store(store), showBy(ALL), sortBy(sortBy)
{

}

PrintTransactions::PrintTransactions(Store & store, Customer * customer) :
	store(store), customer(customer), showBy(CUSTOMER)
{

}

PrintTransactions::PrintTransactions(Store & store, const Date & date) :
	store(store), date1(date), showBy(DAY)
{

}

PrintTransactions::PrintTransactions(Store & store, const Date & date1, const Date & date2) :
	store(store), date1(date1), date2(date2), showBy(PERIOD)
{

}

MenuResult PrintTransactions::handle()
{
	list <Transaction> transactions;
	if (showBy == CUSTOMER)
	{
		for (const Transaction & i : store.getAllTransactions())
		{
			if (&(i.getCustomer()) == customer)
			{
				transactions.push_back(i);
			}
		}
	}
	else if (showBy == DAY)
	{
		for (const Transaction & i : store.getAllTransactions())
		{
			if (i.getDate() == date1)
			{
				transactions.push_back(i);
			}
		}
	}
	else if (showBy == PERIOD)
	{
		for (const Transaction & i : store.getAllTransactions())
		{
			if (i.getDate() >= date1 && i.getDate() <= date2)
			{
				transactions.push_back(i);
			}
		}
	}
	else if (showBy == ALL)
	{
		transactions = store.getAllTransactions();
	}

	if (sortBy == DATE)
	{
		transactions.sort([](const Transaction & a, const Transaction & b) { return a.getDate() < b.getDate(); });
	}

	for (const Transaction & i : transactions)
	{
		cout << "Customer ID: ";
		cout << i.getCustomer().getId() << endl;
		cout << "Transaction date: ";
		cout << i.getDate() << endl;
		cout << "Products: ";
		for (const Product * j : i.products)
		{
			cout << (*j).getName();

			if (j != *(i.products.rbegin()))
			{
				cout << ", ";
			}
		}
		cout << endl << endl;
	}

	pause();
	return CONTINUE;
}
