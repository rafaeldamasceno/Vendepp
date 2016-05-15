#include "Menu.h"

#include "AddTransaction.h"
#include "ManageCustomers.h"
#include "ViewInformation.h"
#include "Advertisement.h"

class DateProcessor : public MenuHandler {
protected:
	Date readDate(string prompt) {
		
		return "xxxx";
	}
};

class OneDateProcessor : public DateProcessor {
public:

	virtual MenuResult handle() {
		Date date = readDate("xxxx");

		return handle(date);
	}

	virtual MenuResult handle(Date date) = 0;
};

class TwoDateProcessor : public DateProcessor {
public:

	virtual MenuResult handle() {
		Date date1 = readDate("xxxx");
		Date date2 = readDate("xxxx");

		return handle(date1, date2);
	}

	virtual MenuResult handle(Date date1, Date date2) = 0;
};

int main()
{
	Menu menu;
	AddTransaction addTransaction;
	ManageCustomers manageCustomers;
	ViewInformation viewInformation;
	Advertisement advertisement;
	ExitHandler exitHandler;

	menu.entries.push_back(MenuEntry("Exit", exitHandler));
	menu.entries.push_back(MenuEntry("Add transaction", addTransaction));
	menu.entries.push_back(MenuEntry("Manage customers", manageCustomers));
	menu.entries.push_back(MenuEntry("View information", viewInformation));
	menu.entries.push_back(MenuEntry("Advertisement", advertisement));

	

	menu.handle();

	return 0;
}