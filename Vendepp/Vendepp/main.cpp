#include "Menu.h"

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

class SubMenu1AddTransaction : public Menu {
public:
	SubMenu1AddTransaction() {
		entries.push_back(MenuEntry("Back", exitHandler));
	}

	ExitHandler exitHandler;
};


class SubMenu22EditCustomer : public Menu {
public:
	SubMenu22EditCustomer() {
		entries.push_back(MenuEntry("Back", exitHandler));
		entries.push_back(MenuEntry("Edit name", exitHandler));
	}

	ExitHandler exitHandler;
};

class SubMenu2ManageCustomers : public Menu {
public:
	SubMenu2ManageCustomers() {
		entries.push_back(MenuEntry("Back", exitHandler));
		entries.push_back(MenuEntry("Add customer", exitHandler));
		entries.push_back(MenuEntry("Edit customer", editcustomer));
		entries.push_back(MenuEntry("Remove customer", exitHandler));
	}
	SubMenu22EditCustomer editcustomer;
	ExitHandler exitHandler;
};


class SubMenu312ViewAllCustomers : public Menu {
public:
	SubMenu312ViewAllCustomers() {
		entries.push_back(MenuEntry("Back", exitHandler));
		entries.push_back(MenuEntry("Sort by ID", exitHandler));
		entries.push_back(MenuEntry("Sort by Name", exitHandler));
	}

	ExitHandler exitHandler;
};

class SubMenu31ViewCustomers : public Menu {
public:
	SubMenu31ViewCustomers() {
		entries.push_back(MenuEntry("Back", exitHandler));
		entries.push_back(MenuEntry("View single customer", exitHandler));
		entries.push_back(MenuEntry("View all customers", viewallcustomers));
		entries.push_back(MenuEntry("View Bottom10", exitHandler));
	}
	SubMenu312ViewAllCustomers viewallcustomers;
	ExitHandler exitHandler;
};

class SubMenu33ViewTransactions : public Menu {
public:
	SubMenu33ViewTransactions() {
		entries.push_back(MenuEntry("Back", exitHandler));
		entries.push_back(MenuEntry("View customer transactions", exitHandler));
		entries.push_back(MenuEntry("View day transactions", exitHandler));
		entries.push_back(MenuEntry("View period transactions", exitHandler));
		entries.push_back(MenuEntry("View all transactions", exitHandler));
	}
	
	ExitHandler exitHandler;
};

class SubMenu3ViewInformation : public Menu {
public:
	SubMenu3ViewInformation() {
		entries.push_back(MenuEntry("Back", exitHandler));
		entries.push_back(MenuEntry("View customers", viewcustomers));
		entries.push_back(MenuEntry("View products", exitHandler));
		entries.push_back(MenuEntry("View transactions", viewtransactions));
	}
	SubMenu31ViewCustomers viewcustomers;
	SubMenu33ViewTransactions viewtransactions;
	ExitHandler exitHandler;
};

class SubMenu4Advertisement : public Menu {
public:
	SubMenu4Advertisement() {
		entries.push_back(MenuEntry("Back", exitHandler));
		entries.push_back(MenuEntry("Advertise customer", exitHandler));
		entries.push_back(MenuEntry("Bottom10 campaign", exitHandler));
	}

	ExitHandler exitHandler;

};


int main()
{
	Menu menu;
	SubMenu1AddTransaction submenu1addtransaction;
	SubMenu2ManageCustomers submenu2managecustomers;
	SubMenu3ViewInformation submenu3viewinformation;
	SubMenu4Advertisement submenu4advertisement;
	ExitHandler exitHandler;

	menu.entries.push_back(MenuEntry("Exit", exitHandler));
	menu.entries.push_back(MenuEntry("Add Transaction", submenu1addtransaction));
	menu.entries.push_back(MenuEntry("Manage customers", submenu2managecustomers));
	menu.entries.push_back(MenuEntry("View Information", submenu3viewinformation));
	menu.entries.push_back(MenuEntry("Advertisement", submenu4advertisement));

	

	menu.handle();

	return 0;
}