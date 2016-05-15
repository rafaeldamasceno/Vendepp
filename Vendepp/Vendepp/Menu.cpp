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
		
		cout << endl << "Choose an option: ";
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

	return CONTINUE;
}

void Menu::invalidOption(int opt)
{
	cout << endl << "ERROR: The option \"" << opt << "\" is invalid." << endl;
}

void Menu::invalidOption(string opt)
{
	cout << endl << "ERROR: The option \"" << opt << "\" is invalid." << endl;
}


void Menu::printMenu() const
{
	for (size_t i = 1; i < entries.size(); i++)
	{
		cout << i << ". " << entries[i].first << endl;
	}
	cout << endl << 0 << ". " << entries[0].first << endl;
}