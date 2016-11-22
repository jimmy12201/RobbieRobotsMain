#include "Shop.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


void shop::createPart(int part_number, string name, int type, double weight, double cost, string description, int power, int speed, int energy, int compartments)
{
	
	if (type == 0)
	{
		arm part(name, part_number, weight, cost, description, power);
		arms.push_back(part);
	}
	if (type == 1)
	{
		battery part(name, part_number, weight, cost, description, energy);
		batteries.push_back(part);
	}
	if (type == 2)
	{
		head part(name, part_number, weight, cost, description);
		heads.push_back(part);
	}
	if (type == 3)
	{
		torso part(name, part_number, weight, cost, description, compartments);
		torsos.push_back(part);
	}
	if (type == 4)
	{
		locomotor part(name, part_number, weight, cost, description, power, speed);
		locomotors.push_back(part);
	}
}
void shop::createModel(string name1, string cost1, string modelNumber1, string description1, int arm1, int arm2, int battery1, int battery2, int battery3, int head1, int torso1, int locomotor1) {
	robotModels TempModel;
	TempModel.createRobot(name1, cost1, modelNumber1, description1, arm1, arm2, battery1, battery2, battery3, head1, torso1, locomotor1,arms,torsos,heads,batteries,locomotors);
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

int shop::createOrder(int orderNumber, int month, int day, int year, double askingPrice, int associate, int customer, int model){

	order OrderTemp;
	OrderTemp.createOrder(orderNumber, month, day, year, askingPrice, associates[associate], customers[customer], completedModels[model]);
		orders.push_back(OrderTemp);
		return 1;

}
void shop::createCustomers(string name, string address, string phone, string email) {
	customer TempCustomer;
	TempCustomer.createCustomer(name, address, phone, email);
	customers.push_back(TempCustomer);

}
void shop::createSalesAssociate(string name, string number) {
	salesAssociate TempAssociate;
	TempAssociate.createAssociate(name, number);
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
	double profit=0,i,robotNumber=0;
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
void shop::printinfoBatteries() {
	int i = 0;
	cout << "Batteries: \n";
	for (i = 0; i < batteries.size(); i++) {
		cout << batteries[i].getName() << endl;
		cout << batteries[i].getpartNumber() << endl;
		cout << batteries[i].getWeight() << endl;
		cout << batteries[i].getCost() << endl;
		cout << batteries[i].getDescription() << endl;
		cout << batteries[i].getEnergy() << endl << endl;
	}
	cout << "\n";
}
void shop::printinfoArms() {
	int i = 0;
	cout << "Arms: \n";
	for (i = 0; i < arms.size(); i++) {
		cout << arms[i].getName() << endl;
		cout << arms[i].getpartNumber() << endl;
		cout << arms[i].getWeight() << endl;
		cout << arms[i].getCost() << endl;
		cout << arms[i].getDescription() << endl;
		cout << arms[i].getPower() << endl << endl;
	}
	cout << "\n";
}
void shop::printinfoHeads() {
	int i = 0;
	cout << "Heads: \n";
	for (i = 0; i < customers.size(); i++) {
		cout << customers[i].getName() << endl;
	}
	cout << "\n";
}
void shop::printinfoLocomotors() {
	int i = 0;
	cout << "locomotors: \n";
	for (i = 0; i < locomotors.size(); i++) {
		cout << locomotors[i].getName() << endl;
		cout << locomotors[i].getpartNumber() << endl;
		cout << locomotors[i].getWeight() << endl;
		cout << locomotors[i].getCost() << endl;
		cout << locomotors[i].getDescription() << endl;
		cout << locomotors[i].getPower() << endl;
		cout << locomotors[i].getSpeed() << endl << endl;
	}
	cout << "\n";
}
void shop::printinfoTorsos() {
	int i = 0;
	cout << "Torsos: \n";
	for (i = 0; i < torsos.size(); i++) {
		cout << torsos[i].getName() << endl;
		cout << torsos[i].getpartNumber() << endl;
		cout << torsos[i].getWeight() << endl;
		cout << torsos[i].getCost() << endl;
		cout << torsos[i].getCompartments() << endl;
	}
	cout << "\n";
}
