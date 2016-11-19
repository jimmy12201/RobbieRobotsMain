#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Radio_Button.H>
#include <FL/Fl_Choice.H>
#include <iostream>
#include <string>
#include "Shop.h"

using namespace std;

shop Shop;

//
// Declarations (we'll define later, just need to declare some variables!)
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


//
// Widgets
//

Fl_Window *win;
Fl_Menu_Bar *menubar;
customerGUI *customerGUIP; // The dialog of interest!
salesAssociateGUI *salesAssociateGUIP;
roboPartsGUI *roboPartsGUIP;

//CUSTOMER GUI

class customerGUI {
public:
	customerGUI() {
		dialog = new Fl_Window(340, 270, "New Customer");

		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

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

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
	Fl_Return_Button *rp_create;
	Fl_Button *rp_cancel;
};

class salesAssociateGUI {
public:
	salesAssociateGUI(){
		dialog = new Fl_Window(340, 270, "New Sales Associate");

		rp_name = new Fl_Input(120, 10, 210, 25, "Name:");
		rp_name->align(FL_ALIGN_LEFT);

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

private:
	Fl_Window *dialog;
	Fl_Input *rp_name;
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
	Shop.createCustomers(customerGUIP->name());
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
	Shop.createSalesAssociate(salesAssociateGUIP->name());
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
	if (roboPartsGUIP->type() == 2)
	{
		cout << "### Creating robot part" << endl;
		cout << "Name    : " << roboPartsGUIP->name() << endl;
		cout << "Part #  : " << roboPartsGUIP->part_number() << endl;
		cout << "Type    : " << roboPartsGUIP->type() << endl;
		double weight = stof(roboPartsGUIP->weight());
		cout << "Weight    : " << weight << endl;
		double cost = stof(roboPartsGUIP->cost());
		cout << "Cost    : " << cost << endl;
		cout << "Descript: " << roboPartsGUIP->description() << endl;

		Shop.createPart(roboPartsGUIP->part_number(), roboPartsGUIP->name(), roboPartsGUIP->type(), weight, cost, roboPartsGUIP->description(),0,0,0);
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


//
// Menu
//

Fl_Menu_Item menuitems[] = {
	{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "Customer", 0, (Fl_Callback *)createCustomerGUI },
	{ "Sales Associate", 0, (Fl_Callback *)createSalesAssociateGUI, 0, FL_MENU_DIVIDER },
	{ "Robot Part", 0, (Fl_Callback *)createRoboPartsGUI },/*
	{ "Robot Model", 0, (Fl_Callback *)CB },
	{ 0 },
	{ "&Report", 0, 0, 0, FL_SUBMENU },
	{ "Invoice", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "All Orders", 0, (Fl_Callback *)CB },
	{ "Orders by Customer", 0, (Fl_Callback *)CB },
	{ "Orders by Sales Associate", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "All Customers", 0, (Fl_Callback *)CB },
	{ "All Sales Associates", 0, (Fl_Callback *)CB, 0, FL_MENU_DIVIDER },
	{ "All Robot Models", 0, (Fl_Callback *)CB },
	{ "All Robot Parts", 0, (Fl_Callback *)CB },
	{ 0 },
	{ "&Help", 0, 0, 0, FL_SUBMENU },
	{ "&Manual", 0, (Fl_Callback *)CB },
	{ "&About", 0, (Fl_Callback *)CB },
	{ 0 },*/
	{ 0 }
};

//
// Main
//

int main() {
	const int X = 500;
	const int Y = 400;

	// Create dialogs
	customerGUIP = new customerGUI{};
	salesAssociateGUIP = new salesAssociateGUI{};
	roboPartsGUIP = new roboPartsGUI{};

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
