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