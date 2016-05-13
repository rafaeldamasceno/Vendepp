#pragma once

#include <map>

#include "Product.h"

using namespace std;

class Store
{
public:
	Store();

private:
	map <string, Product> products;
};