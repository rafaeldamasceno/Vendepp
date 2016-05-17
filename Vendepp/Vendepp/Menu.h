#pragma once

#include <vector>
#include <string>

#include "common.h"
#include "Store.h"

using namespace std;

enum MenuResult
{
	EXIT, CONTINUE, ERROR
};

class MenuHandler
{
public:
	virtual MenuResult handle() = 0;
	inline virtual ~MenuHandler() {};
private:

};

typedef pair <string, MenuHandler&> MenuEntry;

class ExitHandler : public MenuHandler
{
public:
	virtual MenuResult handle();
};

class Menu : public MenuHandler
{
public:
	virtual MenuResult handle();
	virtual void invalidOption(int opt);
	virtual void invalidOption(string opt);
protected:
	void printMenu() const;
public:
	vector <MenuEntry> entries;

};