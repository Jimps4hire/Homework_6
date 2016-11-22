#pragma once
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
#include "FL/Fl_JPEG_Image.h"
#include "RobotShop.h"
#include "OrderItem.h"
using namespace std;
using namespace System;

class UI_BrowseCatalog
{
	static UI_BrowseCatalog *catalog;

	Fl_Choice *f_robotModel_choice;
	Fl_Light_Button *f_c_button;
	Fl_Input *f_name_input;
	Fl_Input *f_price_input;
	Fl_Input *f_type_input;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;
	Fl_Text_Editor *f_comment_input;
	Fl_Double_Window *function_panel;
	Control_Table* f_table;
	Fl_JPEG_Image* f_image;
	Fl_Box* f_picturebox; 

public:
	UI_BrowseCatalog(void);
	~UI_BrowseCatalog(void);
	static UI_BrowseCatalog* create();
	void open();
	Fl_Double_Window* create_panel() ;
	static void robotModel_cb(Fl_Widget* widget, void* userData);
};

