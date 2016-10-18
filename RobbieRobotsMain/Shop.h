#pragma once
#ifndef __SHOP_H
#define __SHOP_H 2016
#include <vector>
#include "Robotmodels.h"
#include "Robopart.h"
#include "Customers.h"
#include "Orders.h"
class shop{
public:
	void MainMenu();
	void createPart();
	void createModel();
	void printModels();
	void createCustomers();
	
private:
	vector<robotModels> completedModels;
	vector<arm> arms;
	vector<torso> torsos;
	vector<head> heads;
	vector<battery>batteries;
	vector<locomotor> locomotors;
	vector<customer> customers;
};
#endif
