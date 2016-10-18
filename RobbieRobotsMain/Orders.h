#pragma once
#ifndef __ORDERS_H
#define __ORDERS_H 2016
#include <ctime>
#include "robotModels.h"
#include "Shop.h"
class order {
public:
	int ub;
	
private:
	double orderNumber;
	string CustomerNameOrder;
	robotModel selectedModel;
	time_t time;
	double price;
	double shipping;

};
#endif