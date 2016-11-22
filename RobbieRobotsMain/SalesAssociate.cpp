#include "SalesAssociate.h"
#include <iostream>
#include <string>
using namespace std;

void salesAssociate::createAssociate(string Name, string number) {
	associateName = Name;
	employeeNumber = number;
}
string salesAssociate::getAssociateName() {
	return associateName;
}