#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include "FL/Fl_Double_Window.h"
#include <FL/Fl_Menu_Bar.H>

class UI_SalesAssociate
{
	static UI_SalesAssociate *sa;

	Fl_Input *f_name_input;
	Fl_Double_Window *function_panel;
	Fl_Return_Button *f_panel_ok;
	Fl_Button *f_panel_cancel;

public:
	UI_SalesAssociate(void);
	~UI_SalesAssociate(void);

	static UI_SalesAssociate* create();
	Fl_Double_Window* create_panel();
	void open();
	void CreateSA();
};

