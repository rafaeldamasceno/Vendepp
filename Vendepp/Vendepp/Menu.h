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
	static ExitHandler exitHandler;
	vector <MenuEntry> entries;
};

class OneDateProcessor : public MenuHandler {
public:
	OneDateProcessor(const string & prompt, const string & error);
	Date readDate(const string & prompt, const string & error);
	virtual MenuResult handle();

protected:
	virtual MenuResult handle(Date date) = 0;

	string error;
	string prompt1;
};

class TwoDateProcessor : public OneDateProcessor {
public:
	TwoDateProcessor(const string & prompt1, const string & prompt2, const string & error);

protected:
	virtual MenuResult handle(Date date1, Date date2) = 0;
	virtual MenuResult handle(Date date1);

	string prompt2;
};

Customer * readCustomerId(Store & store);
Product * readProductName(Store & store);
