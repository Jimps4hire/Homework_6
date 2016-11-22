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

class UI_RobotPart
{
	static UI_RobotPart *part;

	Fl_Choice *f_part_choice;
	Fl_Input *f_desc_input;
	Fl_Input *f_type_input;
	Fl_Input *f_partno_input;
	Fl_Input *f_weight_input;
	Fl_Input *f_cost_input;
//	Fl_Input *f_total_input;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;
//	Fl_Text_Editor *f_comment_input;
	Fl_Double_Window *function_panel;

public:
	UI_RobotPart(void);
	~UI_RobotPart(void);
	static UI_RobotPart* create();
	Fl_Double_Window* create_panel();
	void open();
	void CreatePart();
};

