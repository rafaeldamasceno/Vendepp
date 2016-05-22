#include "ManageCustomers.h"

#include <iostream>
#include <iomanip>
#include <ctime>

#include "utils.h"

AddCustomer::AddCustomer(Store & store) :
	store(store)
{

}

MenuResult AddCustomer::handle()
{
	time_t today = time(NULL);
	struct tm *time;
	time = localtime(&today);
	int day, month, year;
	day = time->tm_mday;
	month = time->tm_mon + 1;
	year = time->tm_year + 1900;

	Date todayDate(day, month, year);
	int id = store.getAvailableId();
	string name;
	cin.clear();
	cin.ignore(INT64_MAX, '\n');
	cout << "Insert customer name: ";
	getline(cin, name);
	Customer customer(id, name, todayDate, 0.00);
	store.addCustomer(customer);
	cout << "The customer has been added.\n";
	cout << "\nID: " << customer.getId() << "\nName: " << customer.getName() << "\nJoin date: " << customer.getJoinDate() << "\nAmount: " << fixed << setprecision(2) << customer.getTotalCost() << endl;
	pause();
	return CONTINUE;
}

EditCustomerName::EditCustomerName(Store & store) :
	store(store)
{

}

MenuResult EditCustomerName::handle()
{
	Customer * customer = readCustomerId(store);
	cin.clear();
	cin.ignore(INT64_MAX, '\n');
	cout << "Insert the new name: ";
	string name;
	getline(cin, name);
	customer->setName(name);
	store.writeCustomers();
	cout << "The customer's name has been changed to: " << name << ".\n";
	pause();
	return CONTINUE;
}

EditCustomer::EditCustomer(Store & store) :
	editCustomerName(store)
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("Edit name", editCustomerName));
}

RemoveCustomer::RemoveCustomer(Store & store) :
	store(store)
{
}

MenuResult RemoveCustomer::handle()
{
	Customer* customer = readCustomerId(store);
	cin.clear();
	cin.ignore(INT64_MAX, '\n');
	cout << "\nID: " << customer->getId() << "\nName: " << customer->getName() << "\nJoin date: " << customer->getJoinDate() << "\nAmount: " << fixed << setprecision(2) << customer->getTotalCost() << endl;
	char c;
	cout << "\n\nAre you sure you want to remove this customer?\nInsert Y for YES or anything else to cancel: ";
	cin >> c;
	cin.clear();
	cin.ignore(INT64_MAX, '\n');
	c = tolower(c);
	if (c == 'y')
	{
		store.deleteCustomer(customer);
		cout << "The customer has been removed.\n";
	}
	pause();
	return CONTINUE;
}

ManageCustomers::ManageCustomers(Store & store) :
	addCustomer(store), editCustomer(store), removeCustomer(store)
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("Add customer", addCustomer));
	entries.push_back(MenuEntry("Edit customer", editCustomer));
	entries.push_back(MenuEntry("Remove customer", removeCustomer));
}