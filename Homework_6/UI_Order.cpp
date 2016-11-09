#include "StdAfx.h"
#include "UI_Order.h"
#include "FL/Fl_Box.h"
#include "RobotShop.h"
#include <string>
#include <sstream>
using namespace std;
using namespace System;

extern double string_to_double( const std::string& s );

Fl_Menu_Item menu_f_customer_choice[] = {
 {"local", 0,  0, (void*)(0), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {"global", 0,  0, (void*)(1), 0, FL_NORMAL_LABEL, 0, 11, 0},
 {0,0,0,0,0,0,0,0,0}
};

UI_Order* UI_Order::order = new UI_Order();

UI_Order::UI_Order(void)
{
	f_salesagent_choice=(Fl_Choice *)0;
	f_customer_choice=(Fl_Choice *)0;
	f_robotModel_choice=(Fl_Choice *)0;
	f_c_button=(Fl_Light_Button *)0;
	f_name_input=(Fl_Input *)0;
	f_return_type_input=(Fl_Input *)0;
	f_price_input=(Fl_Input *)0;
	f_quantity_input=(Fl_Input *)0;
	f_shipping_input=(Fl_Input *)0;
	f_tax_input=(Fl_Input *)0;
	f_total_input=(Fl_Input *)0;
	f_subtotal_input=(Fl_Input *)0;
	f_panel_ok=(Fl_Return_Button *)0;
	f_panel_cancel=(Fl_Button *)0;
	f_comment_input=(Fl_Text_Editor *)0;
}


UI_Order::~UI_Order(void)
{
}
UI_Order* UI_Order::create()
{
	return order;
}

Fl_Double_Window* UI_Order::create_panel1() {
  { function_panel = new Fl_Double_Window(343, 232, "Function/Method Properties");
    { 
		Fl_Group* o = new Fl_Group(10, 10, 270, 20);
	/*
      { f_salesagent_choice = new Fl_Choice(10, 10, 75, 20);
        f_salesagent_choice->tooltip("Change member access attribute.");
        f_salesagent_choice->down_box(FL_BORDER_BOX);
        f_salesagent_choice->labelsize(11);
        f_salesagent_choice->textsize(11);
        f_salesagent_choice->when(FL_WHEN_CHANGED);

//        f_salesagent_choice->menu(menu_f_salesagent_choice);
      }  // Fl_Choice* f_salesagent_choice
	  */
      { f_customer_choice = new Fl_Choice(10, 10, 75, 20);
        f_customer_choice->tooltip("Change widget accessibility.");
        f_customer_choice->down_box(FL_BORDER_BOX);
        f_customer_choice->labelsize(11);
        f_customer_choice->textsize(11);
        f_customer_choice->when(FL_WHEN_CHANGED);
        f_customer_choice->menu(menu_f_customer_choice);
      }  // Fl_Choice* f_customer_choice
      { f_c_button = new Fl_Light_Button(95, 10, 120, 20, "C declaration");
        f_c_button->tooltip("Declare with a C interface instead of C++.");
        f_c_button->labelsize(11);
      } // Fl_Light_Button* f_c_button
      { Fl_Box* o = new Fl_Box(235, 10, 45, 20);
        Fl_Group::current()->resizable(o);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    { f_name_input = new Fl_Input(10, 50, 320, 20, "Name(args): (blank for main())");
      f_name_input->tooltip("The name of the function or method.");
      f_name_input->labelfont(1);
      f_name_input->labelsize(11);
      f_name_input->textfont(4);
      f_name_input->textsize(11);
      f_name_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_name_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_name_input
    { f_return_type_input = new Fl_Input(10, 90, 320, 20, "Return Type: (blank to return outermost widget)");
      f_return_type_input->tooltip("The return type of the function or method.");
      f_return_type_input->labelfont(1);
      f_return_type_input->labelsize(11);
      f_return_type_input->textfont(4);
      f_return_type_input->textsize(11);
      f_return_type_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_return_type_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input
    { Fl_Group* o = new Fl_Group(10, 200, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 200, 50, 20, "OK");
        f_panel_ok->tooltip("Apply the changes.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 200, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the changes.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 200, 205, 20);
        Fl_Group::current()->resizable(o);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    { f_comment_input = new Fl_Text_Editor(10, 125, 320, 65, "Comment:");
      f_comment_input->tooltip("Function comment in Doxygen format");
      f_comment_input->box(FL_DOWN_BOX);
      f_comment_input->labelfont(1);
      f_comment_input->labelsize(11);
      f_comment_input->textfont(4);
      f_comment_input->textsize(11);
      f_comment_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      Fl_Group::current()->resizable(f_comment_input);
      f_comment_input->buffer(new Fl_Text_Buffer());
    } // Fl_Text_Editor* f_comment_input
    function_panel->set_modal();
    function_panel->end();
  } // Fl_Double_Window* function_panel
  return function_panel;
}

void UI_Order::open() {
  if (!function_panel) create_panel();
//  f_return_type_input->static_value("Order");
//  f_name_input->static_value("New");
  
    f_customer_choice->value(0);
    f_customer_choice->show();
//    f_salesagent_choice->hide();
//    f_price_input->value(0);
    f_price_input->show();
    f_quantity_input->value(0);
    f_quantity_input->show();

	/*
  f_c_button->value(cdecl_);
  const char *c = comment();
  f_comment_input->buffer()->text(c?c:"");
  */
  function_panel->show();
//  const char* message = 0;
  for (;;) { // repeat as long as there are errors
//    if (message) fl_alert("%s", message);
    for (;;) {
      Fl_Widget* w = Fl::readqueue();
      if (w == f_panel_cancel)
	  {
		goto BREAK2;
	  }
      else if (w == f_panel_ok)
	  {
		CreateOrder();
		break;
	  }
      else if (w == f_quantity_input)
	  {
		  Calculate();
	  }
      else if (/*w == NULL ||*/ !w)
	  {
		Fl::wait();
	  }
    }

	/*
    const char*c = f_name_input->value();
//    while (isspace(*c)) c++;
//    message = c_check(c); if (message) continue;
    const char *d = c;
    for (; *d != '('; d++) if (isspace(*d) || !*d) break;
    if (*c && *d != '(') {
      message = "must be name(arguments), try again:"; continue;
    }
    int mod = 0;
    c = f_return_type_input->value();
	*/
	/*
    message = c_check(c); if (message) continue;
    name(f_name_input->value());
    storestring(c, return_type);
    if (is_in_class()) {
      if (public_ != f_salesagent_choice->value()) {
        mod = 1;
        public_ = f_salesagent_choice->value();
        redraw_browser();
      }
    } else {
      if (public_ != f_customer_choice->value()) {
        mod = 1;
        public_ = f_customer_choice->value();
        redraw_browser();
      }
    }
    if (cdecl_ != f_c_button->value()) {
      mod = 1;
      cdecl_ = f_c_button->value();
    }
    c = f_comment_input->buffer()->text();
    if (c && *c) {
      if (!comment() || strcmp(c, comment())) redraw_browser();
      comment(c);
    } else {
      if (comment()) redraw_browser();
      comment(0);
    }
    if (c) free((void*)c);
    if (mod) set_modflag(1);
	*/
    break;
  }
BREAK2:
  function_panel->hide();
}
Fl_Double_Window* UI_Order::create_panel() {
  {
	RobotShop* robot = RobotShop::create();
	function_panel = new Fl_Double_Window(343, 302, "Sales Order");
    { 
		Fl_Group* o = new Fl_Group(10, 10, 270, 20);

	// customers
	list<Customer*> customers = robot->GetCustomer();
//	if(f_customer_choice == (Fl_Choice *)0)
	{
		Fl_Menu_Item* menu_f_customer_choice = new Fl_Menu_Item[customers.size()+1];
		int i = 0;
		for(std::list<Customer*>::const_iterator iterator = customers.begin(), end = customers.end(); iterator != end; ++iterator) 
		{			
			Fl_Menu_Item* item = menu_f_customer_choice+i;
			Customer* cust = *iterator;
			string name = cust->getName();
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = 0;
			item->user_data_ =  0;
			item->flags = 0;
			item->labeltype_ = FL_NORMAL_LABEL;
			item->labelfont_ = FL_HELVETICA;
			item->labelsize_ = 11;
			item->labelcolor_ = 0;
			i++;
		}
		Fl_Menu_Item* item = menu_f_customer_choice+i;
		item->text = 0;
		item->shortcut_ = 0;
		item->callback_ = 0;
		item->user_data_ =  0;
		item->flags = 0;
		item->labeltype_ = 0;
		item->labelfont_ = 0;
		item->labelsize_ = 0;
		item->labelcolor_ = 0;

		f_customer_choice = new Fl_Choice(10, 10, 120, 20, "Customers");
		f_customer_choice->tooltip("Customer.");
		f_customer_choice->down_box(FL_BORDER_BOX);
		f_customer_choice->labelsize(11);
		f_customer_choice->textsize(11);
//		f_customer_choice->when(FL_WHEN_CHANGED);
		f_customer_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		f_customer_choice->menu(menu_f_customer_choice);
	}

	// sales agent
	list<SalesAssoc*> salesAssocs = robot->GetSalesAssocs();
//	if(f_salesagent_choice == (Fl_Choice *)0)
	{
		Fl_Menu_Item* menus_f_salesagent_choice = new Fl_Menu_Item[salesAssocs.size()+1];
		int i = 0;
		for(std::list<SalesAssoc*>::const_iterator iterator = salesAssocs.begin(), end = salesAssocs.end(); iterator != end; ++iterator) 
		{			
			Fl_Menu_Item* item = menus_f_salesagent_choice+i;
			SalesAssoc* cust = *iterator;
			string name = cust->getName();
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = 0;
			item->user_data_ =  0;
			item->flags = 0;
			item->labeltype_ = FL_NORMAL_LABEL;
			item->labelfont_ = FL_HELVETICA;
			item->labelsize_ = 11;
			item->labelcolor_ = 0;
			i++;
		}
		Fl_Menu_Item* item = menus_f_salesagent_choice+i;
		item->text = 0;
		item->shortcut_ = 0;
		item->callback_ = 0;
		item->user_data_ =  0;
		item->flags = 0;
		item->labeltype_ = 0;
		item->labelfont_ = 0;
		item->labelsize_ = 0;
		item->labelcolor_ = 0;

		f_salesagent_choice = new Fl_Choice(145, 10, 125, 20, "Sales Agent");
		f_salesagent_choice->tooltip("Sales Agent.");
		f_salesagent_choice->down_box(FL_BORDER_BOX);
		f_salesagent_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		f_salesagent_choice->labelsize(11);
		f_salesagent_choice->textsize(11);
//		f_salesagent_choice->when(FL_WHEN_CHANGED);
		f_salesagent_choice->menu(menus_f_salesagent_choice);
	}

	/*
      { f_c_button = new Fl_Light_Button(95, 10, 120, 20, "C declaration");
        f_c_button->tooltip("Declare with a C interface instead of C++.");
        f_c_button->labelsize(11);
      } // Fl_Light_Button* f_c_button
	  */

      { Fl_Box* box = new Fl_Box(235, 10, 45, 20);
        Fl_Group::current()->resizable(box);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o


	/*
    { f_name_input = new Fl_Input(10, 50, 320, 20, "Name(args): (blank for main())");
      f_name_input->tooltip("The name of the function or method.");
      f_name_input->labelfont(1);
      f_name_input->labelsize(11);
      f_name_input->textfont(4);
      f_name_input->textsize(11);
      f_name_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_name_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_name_input
	*/

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
			RobotModel* cust = *iterator;
			string name = cust->getName();
			if(price == 0)
			{
				price = cust->getPrice();
			}
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = (Fl_Callback *)UI_Order::robotModel_cb;
			item->user_data_ =  (void*)cust;
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

		f_robotModel_choice = new Fl_Choice(10, 50, 320, 20, "Robot Model:");
		f_robotModel_choice->tooltip("Robot Model");
		f_robotModel_choice->down_box(FL_BORDER_BOX);
		f_robotModel_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		f_robotModel_choice->labelsize(11);
		f_robotModel_choice->textsize(11);
		f_salesagent_choice->when(FL_WHEN_CHANGED);
		f_robotModel_choice->menu(menu_f_robotModel_choice);
	}


    { f_price_input = new Fl_Input(10, 90, 120, 20, "Price:");
      f_price_input->tooltip("Price");
      f_price_input->labelfont(1);
      f_price_input->labelsize(11);
      f_price_input->textfont(4);
      f_price_input->textsize(11);
      f_price_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_price_input->when(FL_WHEN_NEVER);

	  string strPr = to_string((long double)price);
	  const char *cstr = strPr.c_str();
	  f_price_input->static_value(strdup(cstr));
    } // Fl_Input* f_return_type_input

    { f_quantity_input = new Fl_Input(145, 90, 120, 20, "Quantity:");
      f_quantity_input->tooltip("Quantity");
      f_quantity_input->labelfont(1);
      f_quantity_input->labelsize(11);
      f_quantity_input->textfont(4);
      f_quantity_input->textsize(11);
      f_quantity_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_quantity_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

    { f_shipping_input = new Fl_Input(10, 130, 120, 20, "Shipping:");
      f_shipping_input->tooltip("Shipping");
      f_shipping_input->labelfont(1);
      f_shipping_input->labelsize(11);
      f_shipping_input->textfont(4);
      f_shipping_input->textsize(11);
      f_shipping_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_shipping_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

	{ f_tax_input = new Fl_Input(145, 130, 120, 20, "Tax (8.0%):");
      f_tax_input->tooltip("Tax");
      f_tax_input->labelfont(1);
      f_tax_input->labelsize(11);
      f_tax_input->textfont(4);
      f_tax_input->textsize(11);
      f_tax_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_tax_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input


	{ f_subtotal_input = new Fl_Input(10, 170, 120, 20, "Subtotal:");
      f_subtotal_input->tooltip("Subtotal");
      f_subtotal_input->labelfont(1);
      f_subtotal_input->labelsize(11);
      f_subtotal_input->textfont(4);
      f_subtotal_input->textsize(11);
      f_subtotal_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_subtotal_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

	{ f_total_input = new Fl_Input(145, 170, 120, 20, "Total:");
      f_total_input->tooltip("Total");
      f_total_input->labelfont(1);
      f_total_input->labelsize(11);
      f_total_input->textfont(4);
      f_total_input->textsize(11);
      f_total_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_total_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

	{
//	  f_comment_input = new Fl_Text_Editor(10, 125, 320, 65, "Comment:");
	  f_comment_input = new Fl_Text_Editor(10, 205, 320, 65, "Comment:");
      f_comment_input->tooltip("order comment");
      f_comment_input->box(FL_DOWN_BOX);
      f_comment_input->labelfont(1);
      f_comment_input->labelsize(11);
      f_comment_input->textfont(4);
      f_comment_input->textsize(11);
      f_comment_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      Fl_Group::current()->resizable(f_comment_input);
      f_comment_input->buffer(new Fl_Text_Buffer());
    } // Fl_Text_Editor* f_comment_input

    { Fl_Group* o = new Fl_Group(10, 280, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 280, 50, 20, "OK");
        f_panel_ok->tooltip("Create order.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 280, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the order.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 280, 205, 20);
        Fl_Group::current()->resizable(o);
      } // Fl_Box* o
      o->end();
    } // Fl_Group* o
    function_panel->set_modal();
    function_panel->end();
  } // Fl_Double_Window* function_panel
  return function_panel;
}
void UI_Order::robotModel_cb(Fl_Widget* widget, void* userData) 
{
	RobotModel* robot = (RobotModel*)userData;
	double price = robot->getPrice();
	string strPr = to_string((long double)price);
	const char *cstr = strPr.c_str();

	double shipping = robot->getShipping();
	string strShipping = to_string((long double)shipping);
	const char *cshipping = strShipping.c_str();

	UI_Order* order = UI_Order::create();
    order->f_price_input->static_value(strdup(cstr));
    order->f_shipping_input->static_value(strdup(cshipping));
}
void UI_Order::CreateOrder()
{
	RobotShop* robot = RobotShop::create();

	Calculate();

	string* strcust = new string(f_customer_choice->text());
	string* strsa = new string(f_salesagent_choice->text());
	string* strrobotModel = new string(f_robotModel_choice->text());
	string* strprice = new string(f_price_input->value());
	string* strqty = new string(f_quantity_input->value());
	string* strshipping = new string(f_shipping_input->value());

	list<SalesOrder*> salesOrder = robot->getSalesOrder();
	SalesOrder* order = new SalesOrder(salesOrder.size()+1, *strsa, *strcust);

	double price = string_to_double(*strprice);
	double qty = string_to_double(*strqty);
	double shipping = string_to_double(*strshipping);
	order->addItem(*strrobotModel, qty, price, shipping);
}
void UI_Order::Calculate()
{
	RobotShop* robot = RobotShop::create();

	string* strprice = new string(f_price_input->value());
	string* strqty = new string(f_quantity_input->value());
	if(strcmp(strqty->c_str(), "") != 0)
	{
//		double price = Convert::ToSingle(strprice);
		double price = string_to_double(*strprice);
		double qty = string_to_double(*strqty);
		double shipping = 0;

		string* strshipping = new string(f_shipping_input->value());
		if(strcmp(strshipping->c_str(), "") != 0)
		{
			shipping = string_to_double(*strshipping);
		}

		double tax = price * qty * 0.08;
		string strtax = to_string((long double)tax);
		const char *ctax = strtax.c_str();
		order->f_tax_input->static_value(strdup(ctax));

		double subtotal = price * qty + shipping;
		string strsubtotal = to_string((long double)subtotal);
		const char *csubtotal = strsubtotal.c_str();
		order->f_subtotal_input->static_value(strdup(csubtotal));

		double total = subtotal + tax;
		string strtotal = to_string((long double)total);
		const char *ctotal = strtotal.c_str();
		order->f_total_input->static_value(strdup(ctotal));
	}
}
