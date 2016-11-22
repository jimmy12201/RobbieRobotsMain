#define _CRT_SECURE_NO_WARNINGS
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Output.H>
#include <iostream>
#include <string>
#include "Shop.h"

using namespace std;

shop Shop;

//
// Declarations
//
class customerGUI;
void createCustomerGUI(Fl_Widget* w, void* p);
void cancelCustomer(Fl_Widget* w, void* p);
void createCustomerCB(Fl_Widget* w, void* p);

class salesAssociateGUI;
void createSalesAssociateGUI(Fl_Widget* w, void* p);
void cancelSalesAssociate(Fl_Widget* w, void* p);
void createSalesAccociateCB(Fl_Widget* w, void* p);

class roboPartsGUI;
void createRoboPartsGUI(Fl_Widget* w, void* p);
void cancelRoboParts(Fl_Widget* w, void* p);
void createRoboPartsCB(Fl_Widget* w, void* p);
void specifyGUI(Fl_Widget* w, void* p);

class roboModelsGUI;
void createModelsGUI(Fl_Widget* w, void* p);
void cancelModel(Fl_Widget* w, void* p);
void createModelCB(Fl_Widget* w, void* p);
void batteryLimitCB(Fl_Widget* w, void* p);
void getPrice(Fl_Widget* w, void* p);

class orderCreateGUI;
void createOrderGUI(Fl_Widget* w, void* p);
void cancelOrder(Fl_Widget* w, void* p);
void createOrderCB(Fl_Widget* w, void* p);
void getRobotInfoCB(Fl_Widget* w, void* p);







//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
customerGUI *customerGUIP; // The dialog of interest!
salesAssociateGUI *salesAssociateGUIP;
roboPartsGUI *roboPartsGUIP;
roboModelsGUI *roboModelsGUIP;
orderCreateGUI *orderCreateGUIP;

//CUSTOMER GUI

class customerGUI {
public:
	customerGUI() {
		dialog = new Fl_Window(340, 270, "New Customer");

		rp_name = new Fl_Input(100, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_address = new Fl_Input(100, 40, 210, 25, "Address");
		rp_address->align(FL_ALIGN_LEFT);

		rp_phone_number = new Fl_Input(100, 70, 210, 25, "Phone");
		rp_phone_number->align(FL_ALIGN_LEFT);

		rp_email = new Fl_Input(100, 100, 210, 25, "Email");
		rp_email->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)createCustomerCB, 0);

		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancelCustomer, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return rp_name->value(); }
	string phoneNumber() { return rp_phone_number->value(); }
	string address() { return rp_address->value(); }
	string email() { return rp_email->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_phone_number;
	Fl_Input *rp_address;
	Fl_Input *rp_email;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};
class salesAssociateGUI {
public:
	salesAssociateGUI(){
		dialog = new Fl_Window(340, 270, "New Sales Associate");

		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_employee_number = new Fl_Input(120, 40, 210, 25, "Employee ID:");
		rp_employee_number->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)createSalesAccociateCB, 0);

		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancelSalesAssociate, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	string name() { return rp_name->value(); }
	string employeeNumber() { return rp_employee_number->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_employee_number;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};
