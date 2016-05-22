#include "AddTransaction.h"

AddTransaction::AddTransaction(Store & store) : 
store(store)
{

}

MenuResult AddTransaction::handle()
{
	// pedir id
	Customer * customer = readCustomerId(store);
	// pedir data
	Date date;

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
		// verifica aqui se o produto já existe na lista ali de cima. usa .find() != products.end();


		transaction.products.push_back(product);
	}

	store.addTransaction(transaction);

	return CONTINUE;
}