#pragma once

#include "Menu.h"

class CustomerAdvertisement : public Menu {
public:
	CustomerAdvertisement(Store & store);
	virtual MenuResult handle();

private:
	Store & store;
};

//class Bottom10Advertisement : public Menu {
//public:
//	Bottom10Advertisement(Store & store);
//	virtual MenuResult handle();
//
//private:
//	Store & store;
//
//};

class Advertisement : public Menu {
public:
	Advertisement(Store & store);

private:
	CustomerAdvertisement customerAdvertisement;
	//Bottom10Advertisement bottom10Advertisement;
};