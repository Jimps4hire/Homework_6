#include "StdAfx.h"
#include "UI_RobotPart.h"
#include "FL/Fl_Box.h"
#include "RobotShop.h"
#include <string>
#include <sstream>
using namespace std;
using namespace System;

extern double string_to_double( const std::string& s );

Fl_Menu_Item menu_f_part_choice[] = {
 {"Arm", 0,  0, (void*)(0), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Battery", 0,  0, (void*)(1), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Head", 0,  0, (void*)(2), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Locomotor", 0,  0, (void*)(3), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Torso", 0,  0, (void*)(4), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

UI_RobotPart::UI_RobotPart(void)
{
}
UI_RobotPart* UI_RobotPart::create()
{
	return part;
}

UI_RobotPart* UI_RobotPart::part = new UI_RobotPart();

UI_RobotPart::~UI_RobotPart(void)
{
}

Fl_Double_Window* UI_RobotPart::create_panel() {
  {
	function_panel = new Fl_Double_Window(343, 242, "Robot Part");
    { 
		Fl_Group* o = new Fl_Group(10, 10, 270, 20);

//	if(f_part_choice == (Fl_Choice *)0)
	{
		f_part_choice = new Fl_Choice(10, 10, 120, 20, "Parts");
		f_part_choice->tooltip("Part");
		f_part_choice->down_box(FL_BORDER_BOX);
		f_part_choice->labelsize(11);
		f_part_choice->textsize(11);
//		f_part_choice->when(FL_WHEN_CHANGED);
		f_part_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		f_part_choice->menu(menu_f_part_choice);
	}

      { Fl_Box* box = new Fl_Box(235, 10, 45, 20);
        Fl_Group::current()->resizable(box);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o

    { f_desc_input = new Fl_Input(10, 50, 250, 20, "Description:");
      f_desc_input->tooltip("Description");
      f_desc_input->labelfont(1);
      f_desc_input->labelsize(11);
      f_desc_input->textfont(4);
      f_desc_input->textsize(11);
      f_desc_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_desc_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

    { f_type_input = new Fl_Input(145, 90, 120, 20, "Part Type:");
      f_type_input->tooltip("Part Type");
      f_type_input->labelfont(1);
      f_type_input->labelsize(11);
      f_type_input->textfont(4);
      f_type_input->textsize(11);
      f_type_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_type_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

    { f_partno_input = new Fl_Input(10, 90, 120, 20, "Part No:");
      f_partno_input->tooltip("Part No");
      f_partno_input->labelfont(1);
      f_partno_input->labelsize(11);
      f_partno_input->textfont(4);
      f_partno_input->textsize(11);
      f_partno_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_partno_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

	{ f_weight_input = new Fl_Input(145, 130, 120, 20, "Weight:");
      f_weight_input->tooltip("Weight");
      f_weight_input->labelfont(1);
      f_weight_input->labelsize(11);
      f_weight_input->textfont(4);
      f_weight_input->textsize(11);
      f_weight_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_weight_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input


	{ f_cost_input = new Fl_Input(10, 130, 120, 20, "Cost:");
      f_cost_input->tooltip("Cost");
      f_cost_input->labelfont(1);
      f_cost_input->labelsize(11);
      f_cost_input->textfont(4);
      f_cost_input->textsize(11);
      f_cost_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_cost_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

	/*
	{ f_total_input = new Fl_Input(145, 170, 120, 20, "Total:");
      f_total_input->tooltip("Total");
      f_total_input->labelfont(1);
      f_total_input->labelsize(11);
      f_total_input->textfont(4);
      f_total_input->textsize(11);
      f_total_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_total_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input
	*/

    { Fl_Group* o = new Fl_Group(10, 220, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 220, 50, 20, "OK");
        f_panel_ok->tooltip("Create order.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 220, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the order.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 220, 205, 20);
        Fl_Group::current()->resizable(o);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    function_panel->set_modal();
    function_panel->end();
  } // Fl_Double_Window* function_panel
  return function_panel;
}

void UI_RobotPart::open() {
  if (!function_panel) create_panel();
  
    f_part_choice->value(0);
    f_part_choice->show();

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
		CreatePart();
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
void UI_RobotPart::CreatePart()
{
	RobotShop* robot = RobotShop::create();
	Inventory* inv = robot->GetInventory();
	string* strpart = new string(f_part_choice->text());
	string* strtype = new string(f_type_input->value());
	string* strdesc = new string(f_desc_input->value());
	string* strpartno = new string(f_partno_input->value());
	string* strweight = new string(f_weight_input->value());
	string* strcost = new string(f_cost_input->value());

	int partno = atoi( strpartno->c_str());
	double weight = string_to_double(*strweight);
	double cost = string_to_double(*strcost);

	RobotPart* amr1 = RobotPart::createPart(*strpart, *strdesc, *strtype, partno, weight, cost);
	inv->addPart(amr1);
}
