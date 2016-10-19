#pragma once
#ifndef __SHOP_H
#define __SHOP_H 2016
#include <vector>
#include "Robotmodels.h"
#include "Robopart.h"
#include "Customers.h"
#include "Orders.h"
#include "SalesAssociate.h"
class shop{
public:
	void MainMenu();
	void createPart();
	void createModel();
	int createOrder();
	void createCustomers();
	void createSalesAssociate();
	void printRobotInfo();
	void overallSalesReport();
	void datedSalesReport();
	void associateReport();
	void customerReport();
	
private:
	vector<robotModels> completedModels;
	vector<arm> arms;
	vector<torso> torsos;
	vector<head> heads;
	vector<battery>batteries;
	vector<locomotor> locomotors;
	vector<customer> customers;
	vector<salesAssociate> associates;
	vector<order> orders;
};
#endif
