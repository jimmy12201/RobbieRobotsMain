#pragma once
#ifndef __CUSTOMERGUI_H
#define __CUSTOMERGUI_H 2016
#include "RobbieRobotsMain.cpp"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Multiline_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <iostream>


using namespace std;

class customerGUI {
public:
	customerGUI() {
		dialog = new Fl_Window(340, 270, "Robot Part");

		rp_create = new Fl_Return_Button(145, 240, 120, 25, "Create");
		//rp_create->callback((Fl_Callback *)create_robot_partCB, 0);

		rp_cancel = new Fl_Button(270, 240, 60, 25, "Cancel");
		rp_cancel->callback((Fl_Callback *)cancel_robot_partCB, 0);

		dialog->end();
		dialog->set_non_modal();
	}

	void show() { dialog->show(); }
	void hide() { dialog->hide(); }

private:

	int test;
	Fl_Window *dialog;
	Fl_Input *nameField;
	Fl_Button *rp_create;
	Fl_Button *rp_cancel;
};

#endif