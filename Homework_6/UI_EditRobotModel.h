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
#include <FL/Fl_Check_Button.H>
#include "FL/Fl_Box.h"

class UI_EditRobotModel
{
	static UI_EditRobotModel *model;

	Fl_Choice *f_robotModel_choice;
	Fl_Input *f_price_input;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;
	Fl_Check_Button *f_hide_check;
	Fl_Double_Window *function_panel;

public:
	UI_EditRobotModel(void);
	~UI_EditRobotModel(void);

	static UI_EditRobotModel* create();
	Fl_Double_Window* create_panel();
	void open();
	static void robotModel_cb(Fl_Widget*, void*);
	static void hidePart_ck(Fl_Widget* widget, void* userData);
};

