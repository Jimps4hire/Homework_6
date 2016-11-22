#pragma once
#include <list>
//#include <string>
//#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Text_Editor.H>
#include "FL/Fl_Double_Window.h"
#include <FL/Fl_Menu_Bar.H>
#include "Control_Table.h"
#include "FL/Fl_Box.h"
#include "RobotShop.h"
#include "OrderItem.h"
using namespace std;
using namespace System;

class UI_Order
{
	static UI_Order *order;

	Fl_Choice *f_salesagent_choice;
	Fl_Choice *f_customer_choice;
	Fl_Choice *f_robotModel_choice;
//	Fl_Light_Button *f_c_button;
//	Fl_Input *f_name_input;
//	Fl_Input *f_return_type_input;
	Fl_Input *f_price_input;
	Fl_Input *f_quantity_input;
	Fl_Input *f_shipping_input;
	Fl_Input *f_tax_input;
	Fl_Input *f_subtotal_input;
	Fl_Input *f_total_input;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;
	Fl_Text_Editor *f_comment_input;
	Fl_Double_Window *function_panel;
//	Fl_Menu_Item* menus_f_customer_choice;
	Fl_Return_Button *f_robot_add;
	Fl_Button *f_robot_delete;
	Fl_Return_Button *f_robot_save;
	Fl_Button *f_robot_open;
	Control_Table* f_table;

	list<OrderItem*> items;

public:
	UI_Order(void);
	~UI_Order(void);

	static UI_Order* create();
	Fl_Double_Window* create_panel();
	void open();
	Fl_Double_Window* create_panel1();
	static void robotModel_cb(Fl_Widget*, void*);
	void CreateOrder();
	void Calculate();
	void AddRobot();
	void SaveOrder();
	void OpenOrder();
	void updateRobotData();
};

