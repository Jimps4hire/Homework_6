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
#include "FL/Fl_Box.h"
#include "FL/Fl_JPEG_Image.h"
#include <FL/Fl_Check_Button.H>
#include "RobotShop.h"
using namespace std;
using namespace System;

class UI_EditRobotPart
{
	static UI_EditRobotPart *part;

	Fl_Choice *f_part_choice;
	Fl_Choice *f_partno_choice;
//	Fl_Input *f_desc_input;
	Fl_Input *f_type_input;
	Fl_Input *f_partno_input;
	Fl_Input *f_weight_input;
	Fl_Input *f_cost_input;
	Fl_Check_Button *f_hide_check;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;
	Fl_Double_Window *function_panel;

public:
	UI_EditRobotPart(void);
	~UI_EditRobotPart(void);
	static UI_EditRobotPart* create();
	void open();
	Fl_Double_Window* create_panel() ;
	static void robot_Part_cb(Fl_Widget* widget, void* userData);
	static void robotPartno_cb(Fl_Widget* widget, void* userData) ;
	static void hidePart_ck(Fl_Widget* widget, void* userData);
};

