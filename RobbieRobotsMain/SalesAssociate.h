#pragma once
#ifndef __SALESASSOCIATE
#define __SALESASSOCIATE_H 2016
#include <ctime>
#include "robotModels.h"
class salesAssociate {
public:
	void createAssociate(string Name, string number);
	string getAssociateName();
private:
	string associateName;
	string employeeNumber;
};

#endif