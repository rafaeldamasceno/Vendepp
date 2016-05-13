#include "Menu.h"

int main()
{
	Menu menu;
	ExitHandler exitHandler;

	menu.entries.push_back(MenuEntry("Exit", exitHandler));
	menu.entries.push_back(MenuEntry("Exit", exitHandler));

	menu.handle();

	return 0;
}