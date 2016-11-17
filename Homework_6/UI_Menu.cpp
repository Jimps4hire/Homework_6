#include "StdAfx.h"
#include "UI_Menu.h"
#include <FL/Fl_Window.H>
#include <FL/Fl_Native_File_Chooser.H>
#include <FL/fl_message.H>
#include "RobotShop.h"
#include "Utility.h"
#include "UI_Order.h"
#include "UI_Customer.h"
#include "UI_SalesAssociate.h"

using namespace std;
using namespace System;

extern int fl_choice(const char*fmt,const char *b0,const char *b1,const char *b2,...);

Fl_Menu_Item menuitems[] = {
	{ "&File",              0, 0, 0, FL_SUBMENU },
	{ "&New File",        0, (Fl_Callback *)UI_Menu::new_cb },
	{ "&Open File...",    FL_COMMAND + 'o', (Fl_Callback *)UI_Menu::open_cb },
	{ "&Save File",       FL_COMMAND + 's', (Fl_Callback *)UI_Menu::save_cb },
	{ "Save File &As...", FL_COMMAND + FL_SHIFT + 's', (Fl_Callback *)UI_Menu::saveas_cb, 0, FL_MENU_DIVIDER },
	{ "E&xit",            FL_COMMAND + 'q', (Fl_Callback *)UI_Menu::quit_cb, 0 },
    { 0 },
	{ "&Create", 0, 0, 0, FL_SUBMENU },
	{ "Order",             FL_COMMAND + 'x', (Fl_Callback *)UI_Menu::order_cb, 0, FL_MENU_DIVIDER },
	{ "&Customer",            FL_COMMAND + 'c', (Fl_Callback *)UI_Menu::customer_cb },
	{ "Sales &Associate",           FL_COMMAND + 'a', (Fl_Callback *)UI_Menu::salesAss_cb, 0, FL_MENU_DIVIDER },
	{ "Robot &Part",          FL_COMMAND + 'p', (Fl_Callback *)UI_Menu::part_cb },
	{ "Robot &Model",          FL_COMMAND + 'm', (Fl_Callback *)UI_Menu::model_cb },
    { 0 },

	{ "&Report", 0, 0, 0, FL_SUBMENU },
	{ "All Orders",         FL_COMMAND + FL_SHIFT + 'x', (Fl_Callback *)UI_Menu::orders_cb },
	{ "Orders by Customer",      FL_COMMAND + FL_SHIFT + 'c', UI_Menu::orderByCust_cb },
	{ "Order by Sales Associate",      FL_COMMAND + FL_SHIFT + 'a', UI_Menu::orderBySA_cb, 0, FL_MENU_DIVIDER },
	{ "All Customers",   FL_COMMAND + FL_CTRL + 'c', UI_Menu::allCust_cb },
	{ "All Sales Associates",   FL_COMMAND + FL_CTRL + 'a', UI_Menu::allSA_cb, 0, FL_MENU_DIVIDER },
	{ "All Robort Models",   FL_COMMAND + FL_SHIFT + 'm', UI_Menu::allModels_cb },
	{ "All Robot Parts",   FL_COMMAND + FL_SHIFT + 'p', UI_Menu::allParts_cb },
	{ 0 },

    { 0 }
};

UI_Menu::UI_Menu(void)
{
}
UI_Menu::UI_Menu(Fl_Window *win)
{
	Fl_Menu_Bar* m = new Fl_Menu_Bar(0, 0, 660, 30);
    m->copy(menuitems, win);
}


UI_Menu::~UI_Menu(void)
{
}
void UI_Menu::new_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::open_cb(Fl_Widget*, void*) 
{
	// open xml file
	const char *c;
	Fl_Native_File_Chooser fnfc;
	fnfc.title("Open:");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	fnfc.filter("Robot Shop Files\t*.xml\n");
	if (fnfc.show() != 0) return;
	c = fnfc.filename();

	// load the file
	RobotShop* robotShop = RobotShop::create();
	robotShop->deserialize(c);

}
void UI_Menu::save_cb(Fl_Widget*, void*) 
{
	RobotShop* robotShop = RobotShop::create();
	if(!robotShop->IsFileOpen())
	{
//		fl_choice("Robot Shop is not open", "Close",  NULL, NULL);
		fl_message("Robot Shop is not open");
		return;
	}

	// save xml file
	Fl_Native_File_Chooser fnfc;
	const char *c = "RobotShop.xml";

	/*
	fnfc.title("Save To:");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
	fnfc.filter("Robot Shop Files\t*.xml\n");
	if (fnfc.show() != 0) return;
	c = fnfc.filename();
	*/

	// save the file
	robotShop->serialize(c);
}
void UI_Menu::saveas_cb(Fl_Widget*, void*) 
{
	RobotShop* robotShop = RobotShop::create();
	if(!robotShop->IsFileOpen())
	{
//		fl_choice("Robot Shop is not open", "Close",  NULL, NULL);
		fl_message("Robot Shop is not open");
		return;
	}

	// save xml file
	Fl_Native_File_Chooser fnfc;
	const char *c = "RobotShop.xml";

	fnfc.title("Save To:");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
	fnfc.filter("Robot Shop Files\t*.xml\n");
	if (fnfc.show() != 0) return;
	c = fnfc.filename();

	// save the file
	robotShop->serialize(c);
}
void UI_Menu::quit_cb(Fl_Widget*, void*) 
{
	exit(0);
}
void UI_Menu::order_cb(Fl_Widget*, void*) 
{
	RobotShop* robotShop = RobotShop::create();
	if(!robotShop->IsFileOpen())
	{
		fl_message("Robot Shop is not open");
		return;
	}

	UI_Order* order = UI_Order::create();
	Fl_Double_Window* dlg = order->create_panel();
	order->open();

	/*
	Fl_Window* dlg = new Fl_Window(70, 70 , 400, 300 , "dialog" ) ;
    dlg->end();
	dlg->set_modal();
	dlg->show();
	while (dlg->visible() && Fl::check()) 
		Fl::wait();
	*/
}
void UI_Menu::customer_cb(Fl_Widget*, void*) 
{
	RobotShop* robotShop = RobotShop::create();
	if(!robotShop->IsFileOpen())
	{
		fl_message("Robot Shop is not open");
		return;
	}

	UI_Customer* customer = UI_Customer::create();
	Fl_Window* dlg = customer->create_panel();
	customer->open();

}
void UI_Menu::salesAss_cb(Fl_Widget*, void*) 
{
	RobotShop* robotShop = RobotShop::create();
	if(!robotShop->IsFileOpen())
	{
		fl_message("Robot Shop is not open");
		return;
	}

	UI_SalesAssociate* sa = UI_SalesAssociate::create();
	Fl_Double_Window* dlg = sa->create_panel();
	sa->open();
}
void UI_Menu::part_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::model_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::orders_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::orderByCust_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::orderBySA_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::allCust_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::allSA_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::allModels_cb(Fl_Widget*, void*) 
{
}
void UI_Menu::allParts_cb(Fl_Widget*, void*) 
{
}
