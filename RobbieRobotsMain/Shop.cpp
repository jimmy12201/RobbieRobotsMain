#include "Shop.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void shop::MainMenu()
{
	int input;
	do{
		//cout << "Main Menu\n---------------\n1. Create\nChoice Number:   \n";
		// << "Create...\n---------------\n1. Order\n2. Customer\n3. Sales Associate\n4. Robot Model\n5. Robot Component\n6. Quit to Main Menu\n";
		cout << "enter 1 to enter part, 2 to create model: ";
		cin >> input;
		if (input == 1)
		{
			createPart();
		}
		else if (input == 2)
		{
			createModel();
		}
		else if (input == 3)
		{
			printModels();
		}
		
	} while (input != 0);
	
}
void shop::createPart()
{
	cout << "Create...Robot Component...\n---------------\n";
	cout << "What part are you creating?\n1. Arm\n2. Battery\n3. Head\n4. Torso\n5. Locomotor\n";
	int partType;
	cin >> partType;
	if (partType == 1)
	{
		arm part;
		part.armInitialize();
		arms.push_back(part);
	}
	if (partType == 2)
	{
		battery part;
		part.batteryInitialize();
		batteries.push_back(part);
	}
	if (partType == 3)
	{
		head part;
		part.headInitialize();
		heads.push_back(part);
	}
	if (partType == 4)
	{
		torso part;
		part.torsoInitialize();
		torsos.push_back(part);
	}
	if (partType == 5)
	{
		locomotor part;
		part.locomotorInitialize();
		locomotors.push_back(part);
	}
}
void shop::createModel() {
	robotModels TempModel;
	TempModel.createRobot(arms,torsos,heads,batteries,locomotors);
	completedModels.push_back(TempModel);
}
void shop::printModels() {
	for (int i = 0; i < completedModels.size();i++)
	{
		completedModels[i].printRobotNames();
		cout << completedModels[i].getModelCost();
	}
}