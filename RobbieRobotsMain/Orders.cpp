#include "Orders.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void order::createOrder(int orderNumberT, int monthT, int dayT, int yearT, double priceT, double askingPriceT, double locationT, salesAssociate &salesAssociateOrderT, customer &customerNameOrderT, robotModels &selectedModelT)
{
	orderNumber = orderNumberT;
	month = monthT;
	day = dayT;
	year = yearT;
	price = priceT;
	location = locationT;
	salesAssociateOrder = &salesAssociateOrderT;
	selectedModel = &selectedModelT;
	customerNameOrder = &customerNameOrderT;
	askingPrice = askingPriceT;
	overallRobotPrice = (selectedModel->getModelAskingPrice())*1.0625 + location*.05;
}
void order::generateBOS() {
	cout << "\nOfficial Bill Of Sales\n---------------------------" << "\n\n";
	cout << "Purchased by: " << customerNameOrder->getName()<<endl;
	cout << "Assisted by : " << salesAssociateOrder->getAssociateName() << endl;
	cout << "Date: " << month << "/" << day << "/" << year << endl;
	cout << "Purchased: " << selectedModel->getRobotName() << endl;
	cout << "Customer Order Number: "<< orderNumber<<endl;
	cout << "Cost of Robot: $" <<setprecision(2)<<fixed <<selectedModel->getModelAskingPrice() << endl;
	cout << "Shipping      +$" << setprecision(2) << location*.05<<endl;
	cout << "Tax:          +$" << setprecision(2) << (selectedModel->getModelAskingPrice())*.0625 <<"\n\t------------\n";
	cout << "Total Cost:   $" << setprecision(2) << (selectedModel->getModelAskingPrice())*1.0625 + location*.05 << "\n\n";

}
string order::getRobotName()
{
	return selectedModel->getRobotName();
}
double order::getRobotPrice()
{
	return askingPrice;
}
double order::getRobotCost()
{
	return price;
}
double order::getRobotTotalPrice()
{
	return overallRobotPrice;
}
int order::getYear()
{
	return year;
}
int order::getMonth()
{
	return month;
}
int order::getDay()
{
	return day;
}
string order::getAssociate()
{
	return salesAssociateOrder->getAssociateName();
}
string order::getCustomer()
{
	return customerNameOrder->getName();
}