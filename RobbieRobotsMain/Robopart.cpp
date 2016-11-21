#include "Robopart.h"
#include <iostream>
#include <string>
using namespace std;
//ROBOPARTS

string roboParts::getName() {
	return name;
}

int roboParts::getpartNumber()
{
	return partNumber;
}
double roboParts::getWeight() {
	return weight;
}
double roboParts::getCost() {
	return cost;
}
string roboParts::getDescription() {
	return description;
} 
//Virtual functions
double roboParts::getSpeed()
{
	return 0;
}
double roboParts::getPower() {
	return 0;
}
double roboParts::getEnergy() {
	return 0;
}
int roboParts::getCompartments()
{
	return 0;
}
// ARMS
double arm::getPower() {
	return powerConsumption;
}


//LOCOMOTOR
double locomotor::getPower() {
	return powerConsumed;
}
double locomotor::getSpeed()
{
	return max_speed;
}

//BATTERY
double battery::getEnergy() {
	return energyBattery;
}

//TORSO
int torso::getCompartments()
{
	return battery_compartments;
}
