#include "StdAfx.h"
#include "UI_EditRobotModel.h"
#include "RobotShop.h"

UI_EditRobotModel* UI_EditRobotModel::model = new UI_EditRobotModel();

UI_EditRobotModel::UI_EditRobotModel(void)
{
}
UI_EditRobotModel* UI_EditRobotModel::create()
{
	return model;
}


UI_EditRobotModel::~UI_EditRobotModel(void)
{
}

void UI_EditRobotModel::open() {
  if (!function_panel) create_panel();
  
  function_panel->show();
  for (;;) { // repeat as long as there are errors
    for (;;) {
      Fl_Widget* w = Fl::readqueue();
      if (w == f_panel_cancel)
	  {
		goto BREAK2;
	  }
      else if (w == f_panel_ok)
	  {
		break;
	  }
      else if (!w)
	  {
		Fl::wait();
	  }
    }

    break;
  }
BREAK2:
  function_panel->hide();
}
Fl_Double_Window* UI_EditRobotModel::create_panel() 
{
  {
	RobotShop* robot = RobotShop::create();
	function_panel = new Fl_Double_Window(443, 202, "Robot Model");
    { 
	// robot model
	double price = 0;
	Product* product = robot->getProduct();
	list<RobotModel*> robotModel = product->getList();
//	if(f_robotModel_choice == (Fl_Choice *)0)
	{
		Fl_Menu_Item* menu_f_robotModel_choice = new Fl_Menu_Item[robotModel.size()+1];
		int i = 0;
		for(std::list<RobotModel*>::const_iterator iterator = robotModel.begin(), end = robotModel.end(); iterator != end; ++iterator) 
		{			
			Fl_Menu_Item* item = menu_f_robotModel_choice+i;
			RobotModel* robot = *iterator;
			string name = robot->getName();
			if(price == 0)
			{
				price = robot->getPrice();
			}
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = (Fl_Callback *)UI_EditRobotModel::robotModel_cb;
			item->user_data_ =  (void*)robot;
			item->flags = 0;
			item->labeltype_ = FL_NORMAL_LABEL;
			item->labelfont_ = FL_HELVETICA;
			item->labelsize_ = 11;
			item->labelcolor_ = 0;
			i++;
		}
		Fl_Menu_Item* item = menu_f_robotModel_choice+i;
		item->text = 0;
		item->shortcut_ = 0;
		item->callback_ = 0;
		item->user_data_ =  0;
		item->flags = 0;
		item->labeltype_ = 0;
		item->labelfont_ = 0;
		item->labelsize_ = 0;
		item->labelcolor_ = 0;

		f_robotModel_choice = new Fl_Choice(10, 10, 320, 20, "Robot Model:");
		f_robotModel_choice->tooltip("Robot Model");
		f_robotModel_choice->down_box(FL_BORDER_BOX);
		f_robotModel_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		f_robotModel_choice->labelsize(11);
		f_robotModel_choice->textsize(11);
		f_robotModel_choice->when(FL_WHEN_CHANGED);
		f_robotModel_choice->menu(menu_f_robotModel_choice);
	}

    { f_price_input = new Fl_Input(10, 50, 120, 20, "Price:");
      f_price_input->tooltip("Price");
      f_price_input->labelfont(1);
      f_price_input->labelsize(11);
      f_price_input->textfont(4);
      f_price_input->textsize(11);
      f_price_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_price_input->when(FL_WHEN_NEVER);

//	  string strPr = to_string((long double)price);
//	  const char *cstr = strPr.c_str();
//	  f_price_input->static_value(strdup(cstr));
    } // Fl_Input* f_return_type_input

	{ f_hide_check = new Fl_Check_Button(145, 50, 120, 20, "Hide Robot Model:");
      f_hide_check->tooltip("Hide Robot Model");
      f_hide_check->labelfont(1);
      f_hide_check->labelsize(11);
//      f_hide_check->textfont(4);
//      f_hide_check->textsize(11);
	  f_hide_check->callback((Fl_Callback*) UI_EditRobotModel::hidePart_ck);
      f_hide_check->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_hide_check->when(FL_WHEN_CHANGED);
    } 

    { Fl_Group* o = new Fl_Group(10, 90, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 90, 50, 20, "OK");
        f_panel_ok->tooltip("Create order.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 90, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the order.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 90, 205, 20);
        Fl_Group::current()->resizable(o);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    } 
    function_panel->set_modal();
    function_panel->end();
  } // Fl_Double_Window* function_panel
  return function_panel;
}
void UI_EditRobotModel::robotModel_cb(Fl_Widget* widget, void* userData) 
{
	RobotModel* robot = (RobotModel*)userData;
	double price = robot->getPrice();
	string strPr = to_string((long double)price);
	const char *cstr = strPr.c_str();
	
	UI_EditRobotModel* model = UI_EditRobotModel::create();
    model->f_price_input->static_value(strdup(cstr));

	model->f_hide_check->user_data((void*) robot);
	bool hide = robot->getHide();
	if(hide)
	{
		model->f_hide_check->set();
	}
	else
	{
		model->f_hide_check->value(0);
	}
}
void UI_EditRobotModel::hidePart_ck(Fl_Widget* widget, void* userData) 
{
	Fl_Check_Button* hide_check = (Fl_Check_Button*)widget;
	RobotModel* robot = (RobotModel*)userData;
	if(robot != NULL)
	{
		if(hide_check->value() == 1)
		{
			robot->setHide(true);
		}
		else
		{
			robot->setHide(false);
		}
	}
}
