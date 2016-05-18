#include "Transaction.h"

Transaction::Transaction(Customer & customer, Date date) :
	customer(customer), date(date)
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
string Transaction::getStringDate() const
{
	return date.writeDate();
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
	out << t.getStringDate() << " ; ";
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