#pragma once
#ifndef __SHOP_H
#define __SHOP_H 2016
#include <vector>
#include "Robotmodels.h"
#include "Robopart.h"
class shop{
public:
	void MainMenu();
	void createPart();
	void createModel();
	void printModels();
	
private:
	vector<robotModels> completedModels;
	vector<arm> arms;
	vector<torso> torsos;
	vector<head> heads;
	vector<battery>batteries;
	vector<locomotor> locomotors;
};
#endif
