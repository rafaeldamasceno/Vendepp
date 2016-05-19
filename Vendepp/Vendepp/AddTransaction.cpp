#include "AddTransaction.h"

AddTransaction::AddTransaction(Store & store) : 
store(store)
{

}

MenuResult AddTransaction::handle()
{
	return CONTINUE;
}