class roboPartsGUI {
public:
	roboPartsGUI() {
		int x = 340, y = 330, i;
		dialog = new Fl_Window(x, y, "Robot Part");

		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_part_number = new Fl_Input(120, 40, 210, 25, "Part Number:");
		rp_part_number->align(FL_ALIGN_LEFT);

		rp_type = new Fl_Choice(120, 70, 210, 25, "Type:");
		rp_type->add("Arm");
		rp_type->add("Battery");
		rp_type->add("Head");
		rp_type->add("Torso");
		rp_type->add("Locomotor");
		rp_type->callback((Fl_Callback *)specifyGUI, 0);

		rp_weight = new Fl_Input(120, 100, 210, 25, "Weight:");
		rp_weight->align(FL_ALIGN_LEFT);

		rp_cost = new Fl_Input(120, 130, 210, 25, "Cost:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 160, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_power = new Fl_Input(120, 240, 210, 25, "Power:");
		rp_power->align(FL_ALIGN_LEFT);
		rp_power->hide();

		rp_speed = new Fl_Input(120, 270, 210, 25, "Speed:");
		rp_speed->align(FL_ALIGN_LEFT);
		rp_speed->hide();

		rp_energy = new Fl_Input(120, 240, 210, 25, "Energy:");
		rp_energy->align(FL_ALIGN_LEFT);
		rp_energy->hide();

		rp_compartments = new Fl_Choice(120, 240, 210, 25, "Compartments:");
		rp_compartments->add("1");
		rp_compartments->add("2");
		rp_compartments->add("3");
		rp_compartments->align(FL_ALIGN_LEFT);
		rp_compartments->hide();

		rp_create = new Fl_Return_Button(145, 300, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)createRoboPartsCB, 0);

		rp_cancel = new Fl_Button(270, 300, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancelRoboParts, 0);

		dialog->end();
		dialog->set_non_modal();
		
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	void hidePower() { rp_power->hide(); }
	void showPower() { rp_power->show(); }
	void hideSpeed() { rp_speed->hide(); }
	void showSpeed() { rp_speed->show(); }
	void hideEnergy() { rp_energy->hide(); }
	void showEnergy() { rp_energy->show(); }
	void hideCompartments() { rp_compartments->hide(); }
	void showCompartments() { rp_compartments->show(); }

	string name() { return rp_name->value(); }
	string part_number() { return rp_part_number->value(); }
	int type() { return rp_type->value(); }
	string weight() { return rp_weight->value(); }
	string cost() { return rp_cost->value(); }
	string description() { return rp_description->value(); }
	int compartments() { return rp_compartments->value(); }
	string power() { return rp_power->value(); }
	string speed() { return rp_speed->value(); }
	string energy() { return rp_energy->value(); }

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Input *rp_part_number;
	Fl_Choice *rp_type;
	Fl_Input *rp_weight;
	Fl_Input *rp_cost;
	Fl_Input *rp_description;
	Fl_Input *rp_power;
	Fl_Input *rp_speed;
	Fl_Input *rp_energy;
	Fl_Choice *rp_compartments;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
	
};

class roboModelsGUI {
public:
	roboModelsGUI() {
		int x = 450, y = 500, i;
		dialog = new Fl_Window(x, y, "Robot Part");

		rp_name = new Fl_Input(120, 10, 210, 25, "Model Name:");
		rp_name->align(FL_ALIGN_LEFT);

		rp_model_number = new Fl_Input(120, 40, 210, 25, "Model Number:");
		rp_model_number->align(FL_ALIGN_LEFT);

		rp_head = new Fl_Choice(120, 70, 210, 25, "Head");
		rp_arm1 = new Fl_Choice(120, 100, 210, 25, "Arm 1");
		rp_arm2 = new Fl_Choice(120, 130, 210, 25, "Arm 2");
		rp_arm2->add("None");

		rp_torso = new Fl_Choice(120,160, 210, 25, "Torso");
		rp_torso->callback((Fl_Callback *)batteryLimitCB, 0);

		rp_locomotor = new Fl_Choice(120, 190, 210, 25, "Locomotor");

		rp_batteries1 = new Fl_Choice(120, 220, 210, 25, "Battery 1");
		rp_batteries2 = new Fl_Choice(120, 250, 210, 25, "Battery 2");
		rp_batteries2->add("None");
		rp_batteries3 = new Fl_Choice(120, 280, 210, 25, "Battery 3");
		rp_batteries3->add("None");

		rp_cost = new Fl_Input(120, 340, 210, 25, "Set Price:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Input(120, 370, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_costBtn = new Fl_Button(120, 310, 120, 25, "Get Cost");
		rp_costBtn->callback((Fl_Callback *)getPrice, 0);

		rp_costReturn = new Fl_Output(250, 310, 70, 25);


		rp_create = new Fl_Return_Button(200, 450, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)createModelCB, 0);

		rp_cancel = new Fl_Button(150, 450, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancelModel, 0);

		dialog->end();
		dialog->set_non_modal();

	}
	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	int batterylimit() { return Shop.torsos[rp_torso->value()].getCompartments(); }
	void showBattery2() { rp_batteries2->show(); }
	void hideBattery2() { rp_batteries2->hide(); }
	void showBattery3() { rp_batteries3->show(); }
	void hideBattery3() { rp_batteries3->hide(); }

	void getCost() {}

	int arm1() { return rp_arm1->value(); }
	int arm2() { return rp_arm2->value(); }
	int torso() { return rp_torso->value(); }
	int battery1() { return rp_batteries1->value(); }
	int battery2() { return rp_batteries2->value(); }
	int battery3() { return rp_batteries3->value(); }
	int locomotor() { return rp_locomotor->value(); }
	int head() { return rp_head -> value(); }
	void returnPrice(double price) { 
		char myString[20] = "";
		sprintf(myString, "%.2f", price);
		rp_costReturn->value(myString); }

