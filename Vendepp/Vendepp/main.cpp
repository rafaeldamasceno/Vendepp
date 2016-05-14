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

class SubMenu1 : public Menu {
public:
	SubMenu1() {
		entries.push_back(MenuEntry("Exit 1", exitHandler));
		entries.push_back(MenuEntry("Exit 2", exitHandler));
	}

	ExitHandler exitHandler;
};


int main()
{
	Menu menu;
	SubMenu1 submenu;
	ExitHandler exitHandler;

	menu.entries.push_back(MenuEntry("Submenu", submenu));
	menu.entries.push_back(MenuEntry("Exit", exitHandler));

	menu.handle();

	return 0;
}