#pragma once
#include <FL/Fl.H>
#include <FL/Fl_Menu_Bar.H>

class UI_Menu
{
public:
	UI_Menu(void);
	UI_Menu(Fl_Window *win);
	~UI_Menu(void);

	static void new_cb(Fl_Widget*, void*); 
	static void open_cb(Fl_Widget*, void*);
	static void save_cb(Fl_Widget*, void*);
	static void saveas_cb(Fl_Widget*, void*); 
	static void quit_cb(Fl_Widget*, void*); 
	static void order_cb(Fl_Widget*, void*); 
	static void customer_cb(Fl_Widget*, void*); 
	static void salesAss_cb(Fl_Widget*, void*); 
	static void part_cb(Fl_Widget*, void*); 
	static void model_cb(Fl_Widget*, void*); 
	static void hidepart_cb(Fl_Widget*, void*); 
	static void hidemodel_cb(Fl_Widget*, void*); 
	static void orderBySA_cb(Fl_Widget*, void*); 
	static void allCust_cb(Fl_Widget*, void*); 
	static void allSA_cb(Fl_Widget*, void*); 
	static void allModels_cb(Fl_Widget*, void*); 
	static void allParts_cb(Fl_Widget*, void*); 
	static void browsecatalog_cb(Fl_Widget*, void*); 
};