	string name() { return rp_name->value(); }
	string model_number() { return rp_model_number->value(); }
	string cost() { return rp_cost->value(); }
	string description() { return rp_description->value(); }
	void expandOptions() {
		//Arms
		for (int i = 0; i < Shop.arms.size(); i++)
		{
			rp_arm1->add(Shop.arms[i].getName().c_str());
		}
		for (int i = 0; i < Shop.arms.size(); i++)
		{
			rp_arm2->add(Shop.arms[i].getName().c_str());
		}
		//Locomotor
		for (int i = 0; i < Shop.locomotors.size(); i++)
		{
			rp_locomotor->add(Shop.locomotors[i].getName().c_str());
		}
		//Heads
		for (int i = 0; i < Shop.heads.size(); i++)
		{
			rp_head->add(Shop.heads[i].getName().c_str());
		}
		//Torso
		for (int i = 0; i < Shop.torsos.size(); i++)
		{
			rp_torso->add(Shop.torsos[i].getName().c_str());
		}
		//Batteries
		for (int i = 0; i < Shop.batteries.size(); i++)
		{
			rp_batteries1->add(Shop.batteries[i].getName().c_str());
		}
		for (int i = 0; i < Shop.batteries.size(); i++)
		{
			rp_batteries2->add(Shop.batteries[i].getName().c_str());
		}
		for (int i = 0; i < Shop.batteries.size(); i++)
		{
			rp_batteries3->add(Shop.batteries[i].getName().c_str());
		}

	}
	double calculatePrice() {
		double cost = 0;

		cost += Shop.arms[roboModelsGUIP->arm1()].getCost();
		cost += Shop.torsos[roboModelsGUIP->torso()].getCost();
		cost += Shop.heads[roboModelsGUIP->head()].getCost();
		cost += Shop.locomotors[roboModelsGUIP->locomotor()].getCost();
		cost += Shop.batteries[roboModelsGUIP->battery1()].getCost();

		if (roboModelsGUIP->arm2() != 0)
		{
			cost += Shop.arms[roboModelsGUIP->arm2()-1].getCost();
		}
		if (roboModelsGUIP->batterylimit() == 2)
		{
			cost += roboModelsGUIP->battery2() != 0 ? Shop.batteries[roboModelsGUIP->battery2() - 1].getCost() : 0;
		}
		else if (roboModelsGUIP->batterylimit() == 3)
		{
			cost += roboModelsGUIP->battery2() != 0 ? Shop.batteries[roboModelsGUIP->battery2() - 1].getCost() : 0;
			cost += roboModelsGUIP->battery3() != 0 ? Shop.batteries[roboModelsGUIP->battery3() - 1].getCost() : 0 ;
		}
		return cost;
	}


private:
	Fl_Window *dialog;
	Fl_Button *rp_costBtn;
	Fl_Button *rp_image_btn;
	Fl_Input *rp_name;
	Fl_Input *rp_model_number;
	Fl_Choice *rp_arm1;
	Fl_Choice *rp_arm2;
	Fl_Choice *rp_torso;
	Fl_Choice *rp_locomotor;
	Fl_Choice *rp_batteries1;
	Fl_Choice *rp_batteries2;
	Fl_Choice *rp_batteries3;
	Fl_Choice *rp_head;
	Fl_Input *rp_weight;
	Fl_Input *rp_description;
	Fl_Input *rp_cost;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
	Fl_Output *rp_costReturn;

};
class orderCreateGUI {
public:
	orderCreateGUI() {
		int x = 800, y = 530, i;
		dialog = new Fl_Window(x, y, "Robot Part");

		rp_month = new Fl_Input(80, 10, 50, 25, "Date");
		rp_month->align(FL_ALIGN_LEFT);

		rp_day = new Fl_Input(140, 10, 50, 25, "/");
		rp_day->align(FL_ALIGN_LEFT);

		rp_year = new Fl_Input(200, 10, 50, 25, "/");
		rp_year->align(FL_ALIGN_LEFT);

		rp_customer = new Fl_Choice(150, 40, 210, 25, "What is your Name?");
		rp_associate = new Fl_Choice(150, 70, 210, 25, "Sales Associate?");
		rp_location = new Fl_Input(150, 110, 210, 25, "Shipping distance\n(miles)");
		rp_order_number = new Fl_Input(150, 140, 210, 25, "Order Number");

		rp_model = new Fl_Choice(500, 40, 210, 25, "Robot Model");
		rp_model->align(FL_ALIGN_TOP);
		rp_model->callback((Fl_Callback *)getRobotInfoCB, 0);



		rp_cost = new Fl_Output(500, 350, 210, 25, "Set Price:");
		rp_cost->align(FL_ALIGN_LEFT);

		rp_total_cost = new Fl_Output(500, 480, 210, 25, "Total Cost");
		rp_total_cost->align(FL_ALIGN_LEFT);

		rp_description = new Fl_Multiline_Output(500, 380, 210, 75, "Description:");
		rp_description->align(FL_ALIGN_LEFT);

		rp_create = new Fl_Return_Button(145, 300, 120, 25, "Create");
		rp_create->callback((Fl_Callback *)createOrderCB, 0);

		rp_cancel = new Fl_Button(270, 300, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancelOrder, 0);

		dialog->end();
		dialog->set_non_modal();

	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }
	void updateDropdowns() {
		for (int i = 0; i< Shop.customers.size(); i++)
		{
			rp_customer->add(Shop.customers[i].getName().c_str());
		}
		for (int i = 0; i< Shop.associates.size(); i++)
		{
			rp_associate->add(Shop.associates[i].getAssociateName().c_str());
		}
		for (int i = 0; i< Shop.completedModels.size(); i++)
		{
			rp_model->add(Shop.completedModels[i].getRobotName().c_str());
		}
	}
	void updateRobotInfo(){
		char myString[30] = "";
		sprintf(myString, "%.2f", Shop.completedModels[rp_model->value()].getModelAskingPrice());
		rp_cost->value(myString);
		rp_description->value(Shop.completedModels[rp_model->value()].getRobotDescription().c_str());
		sprintf(myString, "%.2f", Shop.completedModels[rp_model->value()].getModelAskingPrice() + stof(rp_location->value()) * .05);
		rp_total_cost->value(myString);

	}
	int customer(){ return rp_customer->value(); }
	int month() { return stoi(rp_month->value()); }
	int day() { return stoi(rp_day->value()); }
	int year() { return stoi(rp_year->value()); }
	int associates() { return rp_associate->value(); }
	int model() { return rp_model->value(); }
	int orderNumber() { return stoi(rp_order_number->value()); }
	double askingPrice() { return Shop.completedModels[rp_model->value()].getModelAskingPrice(); };


private:
	Fl_Window *dialog;
	Fl_Input *rp_order_number;
	Fl_Choice *rp_customer;
	Fl_Choice *rp_associate;
	Fl_Choice *rp_model;
	Fl_Input *rp_location;
	Fl_Input *rp_year;
	Fl_Input *rp_day;
	Fl_Input *rp_month;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;

