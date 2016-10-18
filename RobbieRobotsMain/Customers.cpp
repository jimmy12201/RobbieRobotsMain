#include "Customers.h"
#include <iostream>
#include <string>
using namespace std;
void customer::createCustomer(string name)
{
	customerName = name;
}
string customer::getName()
{
	return customerName;
}