#include "StdAfx.h"
#include "UI_EditRobotPart.h"

extern double string_to_double( const std::string& s );
extern string int_to_string( int num );
extern string double_to_string( double num );

Fl_Menu_Item menu_f_editpart_choice[] = {
 {"Arm", 0,  (Fl_Callback *)UI_EditRobotPart::robot_Part_cb, (void*)(0), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Battery", 0, (Fl_Callback *)UI_EditRobotPart::robot_Part_cb,  (void*)(1), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Head", 0,  (Fl_Callback *)UI_EditRobotPart::robot_Part_cb, (void*)(2), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Locomotor", 0,  (Fl_Callback *)UI_EditRobotPart::robot_Part_cb, (void*)(3), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Torso", 0,  (Fl_Callback *)UI_EditRobotPart::robot_Part_cb, (void*)(4), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};


UI_EditRobotPart* UI_EditRobotPart::part = new UI_EditRobotPart();

UI_EditRobotPart::UI_EditRobotPart(void)
{
}


UI_EditRobotPart::~UI_EditRobotPart(void)
{
}

UI_EditRobotPart* UI_EditRobotPart::create()
{
	return part;
}
void UI_EditRobotPart::open() {
  if (!function_panel) create_panel();

//  robot_Part_cb((Fl_Widget*) f_part_choice, (void*) 0); 

//  robotPartno_cb((Fl_Widget*) f_partno_input, (void*) f_partno_input->user_data());

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
Fl_Double_Window* UI_EditRobotPart::create_panel() {
  {
	function_panel = new Fl_Double_Window(343, 242, "Robot Part");
    {

		{
			f_part_choice = new Fl_Choice(10, 10, 120, 20, "Parts");
			f_part_choice->tooltip("Parts");
			f_part_choice->down_box(FL_BORDER_BOX);
			f_part_choice->labelsize(11);
			f_part_choice->textsize(11);
			f_part_choice->when(FL_WHEN_CHANGED);
			f_part_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
			f_part_choice->menu(menu_f_editpart_choice);
		}

		{
			f_partno_choice = new Fl_Choice(145, 10, 180, 20, "Name");
			f_partno_choice->tooltip("Name");
			f_partno_choice->down_box(FL_BORDER_BOX);
			f_partno_choice->labelsize(11);
			f_partno_choice->textsize(11);
			f_part_choice->when(FL_WHEN_CHANGED);
			f_partno_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		}


    { f_partno_input = new Fl_Input(10, 50, 120, 20, "Part No:");
      f_partno_input->tooltip("Part No");
      f_partno_input->labelfont(1);
      f_partno_input->labelsize(11);
      f_partno_input->textfont(4);
      f_partno_input->textsize(11);
      f_partno_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_partno_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

    { f_type_input = new Fl_Input(145, 50, 120, 20, "Part Type:");
      f_type_input->tooltip("Part Type");
      f_type_input->labelfont(1);
      f_type_input->labelsize(11);
      f_type_input->textfont(4);
      f_type_input->textsize(11);
      f_type_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_type_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

	{ f_cost_input = new Fl_Input(10, 90, 120, 20, "Cost:");
      f_cost_input->tooltip("Cost");
      f_cost_input->labelfont(1);
      f_cost_input->labelsize(11);
      f_cost_input->textfont(4);
      f_cost_input->textsize(11);
      f_cost_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_cost_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

	{ f_weight_input = new Fl_Input(145, 90, 120, 20, "Weight:");
      f_weight_input->tooltip("Weight");
      f_weight_input->labelfont(1);
      f_weight_input->labelsize(11);
      f_weight_input->textfont(4);
      f_weight_input->textsize(11);
      f_weight_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_weight_input->when(FL_WHEN_NEVER);
    } 


	{ f_hide_check = new Fl_Check_Button(10, 130, 120, 20, "Hide Part:");
      f_hide_check->tooltip("Hide Part");
      f_hide_check->labelfont(1);
      f_hide_check->labelsize(11);
//      f_hide_check->textfont(4);
//      f_hide_check->textsize(11);
	  f_hide_check->callback((Fl_Callback*) UI_EditRobotPart::hidePart_ck);
      f_hide_check->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_hide_check->when(FL_WHEN_CHANGED);
    } 

    { Fl_Group* o = new Fl_Group(10, 170, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 170, 50, 20, "OK");
        f_panel_ok->tooltip("Create order.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 170, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the order.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 170, 205, 20);
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
void UI_EditRobotPart::hidePart_ck(Fl_Widget* widget, void* userData) 
{
//	UI_EditRobotPart* part = UI_EditRobotPart::create();
//	char hide = part->f_hide_check->value();
//	RobotPart* robotPart = (RobotPart*)part->f_hide_check->user_data();
//	string* strhide = new string((const char*)part->f_hide_check->value());

	Fl_Check_Button* hide_check = (Fl_Check_Button*)widget;
	RobotPart* robotPart = (RobotPart*)userData;

	if(robotPart != NULL)
	{
		if(hide_check->value() == 1)
		{
			robotPart->setHide(true);
		}
		else
		{
			robotPart->setHide(false);
		}
	}
}
void UI_EditRobotPart::robotPartno_cb(Fl_Widget* widget, void* userData) 
{
	RobotPart* robotPart = (RobotPart*)userData;
	string strType = robotPart->getType();
	int partNo = robotPart->getPartNo();
	string strPartno = int_to_string(partNo);
	double weight = robotPart->getWeight();
	string strWeight = double_to_string(weight);
	double cost = robotPart->getCost();
	string strCost = double_to_string(cost);
	bool hide = robotPart->getHide();

	UI_EditRobotPart* part = UI_EditRobotPart::create();
    part->f_type_input->static_value(strdup(strType.c_str()));
    part->f_partno_input->static_value(strdup(strPartno.c_str()));
    part->f_weight_input->static_value(strdup(strWeight.c_str()));
    part->f_cost_input->static_value(strdup(strCost.c_str()));
	part->f_hide_check->user_data((void*) robotPart);
	if(hide)
	{
		part->f_hide_check->set();
	}
	else
	{
		part->f_hide_check->value(0);
	}
}
void UI_EditRobotPart::robot_Part_cb(Fl_Widget* widget, void* userData) 
{
	UI_EditRobotPart* part = UI_EditRobotPart::create();
	RobotShop* shop = RobotShop::create();
	Inventory* inv = shop->GetInventory();
	list<RobotPart*> partlist = (list<RobotPart*>)NULL;
	if((int)userData == 0)
	{
		// Arm
		partlist = inv->getArmList();
	}
	else if((int)userData == 1)
	{
		// Battery
		partlist = inv->getBatteryList();
	}
	else if((int)userData == 2)
	{
		// Head
		partlist = inv->getHeadList();
	}
	else if((int)userData == 3)
	{
		// Locomotor
		partlist = inv->getLocomotorList();
	}
	else if((int)userData == 3)
	{
		// Torso
		partlist = inv->getTorsoList();
	}

	if(partlist != (list<RobotPart*>)NULL)
	{
		Fl_Menu_Item* menu_f_partno_choice = new Fl_Menu_Item[partlist.size()+1];
		int i = 0;
		for(std::list<RobotPart*>::const_iterator iterator = partlist.begin(), end = partlist.end(); iterator != end; ++iterator) 
		{			
			Fl_Menu_Item* item = menu_f_partno_choice+i;
			RobotPart* robotpart = *iterator;
			string name = robotpart->getDesc();
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = (Fl_Callback *)UI_EditRobotPart::robotPartno_cb;
			item->user_data_ =  (void*)robotpart;
			item->flags = 0;
			item->labeltype_ = FL_NORMAL_LABEL;
			item->labelfont_ = FL_HELVETICA;
			item->labelsize_ = 11;
			item->labelcolor_ = 0;
			i++;
		}
		Fl_Menu_Item* item = menu_f_partno_choice+i;
		item->text = 0;
		item->shortcut_ = 0;
		item->callback_ = 0;
		item->user_data_ =  0;
		item->flags = 0;
		item->labeltype_ = 0;
		item->labelfont_ = 0;
		item->labelsize_ = 0;
		item->labelcolor_ = 0;

		part->f_partno_choice->menu(menu_f_partno_choice);
		part->f_partno_choice->value(0);
		part->f_partno_choice->show();
	}
//    order->f_price_input->static_value(strdup(cstr));
//    order->f_shipping_input->static_value(strdup(cshipping));
}
