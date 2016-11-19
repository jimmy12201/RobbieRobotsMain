#include "Shop.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


void shop::createPart(string &part_number, string &name, int &type, double &weight, double &cost, string &description, int &power, int &speed, int &energy, int &compartments)
{
	if (type == 1)
	{
		arm part;
		part.armInitialize();
		arms.push_back(part);
	}
	if (type == 2)
	{
		battery part;
		part.batteryInitialize();
		batteries.push_back(part);
	}
	if (type == 3)
	{
		head part;
		part.headInitialize();
		heads.push_back(part);
	}
	if (type == 4)
	{
		torso part;
		part.torsoInitialize();
		torsos.push_back(part);
	}
	if (type == 5)
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
void shop::printRobotInfo() {
	system("cls");
	for (int i = 0; i < completedModels.size();i++)
	{
		cout << "Model " << i+1 <<"\n---------------------\nName: "<< completedModels[i].getRobotName() <<"\n";
		cout <<"Robot Cost: $"<< completedModels[i].getModelAskingPrice() << "\n";
		cout << "'" << completedModels[i].getRobotDescription() << "'\n\n";
	}
}
int shop::createOrder() {
	int selection, i, day, month, year;
	double orderNumberT, priceT, location;
	customer *customerNameOrderT;
	salesAssociate *salesAssociateOrderT;
	robotModels *selectedModelT;
	order OrderTemp;

	//Robot Model
	printRobotInfo();
	cout << "What Robot would You like to take home today? Enter the Robot Model Number: ";
	cin >> selection;
	selection -= 1;
	if (selection > completedModels.size() - 1 || selection <0)
	{
		cout << "Invalid Input, returning to menu\n\n";
		return 0;
	}
	selectedModelT = &completedModels[selection];
	selectedModelT->getRobotData();
	//Sales Associate
	cout << "\n";
	for (i = 0; i < associates.size(); i++)
	{
		cout << i + 1 << ". " << associates[i].getAssociateName() << "\n";
	}
	cout << "\nPlease select the associate who helped you today: ";
	cin >> selection;
	selection -= 1;
	if (selection > associates.size()-1 || selection <0)
	{
		cout << "Invalid Input, returning to menu\n\n";
		return 0;
	}
	salesAssociateOrderT = &associates[selection];

	//Customer 
	cout << "\n";
	for (i = 0; i < customers.size(); i++)
	{
		cout << i + 1 << ". " << customers[i].getName() << "\n";
	}
	cout << "\nPlease select your name: ";
	cin >> selection;
	selection -= 1;
	if (selection > customers.size() - 1 || selection <0)
	{
		cout << "\nInvalid Input, returning to menu\n\n";
		return 0;
	}
	customerNameOrderT = &customers[selection];
	bool incorrect = true;
	while (incorrect)
	{
		cout << "Date:(enter only numbers) \nEnter the number of the Month: ";
		cin >> month;
		cout << "\nEnter the Day: ";
		cin >> day;
		cout << "\nEnter the Year: ";
		cin >> year;
		if (day > 31 || day < 1 || year < 1950 || month > 12 || month < 1)//rudimentary validation check, not perfect
		{
			cout << "Please enter a valid date.\n";
		}
		else
		{
			incorrect = false;
		}
	}
	cout << "\nPlease enter the distance in miles of how far your location is for the Robbie Robots Shop: ";
	cin >> location;
	cout << "\nWhat is the order number?: ";
	cin >> orderNumberT;
	cout << "\nDoes this information look correct?";
	OrderTemp.createOrder(orderNumberT, month, day, year, selectedModelT->getModelCost(),selectedModelT->getModelAskingPrice(), location, *salesAssociateOrderT, *customerNameOrderT, *selectedModelT);
	OrderTemp.generateBOS();
	cout << "Confirm Order?\n0: No\n1: Yes: ";
	cin >> selection;
	if (selection == 1)
	{
		orders.push_back(OrderTemp);
		cout << "Order added!\n";
	}
	return 1;

}
void shop::createCustomers(string name) {
	customer TempCustomer;
	TempCustomer.createCustomer(name);
	customers.push_back(TempCustomer);

}
void shop::createSalesAssociate(string name) {
	salesAssociate TempAssociate;
	TempAssociate.createAssociate(name);
	associates.push_back(TempAssociate);
}
void shop::overallSalesReport()
{
	int count=0;
	system("cls");
	cout << "Overall Sales Report\n---------------------------" << "\n\n";
	for (int j = 0; j < completedModels.size(); j++)
	{
		count = 0;
		for (int i = 0; i < orders.size(); i++)
		{
			if (completedModels[j].getRobotName().compare(orders[i].getRobotName())==0)
			{
				count++;
			}
		}
		cout << "Robot Name: "<< completedModels[j].getRobotName() << "\n";
		cout << "Robots sold: " << count << endl;
		cout << "Cost to build: "<<completedModels[j].getModelCost()<< "\nAsking Price: "<<completedModels[j].getModelAskingPrice()<<"\n"<<"Profit Margain: " << setprecision(2)<< ((completedModels[j].getModelAskingPrice()/completedModels[j].getModelCost())*100)-100<<"%\n\n";
	}
}
void shop::datedSalesReport()
{
	//system("cls");
	for (int i = 0; i < orders.size(); i++)
	{
		orders[i].generateBOS();
	}
	int yearMin, monthMin, dayMin,yearMax,dayMax,monthMax;
	bool incorrect = true;
	while (incorrect)
	{
		cout << "Enter the minimum month: ";
		cin >> monthMin;
		cout << "\nEnter the minimum day: ";
		cin >> dayMin;
		cout << "\nEnter the minimumm year: ";
		cin >> yearMin;
		if (dayMin > 31 || dayMin < 1 || yearMin < 1950 || monthMin > 12 || monthMin < 1)//rudimentary validation check, not perfect
		{
			cout << "Please enter a valid date.\n";
		}
		else
		{
			incorrect = false;
		}
	}
	incorrect = true;
	while (incorrect)
	{
		cout << "\nEnter the maximum month: ";
		cin >> monthMax;
		cout << "\nEnter the maximum day: ";
		cin >> dayMax;
		cout << "\nEnter the maximum year: ";
		cin >> yearMax;
		if (dayMax > 31 || dayMax < 1 || yearMax  < 1950 || monthMax  > 12 || monthMax  < 1)//rudimentary validation check, not perfect
		{
			cout << "Please enter a valid date.\n";
		}
		else
		{
			incorrect = false;
		}
	}
	//system("cls");
	cout << "*******Bill of sales for dates " << monthMin << "/" << dayMin << "/" << yearMin << " - " << monthMax << "/" << dayMax << "/" << yearMax << "\n\n";
	for (int i = 0; i < orders.size(); i++)
	{
		int startDate = (yearMin * 10000) + (monthMin * 1000) + dayMin;
		int endDate = (yearMax * 10000) + (monthMax * 1000) + dayMax;
		int date = (orders[i].getYear() * 10000) + (orders[i].getMonth() * 1000) + (orders[i].getDay());
		if (date >= startDate && date <= endDate)
		{
			orders[i].generateBOS();
		}
	}

}
void shop::associateReport() {
	int profit=0,i,robotNumber=0;
	string Name;
	cout << "Please enter your Name: ";
	cin.ignore();
	getline(cin, Name);

	for (i = 0; i < orders.size(); i++)
	{
		if (orders[i].getAssociate().compare(Name) == 0)
		{
			orders[i].generateBOS();
			profit+=orders[i].getRobotPrice();
			robotNumber++;
		}
	}
	if (!profit)
	{
		cout << "You have not sold any robots yet.\n\n";
	}
	else
	{
		cout << "You have sold " << robotNumber << " robot(s) for a total of $" << profit << "! (Not inlusive of taxes and shipping)\n\n";
	}
}
void shop::customerReport()
{
int i;
double bill = 0;
string Name;
bool found = false;
	cout << "Please enter your Name: ";
	cin.ignore();
	getline(cin, Name);
	cout << endl;

	for (i = 0; i < orders.size(); i++)
	{
		if (orders[i].getCustomer().compare(Name) == 0)
		{
			found = true;
			orders[i].generateBOS();
			bill += orders[i].getRobotTotalPrice();
		}
	}
	if (!found)
	{
		cout << "No customer data.\n\n";
	}
	else
	{
		cout << "The total bill is: $"<< setprecision(2)<< bill<<"\nThank You for shopping at The Robbie Robot Shop!\n\n";
	}
}
void shop::printinfo() {
	int i = 0;
	for (i = 0; i < associates.size(); i++) {
		cout << associates[i].getAssociateName() << endl;
	}
	cout << "\n";
}