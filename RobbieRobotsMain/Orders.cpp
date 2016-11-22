#include "Orders.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void order::createOrder(int orderNumberT, int monthT, int dayT, int yearT, double askingPriceT, salesAssociate &salesAssociateOrderT, customer &customerNameOrderT, robotModels &selcetedModelT)
{
	orderNumber = orderNumberT;
	month = monthT;
	day = dayT;
	year = yearT;
	salesAssociateOrder = &salesAssociateOrderT;
	customerNameOrder = &customerNameOrderT;
	askingPrice = askingPriceT;
}
void order::generateBOS() {

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