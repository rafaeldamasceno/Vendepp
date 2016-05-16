#include "Transaction.h"

Transaction::Transaction(Customer & customer, Date date) :
	customer(customer), date(date)
{

}

Transaction::Transaction()
{
	
}

Customer & Transaction::getCustomer() const
{
	return customer;
}
Date Transaction::getDate() const
{
	return date;
}

void Transaction::SetCustomer(const Customer & customer)
{
	this->customer = customer;
}

void Transaction::SetDate(const Date & date)
{
	this->date = date;
}

ostream & operator << (ostream & out, const Transaction & t)
{
	out << t.getCustomer().getId() << " ; ";
	out << t.getDate() << " ; ";
	for (const Product * i : t.products)
	{
		out << *i;
		if (&i != &t.products.back())
		{
			out << ", ";
		}
	}
	return out;
}