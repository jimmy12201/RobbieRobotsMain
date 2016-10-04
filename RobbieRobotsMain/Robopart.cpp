#include "Robopart.h"
#include <iostream>
#include <string>
using namespace std;
//ROBOPARTS
void roboParts::initializePart() {
	cout << "What is the name of the part?: ";
	cin.ignore();
	getline(cin, name);
	cout << "\nPart number?: ";
	cin >> partNumber;
	cout << "\nPart weight? (g): ";
	cin >> weight;
	cout << "\nPart cost? ($): ";
	cin >> cost;
	cout << "\nPlease give a breif description of the part: \n";
	cin.ignore();
	getline(cin, description);
}
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
string roboParts::getDescription() {
	return description;
} 
// ARMS
double arm::getPower() {
	return powerConsumption;
}
void arm::armInitialize() {
	initializePart();
	cout << "How much energy does this part consume (watts)?: ";
	cin >> powerConsumption;
}
//LOCOMOTOR
double locomotor::getPower() {
	return powerConsumed;
}
double locomotor::getSpeed()
{
	return max_speed;
}
void locomotor::locomotorInitialize() {
	initializePart();
	cout << "How much energy does this part consume (watts)?: ";
	cin >> powerConsumed;
	cout << "What is the maximum speed of this part (MPH)?:  ";
	cin >> max_speed;
}
//BATTERY
double battery::getEnergy() {
	return energyBattery;
}
void battery::batteryInitialize() {
	initializePart();
	cout << "How much energy does this part contain (volts)?: ";
	cin >> energyBattery;
}
//TORSO
int torso::getCompartments()
{
	return battery_compartments;
}
void torso::torsoInitialize() {
	initializePart();
	cout << "How many compartments does this part have?:  ";
	cin >> battery_compartments;
}
//HEAD
void head::headInitialize()
{
	initializePart();
}
