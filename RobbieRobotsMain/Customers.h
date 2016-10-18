#pragma once
#ifndef __CUSTOMERS_H
#define __CUSTOMERS_H 2016
#include <vector>
#include <iostream>
//#include "Shop.h"
using namespace std;
class customer {
public:
	void createCustomer(string name);
	string getName();

private:
	string customerName;
};
#endif