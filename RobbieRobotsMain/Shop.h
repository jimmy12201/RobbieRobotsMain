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
	friend class roboModelsGUI;
	void createPart(int part_number, string name, int type, double weight, double cost, string description, int power ,int speed, int energy, int compartments);
	void createModel(string name, string cost, string modelNumber, string description, int arm1, int arm2, int battery1, int battery2, int battery3, int head, int torso, int locomotor);
	int createOrder();
	void createCustomers(string name);
	void createSalesAssociate(string name);
	void printRobotInfo();
	void overallSalesReport();
	void datedSalesReport();
	void associateReport();
	void customerReport();
	void printinfoHeads(); //TO BE REMOVED
	void printinfoTorsos();
	void printinfoLocomotors();
	void printinfoBatteries();
	void printinfoArms();

	
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
