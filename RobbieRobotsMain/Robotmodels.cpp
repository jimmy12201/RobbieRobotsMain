#include "Robotmodels.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
using namespace std;

void robotModels::createRobot( vector<arm>& Arms, vector<torso>& Torsos, vector<head>& Heads, vector<battery>& Batteries, vector<locomotor>& Locomotors)
{
	unsigned int i;
	int selection;
	//ARM
	cout << "Select Robot Part: Arm\n";
	for (i = 0; i < Arms.size(); i++)
	{
		cout << i << ": " << "Name: " << Arms[i].getName() << "\n";
	}
	cout << "\nEnter the number cooresponding to the part to choose it: ";
	cin >> selection;
	modelParts.push_back(&Arms[selection]);

	//TORSO
	cout << "\nSelect Robot Part: Torso\n\n";
	for (i = 0; i < Torsos.size(); i++)
	{
		cout << i << " " << "Name: " << Torsos[i].getName() << "\n";
	}
	cout << "\nEnter the number cooresponding to the part to choose it: ";
	cin >> selection;
	modelParts.push_back(&Torsos[selection]);

	//HEAD
	cout << "\nSelect Robot Part: Head\n\n";
	for (i = 0; i < Heads.size(); i++)
	{
		cout << i << " " << "Name: " << Heads[i].getName() << "\n";
	}
	cout << "\nEnter the number cooresponding to the part to choose it: ";
	cin >> selection;
	modelParts.push_back(&Heads[selection]);

	//BATTERY
	cout << "\nSelect Robot Part: Battery\n\n";
	for (i = 0; i < Batteries.size(); i++)
	{
		cout << i << " " << "Name: " << Batteries[i].getName() << "\n";
	}
	cout << "\nEnter the number cooresponding to the part to choose it: ";
	cin >> selection;
	modelParts.push_back(&Batteries[selection]);

	//LOCOMOTER
	cout << "\nSelect Robot Part: Arm\n";
	for (i = 0; i < Locomotors.size(); i++)
	{
		cout << i << " " << "Name: " << Locomotors[i].getName() << "\n";
	}
	cout << "\nEnter the number cooresponding to the part to choose it: ";
	cin >> selection;
	modelParts.push_back(&Locomotors[selection]);
}
void robotModels::printRobotNames() {
	for (unsigned int i = 0; i < modelParts.size(); i++)
	{
		if (typeid(*(modelParts[i])).name() == typeid(arm).name())
		{
			cout << "arm\n";
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(torso).name()))
		{
			cout << "torso\n";
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(head).name()))
		{
			cout << "head\n";
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(battery).name()))
		{
			cout << "battery\n";
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(locomotor).name()))
		{
			cout << "locomotor\n";
		}
	}
	
}