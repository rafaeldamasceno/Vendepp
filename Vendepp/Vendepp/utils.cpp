#include "utils.h"

#include <iostream>
#include <string>

using namespace std;

void pause()
{
	cout << "Press enter to continue . . . ";
	cin.get();
}

void header()
{
	cout << "   _____                   __  __            _        _   \n  / ____|                 |  \\/  |          | |      | |  \n | (___  _   _ _ __   __ _| \\  / | __ _ _ __| | _____| |_ \n  \\___ \\| | | | '_ \\ / _` | |\\/| |/ _` | '__| |/ / _ \\ __|\n  ____) | |_| | |_) | (_| | |  | | (_| | |  |   <  __/ |_ \n |_____/ \\__,_| .__/ \\__,_|_|  |_|\\__,_|_|  |_|\\_\\___|\\__|\n              | |                                         \n              |_|                                         \n";
}

unsigned int maxElementIndex(const vector <unsigned int> &vector)
{
	unsigned int position = 0, maxPosition = 0;
	for (const int &i : vector)
	{
		if (i > vector.at(maxPosition))
		{
			maxPosition = position;
		}
		position++;
	}
	return maxPosition;
}