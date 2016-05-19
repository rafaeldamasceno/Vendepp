#pragma once

#include <iostream>
#include "Menu.h"


class AddTransaction : public Menu {
public:
	AddTransaction(Store & store);

	MenuResult handle();
private:
	Store & store;
};