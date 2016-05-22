#pragma once

#include <iostream>
#include "Menu.h"


class AddTransaction : public Menu {
public:
	AddTransaction(Store & store);

	virtual MenuResult handle();
private:
	Store & store;
};