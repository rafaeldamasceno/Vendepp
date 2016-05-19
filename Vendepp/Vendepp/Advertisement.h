#pragma once

#include "Menu.h"

class Advertisement : public Menu {
public:
	Advertisement(Store & store);

private:
	Store & store;
};