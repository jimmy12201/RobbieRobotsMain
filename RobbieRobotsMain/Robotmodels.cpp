#include "Robotmodels.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void robotModels::createRobot( vector<arm>& Arms, vector<torso>& Torsos, vector<head>& Heads, vector<battery>& Batteries, vector<locomotor>& Locomotors)
{
	unsigned int i;
	cout << "Select Robot Part: Arm\n";
	for (i = 0; i < Arms.size(); i++)
	{
		cout << i << ": " << "Name: " << Arms[i].getName() << "\n";
	}
	cout << "\n";
	for (i = 0; i < Torsos.size(); i++)
	{
		cout << i << " " << "Name: " << Torsos[i].getName() << "\n";
	}
	cout << "\n";
	for (i = 0; i < Heads.size(); i++)
	{
		cout << i << " " << "Name: " << Heads[i].getName() << "\n";
	}
	cout << "\n";
	for (i = 0; i < Batteries.size(); i++)
	{
		cout << i << " " << "Name: " << Batteries[i].getName() << "\n";
	}
	cout << "\n";
	for (i = 0; i < Locomotors.size(); i++)
	{
		cout << i << " " << "Name: " << Locomotors[i].getName() << "\n";
	}
	cout << "\n";
}