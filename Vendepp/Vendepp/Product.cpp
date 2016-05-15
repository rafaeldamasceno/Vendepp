#include "Product.h"

#include <iostream>
#include <iomanip>

Product::Product()
{

}

Product::Product(string name, Cost cost) :
	name(name), cost(cost)
{

}

bool Product::operator < (const Product & p) const
{
	return name < p.name;
}

string Product::getName() const
{
	return name;
}

Cost Product::getCost() const
{
	return cost;
}

ostream & operator << (ostream & out, const Product & p)
{
	out << p.getName() << " ; ";
	out << fixed << setprecision(2) << p.getCost();
	return out;
}

istream & operator >> (istream & in, Product & p)
{
	getline(in, p.name, ';');
	p.name.pop_back();
	in.ignore();
	in >> p.cost;
	return in;
}