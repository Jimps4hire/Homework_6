#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include "FL/Fl_Double_Window.h"
#include <FL/Fl_Menu_Bar.H>

class UI_Customer
{
	static UI_Customer *customer;

	Fl_Input *f_name_input;
	Fl_Window *function_panel;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;

public:
	UI_Customer(void);
	~UI_Customer(void);

	static UI_Customer* create();
	Fl_Window* create_panel();
	void open();
	void CreateCustomer();
};

