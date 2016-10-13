#include "Robotmodels.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
using namespace std;

void robotModels::createRobot( vector<arm>& Arms, vector<torso>& Torsos, vector<head>& Heads, vector<battery>& Batteries, vector<locomotor>& Locomotors)
{
	unsigned int i,totalParts=0,j,choice;
	int selection;
	bool selecting = true;
torso newTorso;
	cout << "Create a New Robot\n-----------------\n\n";
	//ARM
	for (j = 1; j <= 2; j++) {
		selecting = true;
		while (selecting)
		{
			cout << "Select Robot Part: Arm --" << " Part " << j<<"/"<<2<<"\n---------------\n\n";
			for (i = 1; i < Arms.size()+1; i++)
			{
				cout << i << ": " << Arms[i-1].getName() << "\n";
				if (i == Arms.size()) {
					cout << i+1 << "+: Create new Part";
				}

			}
			cout << "\nEnter corresponding number to select part, or 0 to skip ";
			cin >> selection;
			selection -= 1;

			if (selection < Arms.size())
			{
				cout << "\n\nIs This part Correct?\n--------------------\nName: " << Arms[selection].getName() << "\nWeight: " << Arms[selection].getWeight() << "\nCost: $" << Arms[selection].getCost() <<"\nPower: "<< Arms[selection].getPower() << "\nDescription: " << Arms[selection].getDescription() <<"\n";
				cout << "0: No\n1: Yes\n";
				cin >> choice;
				if (choice==1) {
					modelParts.push_back(&Arms[selection]);
					selecting = false;
					price += Arms[selection].getCost();
				}

			}
			else if (selection == Arms.size())
			{
				arm newArm;
				newArm.armInitialize();
				Arms.push_back(newArm);
			}
			else if (selection == -1 )
			{
				if (j == 1) {
					cout << "Must have at least one arm.\n";
				}
				else
				{
					break;
				}
			}
			else
			{
				cout << "Invalid Input. Please try again.\n";
			}
		}
		selecting = true;
	}
	

	/*/Torso
	while (selecting)
	{
		cout << "Select Robot Part: Torso\n";
		for (i = 0; i < Torsos.size(); i++)
		{
			cout << i << ": " << "Name: " << Torsos[i].getName() << "\n";
		}
		cout << "\nEnter the number cooresponding to the part to choose it, or a higher number to create a new part: ";
		cin >> selection;

		if (selection < Torsos.size())
		{
			modelParts.push_back(&Torsos[selection]);
			selecting = false;
		}
		else
		{
			newTorso.torsoInitialize();
			Torsos.push_back(newTorso);
		}
	}
	selecting = true;


	//HEAD
	while (selecting)
	{
		cout << "Select Robot Part: Head\n";
		for (i = 0; i < Heads.size(); i++)
		{
			cout << i << ": " << "Name: " << Heads[i].getName() << "\n";
		}
		cout << "\nEnter corresponding number to select part";
		cin >> selection;

		if (selection < Heads.size())
		{
			modelParts.push_back(&Heads[selection]);
			selecting = false;
		}
		else
		{
			head newHead;
			newHead.headInitialize();
			Heads.push_back(newHead);
		}
	}
	selecting = true;

	//Battery
	while (selecting)
	{
		cout << "Select Robot Part: Battery\n";
		for (i = 0; i < Batteries.size(); i++)
		{
			cout << i << ": " << "Name: " << Batteries[i].getName() << "\n";
		}
		cout << "\nEnter the number cooresponding to the part to choose it, or a higher number to create a new part: ";
		cin >> selection;

		if (selection < Batteries.size())
		{
			modelParts.push_back(&Batteries[selection]);
			selecting = false;
		}
		else
		{
			battery newBattery;
			newBattery.batteryInitialize();
			Batteries.push_back(newBattery);
		}
	}
	selecting = true;


	//LOCOMOTORS
	while (selecting)
	{
		cout << "Select Robot Part: Locomotor\n";
		for (i = 0; i < Locomotors.size(); i++)
		{
			cout << i << ": " << "Name: " << Locomotors[i].getName() << "\n";
		}
		cout << "\nEnter the number cooresponding to the part to choose it, or a higher number to create a new part: ";
		cin >> selection;

		if (selection < Locomotors.size())
		{
			modelParts.push_back(&Locomotors[selection]);
			selecting = false;
		}
		else
		{
			locomotor newLocomotor;
			newLocomotor.locomotorInitialize();
			Locomotors.push_back(newLocomotor);
		}
	}*/
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

double robotModels::getModelCost() {
	return price;
}