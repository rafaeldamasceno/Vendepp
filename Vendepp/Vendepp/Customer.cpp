#include "Customer.h"

#include <iostream>
#include <iomanip>


Customer::Customer(unsigned int id, string name, Date joinDate, Cost totalCost, bool active) :
	id(id), name(name), joinDate(joinDate), totalCost(totalCost), active(active)
{
}

string Customer::getName() const
{
	return name;
}

unsigned int Customer::getId() const
{
	return id;
}

Date Customer::getJoinDate() const
{
	return joinDate;
}

Cost Customer::getTotalCost() const
{
	return totalCost;
}

bool Customer::getActiveStatus() const
{
	return active;
}

void Customer::setName(const string & name)
{
	this->name = name;
}

void Customer::setId(const unsigned int & id)
{
	this->id = id;
}

void Customer::setJoinDate(const Date & joinDate)
{
	this->joinDate = joinDate;
}

void Customer::setTotalCost(const Cost & totalCost)
{
	this->totalCost = totalCost;
}

void Customer::setActiveStatus(const bool & active)
{
	this->active = active;
}

bool Customer::operator < (const Customer & c) const
{
	return name < c.name;
}

ostream & operator << (ostream & out, const Customer & c)
{
	out << c.getId() << " ; ";
	out << c.getName() << " ; ";
	out << c.getJoinDate() << " ; ";
	out << fixed << setprecision(2) << c.getTotalCost();
	return out;
}

istream & operator >> (istream & in, Customer & c)
{
	in >> c.id;
	in.ignore(3);
	getline(in, c.name, ';');
	c.name.pop_back();
	in >> c.joinDate;
	in.ignore(3);
	in >> c.totalCost;
	return in;
}
