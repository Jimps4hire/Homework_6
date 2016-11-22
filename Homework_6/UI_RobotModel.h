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
#include "RobotPart.h"

class UI_RobotModel
{
public:
	static UI_RobotModel *part;

	Fl_Input *f_name_input;
	Fl_Input *f_desc_input;
	Fl_Input *f_type_input;
	Fl_Input *f_modelno_input;
	Fl_Input *f_price_input;
	Fl_Input *f_shipping_input;
//	Fl_Input *f_total_input;
	Fl_Choice *f_part_choice;
	Fl_Choice *f_partno_choice;
	Fl_Input *f_quantity_input;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;
//	Fl_Text_Editor *f_comment_input;
	Fl_Return_Button *f_part_add;
	Fl_Button *f_part_delete;
	Fl_Double_Window *function_panel;
	Control_Table* f_table;
	RobotPart *head, *locomotor, *torso, *battery, *arm;

public:
	UI_RobotModel(void);
	~UI_RobotModel(void);
	static UI_RobotModel* create();
	Fl_Double_Window* create_panel();
	void open();
	void CreateModel();
	void AddPart();
	void updatePartData();
	static void robotModel_Part_cb(Fl_Widget* widget, void* userData) ;
	static void robotModel_Partno_cb(Fl_Widget* widget, void* userData) ;
};

