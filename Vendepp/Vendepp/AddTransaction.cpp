#include "AddTransaction.h"

#include <algorithm>

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
	while (true)
	{
		Product * product = readProductName(store);

		if (product == nullptr)
		{
			break;
		}
		auto result = find(transaction.products.begin(), transaction.products.end(), product);
		if (result != transaction.products.end())
		{
			cout << "ERROR: Product already added." << endl;
			continue;
		}

		transaction.products.push_back(product);
	}

	store.addTransaction(transaction);

	return CONTINUE;
}