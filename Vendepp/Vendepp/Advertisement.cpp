#include "Advertisement.h"

Advertisement::Advertisement()
{
	entries.push_back(MenuEntry("Back", exitHandler));
	entries.push_back(MenuEntry("Advertise customer", exitHandler));
	entries.push_back(MenuEntry("Bottom10 campaign", exitHandler));
}