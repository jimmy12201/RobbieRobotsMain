#include "Robotmodels.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string>
using namespace std;

void robotModels::createRobot(string name1, string cost1, string modelNumber1, string description1, int arm1, int arm2, int battery1, int battery2, int battery3, int head1, int torso1, int locomotor1, vector<arm>& Arms, vector<torso>& Torsos, vector<head>& Heads, vector<battery>& Batteries, vector<locomotor>& Locomotors)
{
	name = name1;
	modelNumber = modelNumber1;
	askingPrice = stof(cost1);
	description = description1;

	
	modelParts.push_back(&Arms[arm1]);
	if (arm2 >= 0){
			modelParts.push_back(&Arms[arm2]);
	}

	modelParts.push_back(&Torsos[torso1]);
	modelParts.push_back(&Heads[head1]);
	modelParts.push_back(&Locomotors[locomotor1]);

	modelParts.push_back(&Batteries[battery1]);
	if (battery2 >= 0){
		modelParts.push_back(&Batteries[battery2]);
	}

	if (battery3 >= 0){
		modelParts.push_back(&Batteries[battery3]);
	}




	/*unsigned int i,totalParts=0,j,choice;
	int selection;
	bool selecting = true;
	torso newTorso;
	cout << "Create a New Robot\n-----------------\n\n";
	//ARM
	for (j = 1; j <= 2; j++) {
		selecting = true;
		while (selecting)
		{
			cout << "\nSelect Robot Part: Arm --" << " Part " << j<<"/"<<2<<"\n---------------\n\n";
			for (i = 1; i < Arms.size()+1; i++)
			{
				cout << i << ": " << Arms[i-1].getName() << "\n";

			}
			cout << i << ": Create new Part";
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
	
	//Torso
	while (selecting)
	{
		cout << "\nSelect Robot Part: Torso\n---------------\n\n";
		for (i = 1; i < Torsos.size() + 1; i++)
		{
			cout << i << ": " << Torsos[i - 1].getName() << "\n";

		}
		cout << i  << ": Create new Part";
		cout << "\nEnter corresponding number to select part: ";
		cin >> selection;
		selection -= 1;

		if (selection < Torsos.size())
		{
			cout << "\n\nIs This part Correct?\n--------------------\nName: " << Torsos[selection].getName() << "\nWeight: " << Torsos[selection].getWeight() << "\nCost: $" << Torsos[selection].getCost() << "\nBattery Compartments: " << Torsos[selection].getCompartments() << "\nDescription: " << Torsos[selection].getDescription() << "\n";
			cout << "0: No\n1: Yes\n";
			cin >> choice;
			if (choice == 1) {
				modelParts.push_back(&Torsos[selection]);
				selecting = false;
				price += Torsos[selection].getCost();
			}

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
		cout << "\nSelect Robot Part: Head\n---------------\n\n";
		for (i = 1; i < Heads.size() + 1; i++)
		{
			cout << i << ": " << Heads[i - 1].getName() << "\n";

		}
		cout << i << ": Create new Part";
		cout << "\nEnter corresponding number to select part: ";
		cin >> selection;
		selection -= 1;

		if (selection < Heads.size())
		{
			cout << "\n\nIs This part Correct?\n--------------------\nName: " << Heads[selection].getName() << "\nWeight: " << Heads[selection].getWeight() << "\nCost: $" << Heads[selection].getCost() << "\nDescription: " << Heads[selection].getDescription() << "\n";
			cout << "0: No\n1: Yes\n";
			cin >> choice;
			if (choice == 1) {
				modelParts.push_back(&Heads[selection]);
				selecting = false;
				price += Heads[selection].getCost();
			}

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
	bool done = false;
	for (j = 1; j <= Torsos[Torsos.size() - 1].getCompartments(); j++) {
		selecting = true;
		while (selecting && !done)
		{
			cout << "\nSelect Robot Part: Battery --" << " Part " << j << "/" << Torsos[Torsos.size() - 1].getCompartments() << "\n---------------\n\n";
			for (i = 1; i < Batteries.size() + 1; i++)
			{
				cout << i << ": " << Batteries[i - 1].getName() << "\n";

			}
			cout << i << ": Create new Part";
			cout << "\nEnter corresponding number to select part, or 0 to skip ";
			cin >> selection;
			selection -= 1;

			if (selection < Batteries.size())
			{
				cout << "\n\nIs This part Correct?\n--------------------\nName: " << Batteries[selection].getName() << "\nWeight: " << Batteries[selection].getWeight() << "\nCost: $" << Batteries[selection].getCost() << "\nEnegry (KW-hours): " << Batteries[selection].getEnergy() << "\nDescription: " << Batteries[selection].getDescription() << "\n";
				cout << "0: No\n1: Yes\n";
				cin >> choice;
				if (choice == 1) {
					modelParts.push_back(&Batteries[selection]);
					selecting = false;
					price += Batteries[selection].getCost();
				}

			}
			else if (selection == Batteries.size())
			{
				battery newBattery;
				newBattery.batteryInitialize();
				Batteries.push_back(newBattery);
			}
			else if (selection == -1)
			{
				if (j == 1) {
					cout << "Must have at least one battery.\n";
				}
				else
				{
					done = true;
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

	//LOCOMOTORS
	while (selecting)
	{
		cout << "Select Robot Part: Locomotors\n---------------\n\n";
		for (i = 1; i < Locomotors.size() + 1; i++)
		{
			cout << i << ": " << Locomotors[i - 1].getName() << "\n";

		}
		cout << i  << ": Create new Part";
		cout << "\nEnter corresponding number to select part, or 0 to skip ";
		cin >> selection;
		selection -= 1;

		if (selection < Locomotors.size())
		{
			cout << "\n\nIs This part Correct?\n--------------------\nName: " << Locomotors[selection].getName() << "\nWeight: " << Locomotors[selection].getWeight() << "\nCost: $" << Locomotors[selection].getCost() << "\nDescription: " <<Locomotors[selection].getDescription() << "\n";
			cout << "0: No\n1: Yes\n";
			cin >> choice;
			if (choice == 1) {
				modelParts.push_back(&Locomotors[selection]);
				selecting = false;
				price += Locomotors[selection].getCost();
			}

		}
		else
		{
			locomotor newLocomotor;
			newLocomotor.locomotorInitialize();
			Locomotors.push_back(newLocomotor);
		}
	}
	cout << "Almost finished!\n\n";
	cout << "What is the name of your robot? ";
	cin.ignore();
	getline(cin, name);
	cout << "What is the model number of your robot? ";
	cin >> modelNumber;
	cout << "Give a short description of the robot: ";
	cin.ignore();
	getline(cin, description);
	cout << "Looks good!\n\nThe total cost to build the robot is $ " << getModelCost()<< "\n";
	cout << "Finally, what should the price of this model be? ";
	cin >> askingPrice;
	system("cls");*/
}
void robotModels::getRobotData() {
	cout << "\nRobot Specs By Part\n------------------\n";
	for (unsigned int i = 0; i < modelParts.size(); i++)
	{
		cout <<"Name: " << (*(modelParts[i])).getName() << "\n";
		cout <<"Part Number: " << (*(modelParts[i])).getpartNumber() << "\n";
		cout <<"Weight: " << (*(modelParts[i])).getWeight() << " grams\n";
		cout <<"Cost: $" << (*(modelParts[i])).getCost() << "\n";
		cout <<"Breif description: " << (*(modelParts[i])).getDescription() << "\n";

		if (typeid(*(modelParts[i])).name() == typeid(arm).name())
		{
			cout <<"Power: " <<(*(modelParts[i])).getPower() << " watts\n\n";
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(torso).name()))
		{
			cout << "Battery Compartments: " << (*(modelParts[i])).getCompartments() << "\n\n";
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(head).name()))
		{
			cout << "\n";
			//Saving for case of added variable to head
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(battery).name()))
		{
			cout << "Energy: " << (*(modelParts[i])).getEnergy() << " kWh\n\n";
		}
		else if ((typeid(*(modelParts[i])).name() == typeid(locomotor).name()))
		{
			cout << "Power: " << (*(modelParts[i])).getPower() << " watts\n";
			cout << "Speed: " << (*(modelParts[i])).getSpeed() << " MPH \n\n";
		}
	}
	
}
string robotModels::getRobotName() {
	return name;
}
string robotModels::getRobotDescription() {
	return description;
}
double robotModels::getModelCost() {
	return price;
}
double robotModels::getModelAskingPrice() {
	return askingPrice;
}