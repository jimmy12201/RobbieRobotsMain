#pragma once
#ifndef __ROBOPART_H
#define __ROBOPART_H 2016
#include <vector>
#include <iostream>
using namespace std;

class roboParts{
public:
	void initializePart();
	string getName();
	int getpartNumber();
	double getWeight();
	string getDescription();
protected:
	string name;
	int partNumber;
	double weight;
	double cost;
	string description;
};

class arm : public roboParts {
public:
	void armInitialize();
	double getPower();
private:
	double powerConsumption;
};

class head : public roboParts {
public:
	void headInitialize();
private:
};

class locomotor : public roboParts {
public:
	void locomotorInitialize();
	double getSpeed();
	double getPower();
private:
	double max_speed;
	double powerConsumed;
};

class battery : public roboParts {
public:
	void batteryInitialize();
	double getEnergy();
private:
	double energyBattery;
};

class torso : public roboParts {
public:
	void torsoInitialize();
	int getCompartments();
private:
	int battery_compartments;
};
#endif