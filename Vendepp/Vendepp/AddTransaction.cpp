#include "AddTransaction.h"

#include <algorithm>
#include <iomanip>

AddTransaction::AddTransaction(Store & store) : 
store(store)
{

}

MenuResult AddTransaction::handle()
{
	// pedir id
	Customer * customer = readCustomerId(store);
	cin.clear();
	cin.ignore(INT64_MAX, '\n');
	// pedir data
	//OneDateProcessor oneDateProcessor("Insert date (DD/MM/YYYY): ", "ERROR: Date not valid.");
	Date date(1, 1, 1);
	// criar a transação

	Transaction transaction(*customer, date);
	// ler produtos
	cout << "\nID: " << customer->getId() << "\nName: " << customer->getName() << "\nJoin date: " << customer->getJoinDate() << "\nAmount: " << fixed << setprecision(2) << customer->getTotalCost() << endl;
	cout << "To stop inserting products, press enter.\n";
	while (true)
	{
		Product * product = readProductName(store);

		if (product == nullptr)
		{
			break;
		}
		if (find(transaction.products.begin(), transaction.products.end(), product) != transaction.products.end())
		{
			cout << "ERROR: Product already added." << endl;
			continue;
		}

		transaction.products.push_back(product);
	}

	store.addTransaction(transaction);
	cout << "The transaction has been added.\n";
	return CONTINUE;
}