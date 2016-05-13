#include "Menu.h"

#include <iostream>

MenuResult ExitHandler::handle()
{
	return EXIT;
}

MenuResult Menu::handle()
{

	while (true)
	{
		unsigned int option;
		printMenu();
		cin >> option;

		if (!cin.good())
		{
			string s;
			cin.clear();
			getline(cin, s);
			invalidOption(s);
			continue;
		}

		if (option >= entries.size())
		{
			invalidOption(option);
			continue;
		}

		MenuHandler &handler = entries[option].second;
		MenuResult res = handler.handle();

		if (res == EXIT)
		{
			break;
		}

	}
	return EXIT;
}

void Menu::invalidOption(int opt)
{
	cout << "The option \"" << opt << "\" is invalid." << endl;
}

void Menu::invalidOption(string opt)
{
	cout << "The option \"" << opt << "\" is invalid." << endl;
}


void Menu::printMenu() const
{
	for (size_t i = 0; i < entries.size(); i++)
	{
		cout << i << " " << entries[i].first << endl;
	}
}
