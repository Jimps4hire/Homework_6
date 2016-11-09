#include "StdAfx.h"
#include "UI_Customer.h"
#include "FL/Fl_Box.h"
#include "RobotShop.h"
#include <string>
#include <sstream>
using namespace std;
using namespace System;

UI_Customer* UI_Customer::customer = new UI_Customer();

UI_Customer::UI_Customer(void)
{
	f_name_input=(Fl_Input *)0;
}


UI_Customer::~UI_Customer(void)
{
}

UI_Customer* UI_Customer::create()
{
	return customer;
}

void UI_Customer::open() {
  if (!function_panel) create_panel();
  
    f_name_input->value(0);
    f_name_input->show();

  function_panel->show();
//  const char* message = 0;
  for (;;) { // repeat as long as there are errors
    for (;;) {
      Fl_Widget* w = Fl::readqueue();
      if (w == f_panel_cancel)
	  {
		goto BREAK2;
	  }
      else if (w == f_panel_ok)
	  {
		CreateCustomer();
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
Fl_Double_Window* UI_Customer::create_panel() {
  {
	function_panel = new Fl_Double_Window(343, 122, "Customer");
	{
		Fl_Group* o = new Fl_Group(10, 10, 270, 20);

		{ f_name_input = new Fl_Input(10, 50, 320, 20, "Name:");
		  f_name_input->tooltip("The customer name");
		  f_name_input->labelfont(1);
		  f_name_input->labelsize(11);
		  f_name_input->textfont(4);
		  f_name_input->textsize(11);
		  f_name_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		  f_name_input->when(FL_WHEN_NEVER);
		} // Fl_Input* f_name_input


      { Fl_Box* box = new Fl_Box(235, 10, 45, 20);
        Fl_Group::current()->resizable(box);
      } // Fl_Box* o
      o->end();
	}

	/*
    { f_name_input = new Fl_Input(10, 50, 320, 20, "Name:");
      f_name_input->tooltip("The customer name");
      f_name_input->labelfont(1);
      f_name_input->labelsize(11);
      f_name_input->textfont(4);
      f_name_input->textsize(11);
      f_name_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_name_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_name_input
	*/

    { Fl_Group* o = new Fl_Group(10, 90, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 90, 50, 20, "OK");
        f_panel_ok->tooltip("Create customer.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 90, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the customer.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 90, 205, 20);
        Fl_Group::current()->resizable(o);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    function_panel->set_modal();
    function_panel->end();
  } // Fl_Double_Window* function_panel
  return function_panel;
}
void UI_Customer::CreateCustomer()
{
	RobotShop* robot = RobotShop::create();

	string* strcustomer = new string(f_name_input->value());
	Customer* p_customer = new Customer(*strcustomer);

	robot->AddCustomer(p_customer);
}