#pragma once
#ifndef __ROBOPART_H
#define __ROBOPART_H 2016
#include <vector>
#include <iostream>
using namespace std;

class roboParts{
public:
	roboParts(string nameS, int partNumberS, double weightS, double costS, string descriptionS)
	{
		name = nameS;
		partNumber = partNumberS;
		weight = weightS;
		description = descriptionS;
		cost = costS;
	}
	string getName();
	int getpartNumber();
	double getWeight();
	string getDescription();
	double getCost();
	virtual double getPower();
	virtual double getSpeed();
	virtual double getEnergy();
	virtual int getCompartments();
protected:
	string name;
	int partNumber;
	double weight;
	double cost;
	string description;
};

class arm : public roboParts {
public:
	arm(string nameS, int partNumberS, double weightS, double costS, string descriptionS, double power) : roboParts(nameS, partNumberS, weightS, costS, descriptionS)
	{
		powerConsumption = power;
	}
	 double getPower();
private:
	double powerConsumption;
};

class head : public roboParts {
public:
	head(string nameS, int partNumberS, double weightS, double costS, string descriptionS) : roboParts(nameS,partNumberS,weightS,costS,descriptionS)
	{}
private:
};

class locomotor : public roboParts {
public:
	locomotor(string nameS, int partNumberS, double weightS, double costS, string descriptionS, double power, double speed) : roboParts(nameS, partNumberS, weightS, costS, descriptionS)
	{
		powerConsumed = power;
		max_speed = speed;
	}
	double getSpeed();
	double getPower();
private:
	double max_speed;
	double powerConsumed;
};

class battery : public roboParts {
public:
	battery(string nameS, int partNumberS, double weightS, double costS, string descriptionS, double energy) : roboParts(nameS, partNumberS, weightS, costS, descriptionS)
	{
		energyBattery = energy;
	}
	double getEnergy();
private:
	double energyBattery;
};

class torso : public roboParts {
public:
	torso(string nameS, int partNumberS, double weightS, double costS, string descriptionS, int compartments) : roboParts(nameS, partNumberS, weightS, costS, descriptionS)
	{
		battery_compartments = compartments;
	}
	int getCompartments();
private:
	int battery_compartments;
};
#endif