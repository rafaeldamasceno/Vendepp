#pragma once

#include "Menu.h"

class Advertisement : public Menu {
public:
	Advertisement(Store & store);

	ExitHandler exitHandler;
private:
	Store & store;
};