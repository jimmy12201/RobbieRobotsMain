#pragma once
#ifndef __ORDERS_H
#define __ORDERS_H 2016
#include <ctime>
#include "robotModels.h"
#include "SalesAssociate.h"
#include "Customers.h"
class order {
public:
	void createOrder(int orderNumber, int month, int day, int year, double askingPrice, salesAssociate &salesAssociateOrderT, customer &customerNameOrderT, robotModels &selcetedModelT);
	void generateBOS();
	string getRobotName();
	double getRobotPrice();
	double getRobotCost();
	double getRobotTotalPrice();
	int getYear();
	int getDay();
	int getMonth();
	string getAssociate();
	string getCustomer();
private:
	int selection, i, day, month, year, orderNumber;
	double price, location,askingPrice, overallRobotPrice;
	customer *customerNameOrder;
	salesAssociate *salesAssociateOrder;
	robotModels *selectedModel;

};
#endif