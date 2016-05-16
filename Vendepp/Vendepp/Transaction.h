#pragma once

#include <string>
#include <list>

#include "Customer.h"
#include "Product.h"
#include "common.h"

using namespace std;


class Transaction
{
public:
	Transaction(Customer & customer, Date date);
	Customer & getCustomer() const;
	Date getDate() const;
	void SetCustomer(const Customer & customer);
	void SetDate(const Date & date);

public:	
	list <Product *> products;
private:
	Customer & customer;
	Date date;
};


ostream & operator << (ostream & out, const Transaction & t);
