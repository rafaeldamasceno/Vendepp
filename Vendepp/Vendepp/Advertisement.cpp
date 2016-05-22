#include "Advertisement.h"

#include <algorithm>
#include <iostream>

#include "utils.h"

Advertisement::Advertisement(Store & store) :
	store(store)
{
	CustomerAdvertisement customerAdvertisement(store);

	entries.push_back(MenuEntry("Back", Menu::exitHandler));
	entries.push_back(MenuEntry("Advertise to customer", customerAdvertisement));
	entries.push_back(MenuEntry("Bottom10 campaign", Menu::exitHandler));
}

CustomerAdvertisement::CustomerAdvertisement(Store & store) :
	store(store)
{
	
}

MenuResult CustomerAdvertisement::handle()
{
	Customer * customer = readCustomerId(store);
	vector <vector <bool>> hasBoughtProduct;

	hasBoughtProduct.resize(store.getAllCustomers().size(), vector<bool>(store.getProductsIdMap().size(), false));

	vector <vector <unsigned int>> productsBought;

	productsBought.resize(hasBoughtProduct.size());

	map <unsigned int, unsigned int> idToLine;

	auto pointerToPosition = store.getProductsPointerMap();

	unsigned int line = 0;

	for (const Customer &i : store.getAllCustomers())
	{
		idToLine[i.getId()] = line;
		line++;
	}

	for (const Transaction &i : store.getAllTransactions())
	{
		unsigned int customerLine = idToLine[i.getCustomer().getId()];

		for (Product * j : i.products)
		{
			hasBoughtProduct[customerLine][pointerToPosition[j]] = true;

			auto result = find(productsBought[customerLine].begin(), productsBought[customerLine].end(), pointerToPosition[j]);

			if (result == productsBought[customerLine].end())
			{
				productsBought[customerLine].push_back(pointerToPosition[j]);
			}
		}
	}

	vector <unsigned int> similarClients;

	unsigned int targetProducts = productsBought[idToLine[customer->getId()]].size();

	while (!similarClients.size() && targetProducts)
	{
		for (size_t i = 0; i < hasBoughtProduct.size(); i++)
		{
			bool hasDifferentProduct = false;

			for (const unsigned int &product : productsBought[i])
			{
				if (find(productsBought[idToLine[customer->getId()]].begin(), productsBought[idToLine[customer->getId()]].end(), product) == productsBought[idToLine[customer->getId()]].end())
				{
					hasDifferentProduct = true;
					break;
				}
			}
			if (i != idToLine[customer->getId()] && hasDifferentProduct)
			{
				unsigned int equalProducts = 0;
				for (size_t j = 0; j < pointerToPosition.size(); j++)
				{
					if (hasBoughtProduct[i][j] && hasBoughtProduct[idToLine[customer->getId()]][j])
					{
						equalProducts++;
					}
				}
				if (equalProducts == targetProducts)
				{
					similarClients.push_back(i);
				}
			}
		}

		targetProducts--;
	}
	if (similarClients.size())
	{
		vector <unsigned int> productOccurrences(pointerToPosition.size(), 0);
		for (const unsigned int &i : similarClients)
		{
			for (const int &j : productsBought[i])
			{
				if (find(productsBought[idToLine[customer->getId()]].begin(), productsBought[idToLine[customer->getId()]].end(), j) == productsBought[idToLine[customer->getId()]].end())
				{
					productOccurrences[j]++;
				}
			}
		}

		cout << "The best recommendation for this customer is \"" << store.getProductsIdMap().at(maxElementIndex(productOccurrences))->getName() << "\"." << endl;
	}
	else
	{
		cout << "There are no good recommendations for this customer." << endl;
	}

	pause();

	return CONTINUE;
}