	Fl_Output *rp_total_cost;
	Fl_Multiline_Output *rp_description;
	Fl_Output *rp_cost;

};
//
// Callbacks
//

//Customers
void CB(Fl_Widget* w, void* p) { } // No action

void createCustomerGUI(Fl_Widget* w, void* p) {
	customerGUIP->show();
}
void cancelCustomer(Fl_Widget* w, void* p) {
	customerGUIP->hide();
}
void createCustomerCB(Fl_Widget* w, void* p)
{
	Shop.createCustomers(customerGUIP->name(), customerGUIP->address(), customerGUIP->phoneNumber(), customerGUIP->email());
	customerGUIP->hide();
}

//Sales Associates
void createSalesAssociateGUI(Fl_Widget* w, void* p) {
	salesAssociateGUIP->show();
}
void cancelSalesAssociate(Fl_Widget* w, void* p) {
	salesAssociateGUIP->hide();
}
void createSalesAccociateCB(Fl_Widget* w, void* p)
{
	Shop.createSalesAssociate(salesAssociateGUIP->name(), salesAssociateGUIP->employeeNumber());
	salesAssociateGUIP->hide();
}

//RoboParts
void createRoboPartsGUI(Fl_Widget* w, void* p) {
	roboPartsGUIP->show();
}
void cancelRoboParts(Fl_Widget* w, void* p){
	roboPartsGUIP->hide();
}
void createRoboPartsCB(Fl_Widget* w, void* p) {

	int partNumber = stoi(roboPartsGUIP->part_number());
	double weight = stof(roboPartsGUIP->weight());
	double cost = stof(roboPartsGUIP->cost());


	if (roboPartsGUIP->type() == 0) {
		double power = stof(roboPartsGUIP->power());
		Shop.createPart(partNumber, roboPartsGUIP->name(), roboPartsGUIP->type(), weight, cost, roboPartsGUIP->description(), power, 0, 0, 0);
		Shop.printinfoArms();
	}

	if (roboPartsGUIP->type() == 1){
		double energy = stof(roboPartsGUIP->energy());
		Shop.createPart(partNumber, roboPartsGUIP->name(), roboPartsGUIP->type(), weight, cost, roboPartsGUIP->description(), 0, 0, energy, 0);
		Shop.printinfoBatteries();
	}

	if (roboPartsGUIP->type() == 2){
		Shop.createPart(partNumber, roboPartsGUIP->name(), roboPartsGUIP->type(), weight, cost, roboPartsGUIP->description(),0,0,0,0);
		Shop.printinfoHeads();
	}

	if (roboPartsGUIP->type() == 3){
		Shop.createPart(partNumber, roboPartsGUIP->name(), roboPartsGUIP->type(), weight, cost, roboPartsGUIP->description(), 0, 0, 0, roboPartsGUIP->compartments() + 1);
		Shop.printinfoTorsos();
	}

	if (roboPartsGUIP->type() == 4){
		double power = stof(roboPartsGUIP->power());
		double speed = stof(roboPartsGUIP->speed());
		Shop.createPart(partNumber, roboPartsGUIP->name(), roboPartsGUIP->type(), weight, cost, roboPartsGUIP->description(), power, speed, 0, 0);
		Shop.printinfoLocomotors();
	}

	roboPartsGUIP->hide();

}
void specifyGUI(Fl_Widget* w, void* p) {
	if (roboPartsGUIP->type() == 0)
	{
		roboPartsGUIP->showPower();
		roboPartsGUIP->hideSpeed();
		roboPartsGUIP->hideEnergy();
		roboPartsGUIP->hideCompartments();
	}
	else if (roboPartsGUIP->type() == 1)
	{
		roboPartsGUIP->hidePower();
		roboPartsGUIP->hideSpeed();
		roboPartsGUIP->showEnergy();
		roboPartsGUIP->hideCompartments();
	}
	else if (roboPartsGUIP->type() == 2)
	{
		roboPartsGUIP->hidePower();
		roboPartsGUIP->hideSpeed();
		roboPartsGUIP->hideEnergy();
		roboPartsGUIP->hideCompartments();
	}
	else if (roboPartsGUIP->type() == 3)
	{
		roboPartsGUIP->hidePower();
		roboPartsGUIP->hideSpeed();
		roboPartsGUIP->hideEnergy();
		roboPartsGUIP->showCompartments();
	}
	else if (roboPartsGUIP->type() == 4)
	{
		roboPartsGUIP->showPower();
		roboPartsGUIP->showSpeed();
		roboPartsGUIP->hideEnergy();
		roboPartsGUIP->hideCompartments();
	}
}



//RoboModels
void createModelsGUI(Fl_Widget* w, void* p) {
	roboModelsGUIP->expandOptions();
	roboModelsGUIP->show();
}
void cancelModel(Fl_Widget* w, void* p) {
	roboModelsGUIP->hide();
}
void createModelCB(Fl_Widget* w, void* p) {
	
	string name = roboModelsGUIP->name();
	string cost = roboModelsGUIP->cost();
	string modelNumber = roboModelsGUIP->model_number();
	string description = roboModelsGUIP->description();
	int arm1 = roboModelsGUIP->arm1();
	int arm2 = roboModelsGUIP->arm2() == 0 ? -1 : roboModelsGUIP->arm2();
	int battery1 = roboModelsGUIP->battery1();
	int head = roboModelsGUIP->head();
	int torso = roboModelsGUIP->torso();
	int locomotor = roboModelsGUIP->locomotor();
	//Special battery cases
	int battery2 = roboModelsGUIP->battery2() == 0 ? -1 : roboModelsGUIP->battery2();
	int battery3 = roboModelsGUIP->battery3() == 0 ? -1 : roboModelsGUIP->battery3();
	if (roboModelsGUIP->batterylimit() == 1)
	{
		battery2 = -1;
		battery3 = -1;
	}
	else if (roboModelsGUIP->batterylimit() == 2)
	{
		battery3 = -1;
	}

	Shop.createModel(name, cost, modelNumber, description, arm1, arm2 - 1 , battery1, battery2 - 1 , battery3 - 1, head, torso, locomotor);

	roboModelsGUIP->hide();
}
void batteryLimitCB(Fl_Widget* w, void* p) {

	if (1 == roboModelsGUIP->batterylimit()) {
		roboModelsGUIP->hideBattery2();
		roboModelsGUIP->hideBattery3();
	}
	else if (2 == roboModelsGUIP->batterylimit()) {
		roboModelsGUIP->showBattery2();
		roboModelsGUIP->hideBattery3();
	}
	else if (3 == roboModelsGUIP->batterylimit()) {
		roboModelsGUIP->showBattery2();
		roboModelsGUIP->showBattery3();
	}

}
void getPrice(Fl_Widget* w, void* p) {
	roboModelsGUIP->returnPrice(roboModelsGUIP->calculatePrice());
}

//CreateOrders
void createOrdersGUI(Fl_Widget* w, void* p) {
	orderCreateGUIP->updateDropdowns();
	orderCreateGUIP->show();
}
void cancelOrder(Fl_Widget* w, void* p) {
	orderCreateGUIP->hide();
}
void createOrderCB(Fl_Widget* w, void* p) {

	Shop.createOrder(orderCreateGUIP->orderNumber(), orderCreateGUIP->month(), orderCreateGUIP->day(), orderCreateGUIP->year(), orderCreateGUIP->askingPrice(), orderCreateGUIP->associates(), orderCreateGUIP->customer(), orderCreateGUIP->model());
	orderCreateGUIP->hide();
}
void getRobotInfoCB(Fl_Widget* w, void* p) {
	orderCreateGUIP->updateRobotInfo();
}






//
// Menu
//

Fl_Menu_Item menuitems[] = {
	{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order", 0, (Fl_Callback *)createOrdersGUI, 0, FL_MENU_DIVIDER },
	{ "Customer", 0, (Fl_Callback *)createCustomerGUI },
	{ "Sales Associate", 0, (Fl_Callback *)createSalesAssociateGUI, 0, FL_MENU_DIVIDER },
	{ "Robot Part", 0, (Fl_Callback *)createRoboPartsGUI },
	{ "Robot Model", 0, (Fl_Callback *)createModelsGUI },
	{ 0 }
};

//
// Main
//

int main() {
	const int X = 500;
	const int Y = 400;

	Shop.createPart(1, "Arm1", 0, 5, 8, "Its an arm 1", 15, 0, 0, 0);
	Shop.createPart(2, "Arm2", 0, 10, 16, "Its an arm 2", 30, 0, 0, 0);
	Shop.createPart(3, "Battery1", 1, 15, 24, "Its a Battery 1",0, 0, 17, 0);
	Shop.createPart(4, "Battery2", 1, 20, 32, "Its an Battery 2", 0, 0, 34, 0);
	Shop.createPart(9, "Head1", 2, 25, 40, "Its an Head 1", 0, 0, 0, 0);
	Shop.createPart(10, "Head2", 2, 30, 48, "Its an Head 2 ", 0, 0, 0, 0);
	Shop.createPart(5, "Torso1", 3, 35, 56,  "Its an torso 1", 0, 0, 0, 1);
	Shop.createPart(6, "Torso3", 3, 40, 64, "Its an  Torsos 3", 0, 0, 0, 3);
	Shop.createPart(8, "Torso2", 3, 40, 64, "Its an  Torsos 2", 0, 0, 0, 2);
	Shop.createPart(7, "Locomotor1", 4, 72, 45 , "Its an Loco 1", 16, 19, 0, 0);
	Shop.createPart(8, "Locomotor2", 4, 50,80 , "Its an Loco 2", 32, 38, 0, 0);
	
 //Tester Input



	// Create dialogs
	customerGUIP = new customerGUI{};
	salesAssociateGUIP = new salesAssociateGUI{};
	roboPartsGUIP = new roboPartsGUI{};
	roboModelsGUIP = new roboModelsGUI{};
	orderCreateGUIP = new orderCreateGUI{};

	// Create a window
	win = new Fl_Window{ X, Y, "Robbie Robot Shop Manager" };
	win->color(FL_WHITE);

	// Install menu bar
	menubar = new Fl_Menu_Bar(0, 0, X, 30);
	menubar->menu(menuitems);

	// Wrap it up and let FLTK do its thing
	win->end();
	win->show();
	return(Fl::run());
}
