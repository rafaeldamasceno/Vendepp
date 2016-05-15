#pragma once

#include <string>

#include "common.h"

using namespace std;

class Customer
{
public:
	Customer();
	Customer(unsigned int id, string name, Date joinDate, Cost totalCost=0, bool active = true);

	string getName() const;
	unsigned int getId() const;
	Date getJoinDate() const;
	Cost getTotalCost() const;
	bool getActiveStatus() const;

	void setName(const string & name);
	void setId(const unsigned int & id);
	void setJoinDate(const Date & joinDate);
	void setTotalCost(const Cost & totalCost);
	void setActiveStatus(const bool & active);

	bool operator < (const Customer & p) const;

	friend istream & operator >> (istream & in, Customer & c);

private:
	unsigned int id;
	string name;
	Date joinDate;
	Cost totalCost;
	bool active;
};

ostream & operator << (ostream & out, const Customer & c);
istream & operator >> (istream & in, Customer & c);

