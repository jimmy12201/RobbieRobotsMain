#pragma once
#ifndef __ROBOTMODELS_H
#define __ROBOTMODELS_H 2016
#include <iostream>
#include <vector>
#include "Robopart.h"


using namespace std;

class robotModels {
public:
	void createRobot(vector<arm>&, vector<torso>&, vector<head>&, vector<battery>&, vector<locomotor>&);
private:
	vector<roboParts> modelParts;
	string name;
	int modelNumber;
	double price;
};
#endif