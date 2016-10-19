#include "SalesAssociate.h"
#include <iostream>
#include <string>
using namespace std;

void salesAssociate::createAssociate(string Name) {
	associateName = Name;
}
string salesAssociate::getAssociateName() {
	return associateName;
}