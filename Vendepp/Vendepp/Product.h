#pragma once

#include <string>

#include "common.h"

using namespace std;

class Product
{
public:
	Product();
	Product(string name, Cost cost);
	string getName() const;
	Cost getCost() const;

	bool operator < (const Product & p) const;

	friend istream & operator >> (istream & in, Product & p);
private:
	string name;
	Cost cost;
};

ostream & operator << (ostream & out, const Product & p);
istream & operator >> (istream & in, Product & p);