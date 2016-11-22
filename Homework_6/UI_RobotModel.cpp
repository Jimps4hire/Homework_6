#include "StdAfx.h"
#include "UI_RobotModel.h"
#include "FL/Fl_Box.h"
#include "RobotShop.h"
#include <string>
#include <sstream>
using namespace std;
using namespace System;

extern double string_to_double( const std::string& s );
extern string int_to_string( int num );

Fl_Menu_Item menu_f_partname_choice[] = {
 {"Arm", 0,  (Fl_Callback *)UI_RobotModel::robotModel_Part_cb, (void*)(0), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Battery", 0, (Fl_Callback *)UI_RobotModel::robotModel_Part_cb,  (void*)(1), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Head", 0,  (Fl_Callback *)UI_RobotModel::robotModel_Part_cb, (void*)(2), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Locomotor", 0,  (Fl_Callback *)UI_RobotModel::robotModel_Part_cb, (void*)(3), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"Torso", 0,  (Fl_Callback *)UI_RobotModel::robotModel_Part_cb, (void*)(4), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

UI_RobotModel::UI_RobotModel(void)
{
	arm = NULL;
	locomotor = NULL;
	head = NULL;
	battery = NULL;
	torso = NULL;
}
UI_RobotModel* UI_RobotModel::create()
{
	return part;
}

UI_RobotModel* UI_RobotModel::part = new UI_RobotModel();

UI_RobotModel::~UI_RobotModel(void)
{
}

Fl_Double_Window* UI_RobotModel::create_panel() {
  {
	arm = NULL;
	locomotor = NULL;
	head = NULL;
	battery = NULL;
	torso = NULL;

	function_panel = new Fl_Double_Window(443, 542, "Robot Model");
    { 
//		Fl_Group* o = new Fl_Group(10, 10, 270, 20);

//	if(f_part_choice == (Fl_Choice *)0)
		{ f_name_input = new Fl_Input(10, 10, 120, 20, "Name:");
		  f_name_input->tooltip("Name");
		  f_name_input->labelfont(1);
		  f_name_input->labelsize(11);
		  f_name_input->textfont(4);
		  f_name_input->textsize(11);
		  f_name_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		  f_name_input->when(FL_WHEN_NEVER);
		} // Fl_Input* f_return_type_input
		/*
      { Fl_Box* box = new Fl_Box(435, 10, 45, 20);
        Fl_Group::current()->resizable(box);
      } // Fl_Box* o
	  */
//      o->end();
//    } // Fl_Group* o

    { f_desc_input = new Fl_Input(10, 50, 250, 20, "Description:");
      f_desc_input->tooltip("Description");
      f_desc_input->labelfont(1);
      f_desc_input->labelsize(11);
      f_desc_input->textfont(4);
      f_desc_input->textsize(11);
      f_desc_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_desc_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

    { f_type_input = new Fl_Input(145, 90, 120, 20, "Model Type:");
      f_type_input->tooltip("Model Type");
      f_type_input->labelfont(1);
      f_type_input->labelsize(11);
      f_type_input->textfont(4);
      f_type_input->textsize(11);
      f_type_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_type_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

    { f_modelno_input = new Fl_Input(10, 90, 120, 20, "Model No:");
      f_modelno_input->tooltip("Model No");
      f_modelno_input->labelfont(1);
      f_modelno_input->labelsize(11);
      f_modelno_input->textfont(4);
      f_modelno_input->textsize(11);
      f_modelno_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_modelno_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

	{ f_price_input = new Fl_Input(145, 130, 120, 20, "Price:");
      f_price_input->tooltip("Price");
      f_price_input->labelfont(1);
      f_price_input->labelsize(11);
      f_price_input->textfont(4);
      f_price_input->textsize(11);
      f_price_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_price_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input


	{ f_shipping_input = new Fl_Input(10, 130, 120, 20, "Shipping:");
      f_shipping_input->tooltip("Shipping");
      f_shipping_input->labelfont(1);
      f_shipping_input->labelsize(11);
      f_shipping_input->textfont(4);
      f_shipping_input->textsize(11);
      f_shipping_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_shipping_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

//      o->end();
    } // Fl_Group* o

	{
//		Fl_Group* o = new Fl_Group(10, 170, 270, 20);
		{
			{
			f_part_choice = new Fl_Choice(10, 170, 120, 20, "Parts");
			f_part_choice->tooltip("Part");
			f_part_choice->down_box(FL_BORDER_BOX);
			f_part_choice->labelsize(11);
			f_part_choice->textsize(11);
			f_part_choice->when(FL_WHEN_CHANGED);
			f_part_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
			f_part_choice->menu(menu_f_partname_choice);
			}

			{
			f_partno_choice = new Fl_Choice(145, 170, 180, 20, "Part No");
			f_partno_choice->tooltip("Description");
			f_partno_choice->down_box(FL_BORDER_BOX);
			f_partno_choice->labelsize(11);
			f_partno_choice->textsize(11);
			f_part_choice->when(FL_WHEN_CHANGED);
			f_partno_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
//			f_partno_choice->menu(menu_f_partname_choice);
			}

			{ f_quantity_input = new Fl_Input(10, 210, 120, 20, "Quantity:");
				f_quantity_input->tooltip("Quantity");
				f_quantity_input->labelfont(1);
				f_quantity_input->labelsize(11);
				f_quantity_input->textfont(4);
				f_quantity_input->textsize(11);
				f_quantity_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
				f_quantity_input->when(FL_WHEN_NEVER);
			} // Fl_Input* f_return_type_input

			{ f_part_add = new Fl_Return_Button(10, 250, 50, 20, "Add");
			f_part_add->tooltip("Add part.");
			f_part_add->labelsize(11);
			f_part_add->window()->hotspot(f_part_add);
			} // Fl_Return_Button* f_panel_ok
			{ f_part_delete = new Fl_Button(80, 290, 50, 20, "Delete");
			f_part_delete->tooltip("Delete part.");
			f_part_delete->labelsize(11);
			} // Fl_Button* f_panel_cancel
					/*
			  { Fl_Box* o = new Fl_Box(10, 210, 205, 20);
				Fl_Group::current()->resizable(o);
			  } // Fl_Box* o
			  */
			// create table for parts
			f_table = new Control_Table(10, 290, 420, 180, /*UI_RobotModel::DrawPartCell,*/ "Parts");
			f_table->selection_color(FL_YELLOW);
			f_table->when(FL_WHEN_RELEASE|FL_WHEN_CHANGED);
			f_table->table_box(FL_NO_BOX);
			f_table->col_resize_min(4);
			f_table->row_resize_min(4);

			// ROWS
//			f_table->row_header(1);
//			f_table->row_header_width(60);
			f_table->row_resize(1);
			f_table->rows(5);
			f_table->row_height_all(20);

			// COLS
			f_table->cols(4);
			f_table->col_header(1);
			f_table->col_header_height(25);
			f_table->col_resize(1);
//			f_table->col_width_all(80);
			f_table->col_width(0, 80);
			f_table->col_width(1, 160);
			f_table->col_width(2, 80);
			f_table->col_width(3, 80);

			f_table->setHeader(0, "Name");
			f_table->setHeader(1, "Description");
			f_table->setHeader(2, "Type");
			f_table->setHeader(3, "Part No");

			for(int i = 0; i < 10; i++)
			{
				for(int j = 0; j < 5; j++)
				{
					f_table->setData(i, j, "");
				}
			}

		}
//		o->end();
	}

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

	    { Fl_Group* o = new Fl_Group(10, 500, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 500, 50, 20, "OK");
        f_panel_ok->tooltip("Create order.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 500, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the order.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 500, 205, 20);
        Fl_Group::current()->resizable(o);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    function_panel->set_modal();
    function_panel->end();
  } // Fl_Double_Window* function_panel
  return function_panel;
}

void UI_RobotModel::open() {
  if (!function_panel) create_panel();
  
    f_part_choice->value(0);
    f_part_choice->show();
	robotModel_Part_cb(f_part_choice, 0) ;

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
		CreateModel();
		break;
	  }
      else if (w == f_part_add)
	  {
		  AddPart();
	  }
      else if (w == f_part_delete)
	  {
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
void UI_RobotModel::AddPart()
{
	string* strqty = new string(f_quantity_input->value());
	int qty = atoi( strqty->c_str());

//	UI_RobotModel* model = UI_RobotModel::create();
//	string* strpart = new string(f_partno_choice->text());
	const Fl_Menu_Item* item = f_partno_choice->find_item(f_partno_choice->text());
	void* data = item->user_data_;
	RobotPart* part = (RobotPart*)data;
	part->setQuantity(qty);

	string strpart = part->getName();
	if(strpart == "Arm")
	{
		arm = part;
	}
	else if(strpart == "Battery")
	{
		battery = part;
	}
	else if(strpart == "Head")
	{
		head = part;
	}
	else if(strpart == "Locomotor")
	{
		locomotor = part;
	}
	else if(strpart == "Torso")
	{
		torso = part;
	}
	updatePartData();
}
void UI_RobotModel::updatePartData()
{
	// clear part data
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			f_table->setData(i, j, "");
		}
	}

	int row = 0;
	if(arm != NULL)
	{
		f_table->setData(row, 0, arm->getName());
		f_table->setData(row, 1, arm->getDesc());
		f_table->setData(row, 2, arm->getType());
		f_table->setData(row, 3, int_to_string(arm->getPartNo()));
		row++;
	}
	if(head != NULL)
	{
		f_table->setData(row, 0, head->getName());
		f_table->setData(row, 1, head->getDesc());
		f_table->setData(row, 2, head->getType());
		f_table->setData(row, 3, int_to_string(head->getPartNo()));
		row++;
	}
	if(locomotor != NULL)
	{
		f_table->setData(row, 0, locomotor->getName());
		f_table->setData(row, 1, locomotor->getDesc());
		f_table->setData(row, 2, locomotor->getType());
		f_table->setData(row, 3, int_to_string(locomotor->getPartNo()));
		row++;
	}
	if(battery != NULL)
	{
		f_table->setData(row, 0, battery->getName());
		f_table->setData(row, 1, battery->getDesc());
		f_table->setData(row, 2, battery->getType());
		f_table->setData(row, 3, int_to_string(battery->getPartNo()));
		row++;
	}
	if(torso != NULL)
	{
		f_table->setData(row, 0, torso->getName());
		f_table->setData(row, 1, torso->getDesc());
		f_table->setData(row, 2, torso->getType());
		f_table->setData(row, 3, int_to_string(torso->getPartNo()));
		row++;
	}
	// force to redraw
	f_table->cols(4);
}
void UI_RobotModel::CreateModel()
{
	RobotShop* shop = RobotShop::create();
	Inventory* inv = shop->GetInventory();
	Product* product = shop->getProduct();

	string* strname = new string(f_name_input->value());
	string* strtype = new string(f_type_input->value());
	string* strdesc = new string(f_desc_input->value());
	string* strmodelno = new string(f_modelno_input->value());
	string* strpricet = new string(f_price_input->value());
	string* strshipping = new string(f_shipping_input->value());

//	string* strpart = new string(f_part_choice->text());

	int modelno = atoi( strmodelno->c_str());
	double price = string_to_double(*strpricet);
	double shipping = string_to_double(*strshipping);

	RobotModel* robot1 = new RobotModel(*strname, *strdesc, *strtype, modelno, price, shipping );

	// parts
	if(arm != NULL)
	{
		robot1->addPart(arm, arm->getQuantity());
	}
	if(head != NULL)
	{
		robot1->addPart(head, head->getQuantity());
	}
	if(locomotor != NULL)
	{
		robot1->addPart(locomotor, locomotor->getQuantity());
	}
	if(torso != NULL)
	{
		robot1->addPart(torso, torso->getQuantity());
	}
	if(battery != NULL)
	{
		robot1->addPart(battery, battery->getQuantity());
	}

	product->AddtoProduct(robot1);
}
void UI_RobotModel::robotModel_Partno_cb(Fl_Widget* widget, void* userData) 
{
}
void UI_RobotModel::robotModel_Part_cb(Fl_Widget* widget, void* userData) 
{
	/*
	RobotModel* robot = (RobotModel*)userData;
	double price = robot->getPrice();
	string strPr = to_string((long double)price);
	const char *cstr = strPr.c_str();

	double shipping = robot->getShipping();
	string strShipping = to_string((long double)shipping);
	const char *cshipping = strShipping.c_str();
	*/

	UI_RobotModel* model = UI_RobotModel::create();
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
			RobotPart* part = *iterator;
			if(part->getHide())
			{
				continue;
			}
			string name = part->getDesc();
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = (Fl_Callback *)UI_RobotModel::robotModel_Partno_cb;
			item->user_data_ =  (void*)part;
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

		model->f_partno_choice->menu(menu_f_partno_choice);
		model->f_partno_choice->value(0);
		model->f_partno_choice->show();
	}
//    order->f_price_input->static_value(strdup(cstr));
//    order->f_shipping_input->static_value(strdup(cshipping));
}


