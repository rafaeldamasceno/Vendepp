#include <sstream>

#include "Menu.h"

#include "AddTransaction.h"
#include "ManageCustomers.h"
#include "ViewInformation.h"
#include "Advertisement.h"
#include "Store.h"

int main()
{
	Store store;

	store.askFileNames("customers.txt", "products.txt", "transactions.txt");
	store.load();

	Menu menu;
	AddTransaction addTransaction(store);
	ManageCustomers manageCustomers(store);
	ViewInformation viewInformation(store);
	Advertisement advertisement(store);

	
	menu.entries.push_back(MenuEntry("Exit", Menu::exitHandler));
	menu.entries.push_back(MenuEntry("Add transaction", addTransaction));
	menu.entries.push_back(MenuEntry("Manage customers", manageCustomers));
	menu.entries.push_back(MenuEntry("View information", viewInformation));
	menu.entries.push_back(MenuEntry("Advertisement", advertisement));

	menu.handle();

	return 0;
}

