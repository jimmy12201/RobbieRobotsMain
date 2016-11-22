#include "Customers.h"
#include <iostream>
#include <string>
using namespace std;
void customer::createCustomer(string name, string address, string phone, string email)
{
	customerName = name;
	customerAddress = address;
	customerEmail = email;
	customerPhoneNumber = phone;
}
string customer::getName()
{
	return customerName;
}