#pragma once
#ifndef __ROBOTMODELS_H
#define __ROBOTMODELS_H 2016
#include <memory>
#include <iostream>
#include <vector>
#include "Robopart.h"


using namespace std;

class robotModels {
public:
	void createRobot(string name1, string cost1, string modelNumber1, string description1, int arm1, int arm2, int battery1, int battery2, int battery3, int head1, int torso1, int locomotor1, vector<arm>&, vector<torso>&, vector<head>&, vector<battery>&, vector<locomotor>&);
	string getRobotName();
	void getRobotData();
	double getModelCost();
	double getModelAskingPrice();
	string getRobotDescription();
private:
	vector<roboParts*> modelParts;
	string name;
	string modelNumber;
	double price;
	double askingPrice;
	string description;
};
#endif