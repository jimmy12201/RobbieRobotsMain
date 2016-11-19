#pragma once
#ifndef __SHOP_H
#define __SHOP_H 2016
#include <vector>
#include <iostream>
#include "Robotmodels.h"
#include "Robopart.h"
#include "Customers.h"
#include "Orders.h"
#include "SalesAssociate.h"
class shop{
public:
	void createPart(string &part_number, string &name, int &type, double &weight, double &cost, string &description, int &power ,int &speed, int &energy, int &compartments);
	void createModel();
	int createOrder();
	void createCustomers(string name);
	void createSalesAssociate(string name);
	void printRobotInfo();
	void overallSalesReport();
	void datedSalesReport();
	void associateReport();
	void customerReport();
	void printinfo(); //TO BE REMOVED
	
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
