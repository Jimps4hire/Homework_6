#include "StdAfx.h"
#include <FL/Fl_Native_File_Chooser.H>
#include "UI_Order.h"

extern double string_to_double( const std::string& s );
extern string double_to_string( double num );
extern string int_to_string( int num );

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
//	f_c_button=(Fl_Light_Button *)0;
//	f_name_input=(Fl_Input *)0;
//	f_return_type_input=(Fl_Input *)0;
	f_price_input=(Fl_Input *)0;
	f_quantity_input=(Fl_Input *)0;
	f_shipping_input=(Fl_Input *)0;
	f_tax_input=(Fl_Input *)0;
	f_total_input=(Fl_Input *)0;
	f_subtotal_input=(Fl_Input *)0;
	f_panel_ok=(Fl_Return_Button *)0;
	f_panel_cancel=(Fl_Button *)0;
//	f_comment_input=(Fl_Text_Editor *)0;
}


UI_Order::~UI_Order(void)
{
}
UI_Order* UI_Order::create()
{
	return order;
}

void UI_Order::open() {
  if (!function_panel) create_panel();
  
    f_customer_choice->value(0);
    f_customer_choice->show();
    f_price_input->show();
    f_quantity_input->value(0);
    f_quantity_input->show();

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
		CreateOrder();
		break;
	  }
      else if (w == f_quantity_input)
	  {
		  Calculate();
	  }
      else if (w == f_robot_add)
	  {
		  AddRobot();
	  }
      else if (w == f_robot_save)
	  {
		  SaveOrder();
	  }
      else if (w == f_robot_open)
	  {
		  OpenOrder();
	  }
      else if (w == f_robot_delete)
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
Fl_Double_Window* UI_Order::create_panel() 
{
	items.clear();

  {
	RobotShop* robot = RobotShop::create();
	function_panel = new Fl_Double_Window(443, 482, "Sales Order");
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

    { f_shipping_input = new Fl_Input(10, 50, 120, 20, "Shipping:");
      f_shipping_input->tooltip("Shipping");
      f_shipping_input->labelfont(1);
      f_shipping_input->labelsize(11);
      f_shipping_input->textfont(4);
      f_shipping_input->textsize(11);
      f_shipping_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_shipping_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

	{ f_tax_input = new Fl_Input(145, 50, 120, 20, "Tax (8.0%):");
      f_tax_input->tooltip("Tax");
      f_tax_input->labelfont(1);
      f_tax_input->labelsize(11);
      f_tax_input->textfont(4);
      f_tax_input->textsize(11);
      f_tax_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_tax_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input


	{ f_subtotal_input = new Fl_Input(10, 90, 120, 20, "Subtotal:");
      f_subtotal_input->tooltip("Subtotal");
      f_subtotal_input->labelfont(1);
      f_subtotal_input->labelsize(11);
      f_subtotal_input->textfont(4);
      f_subtotal_input->textsize(11);
      f_subtotal_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_subtotal_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input

	{ f_total_input = new Fl_Input(145, 90, 120, 20, "Total:");
      f_total_input->tooltip("Total");
      f_total_input->labelfont(1);
      f_total_input->labelsize(11);
      f_total_input->textfont(4);
      f_total_input->textsize(11);
      f_total_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_total_input->when(FL_WHEN_NEVER);
    } // Fl_Input* f_return_type_input


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
			if(robot->getHide())
			{
				continue;
			}
			string name = robot->getName();
			if(price == 0)
			{
				price = robot->getPrice();
			}
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = (Fl_Callback *)UI_Order::robotModel_cb;
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

		f_robotModel_choice = new Fl_Choice(10, 130, 320, 20, "Robot Model:");
		f_robotModel_choice->tooltip("Robot Model");
		f_robotModel_choice->down_box(FL_BORDER_BOX);
		f_robotModel_choice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
		f_robotModel_choice->labelsize(11);
		f_robotModel_choice->textsize(11);
		f_robotModel_choice->when(FL_WHEN_CHANGED);
		f_robotModel_choice->menu(menu_f_robotModel_choice);
	}

    { f_price_input = new Fl_Input(10, 170, 120, 20, "Price:");
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

    { f_quantity_input = new Fl_Input(145, 170, 120, 20, "Quantity:");
      f_quantity_input->tooltip("Quantity");
      f_quantity_input->labelfont(1);
      f_quantity_input->labelsize(11);
      f_quantity_input->textfont(4);
      f_quantity_input->textsize(11);
      f_quantity_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_quantity_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
    } // Fl_Input* f_return_type_input

	{ f_robot_add = new Fl_Return_Button(10, 210, 50, 20, "Add");
	f_robot_add->tooltip("Add part.");
	f_robot_add->labelsize(11);
	f_robot_add->window()->hotspot(f_robot_add);
	} // Fl_Return_Button* f_panel_ok
	{ f_robot_delete = new Fl_Button(70, 210, 50, 20, "Delete");
	f_robot_delete->tooltip("Delete part.");
	f_robot_delete->labelsize(11);
	} // Fl_Button* f_panel_cancel
	{ f_robot_save = new Fl_Return_Button(130, 210, 80, 20, "Save Draft");
	f_robot_save->tooltip("Add part.");
	f_robot_save->labelsize(11);
	f_robot_save->window()->hotspot(f_robot_add);
	} // Fl_Return_Button* f_panel_ok
	{ f_robot_open = new Fl_Button(220, 210, 80, 20, "Open Draft");
	f_robot_open->tooltip("Delete part.");
	f_robot_open->labelsize(11);
	} // Fl_Button* f_panel_cancel

	// robots table
	// create table for parts
	f_table = new Control_Table(10, 250, 420, 160, /*UI_RobotModel::DrawPartCell,*/ "Parts");
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
	f_table->col_width(0, 160);
	f_table->col_width(1, 80);
	f_table->col_width(2, 80);
	f_table->col_width(3, 100);

	f_table->setHeader(0, "Name");
	f_table->setHeader(1, "Price");
	f_table->setHeader(2, "Quantity");
	f_table->setHeader(3, "Total Cost");

	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			f_table->setData(i, j, "");
		}
	}

	/*
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
	*/

    { Fl_Group* o = new Fl_Group(10, 430, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 430, 50, 20, "OK");
        f_panel_ok->tooltip("Create order.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 430, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the order.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 430, 205, 20);
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
	string* strshipping = new string(f_shipping_input->value());

	list<SalesOrder*> salesOrder = robot->getSalesOrder();
	SalesOrder* order = new SalesOrder(salesOrder.size()+1, *strsa, *strcust);

	if(items.size() > 0)
	{
		for(std::list<OrderItem*>::const_iterator iterator = items.begin(), end = items.end(); iterator != end; ++iterator) 
		{			
			OrderItem* item = *iterator;
			order->addItem(item->getName(), item->getQuantity(), item->getPrice());
		}
	}
	order->setShipping(string_to_double(*strshipping));
	robot->AddOrder(order);
}
void UI_Order::Calculate()
{
	RobotShop* robot = RobotShop::create();

	double price = 0;
	double shipping = 0;

	string* strshipping = new string(f_shipping_input->value());
	if(strcmp(strshipping->c_str(), "") != 0)
	{
		shipping = string_to_double(*strshipping);
	}

	if(items.size() > 0)
	{
		for(std::list<OrderItem*>::const_iterator iterator = items.begin(), end = items.end(); iterator != end; ++iterator) 
		{			
			OrderItem* item = *iterator;
			price += item->getTotalCost();
		}
	}
	double tax = price * 0.08;
	string strtax = to_string((long double)tax);
	const char *ctax = strtax.c_str();
	order->f_tax_input->static_value(strdup(ctax));

	double subtotal = price + shipping;
	string strsubtotal = to_string((long double)subtotal);
	const char *csubtotal = strsubtotal.c_str();
	order->f_subtotal_input->static_value(strdup(csubtotal));

	double total = subtotal + tax;
	string strtotal = to_string((long double)total);
	const char *ctotal = strtotal.c_str();
	order->f_total_input->static_value(strdup(ctotal));

	/*
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
	*/
}
void UI_Order::AddRobot()
{
	string* strrobotModel = new string(f_robotModel_choice->text());
	string* strprice = new string(f_price_input->value());
	string* strqty = new string(f_quantity_input->value());
	double price = string_to_double(*strprice);
	double qty = string_to_double(*strqty);

	OrderItem* item = new OrderItem(*strrobotModel, qty, price, qty * price);
	items.push_back(item);

	Calculate();
	updateRobotData();
}
void UI_Order::updateRobotData()
{
	// clear part data
	for(int i = 0; i < 10; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			f_table->setData(i, j, "");
		}
	}

	if(items.size() > 0)
	{
		int row = 0;
		for(std::list<OrderItem*>::const_iterator iterator = items.begin(), end = items.end(); iterator != end; ++iterator) 
		{			
			OrderItem* item = *iterator;
			f_table->setData(row, 0, item->getName());
			f_table->setData(row, 1, double_to_string(item->getPrice()));
			f_table->setData(row, 2, int_to_string(item->getQuantity()));
			f_table->setData(row, 3, double_to_string(item->getTotalCost()));
			row++;
		}
	}

	// force to redraw
	f_table->cols(4);
}
void UI_Order::SaveOrder()
{
	Fl_Native_File_Chooser fnfc;
	const char *c = "Order.xml";
	fnfc.title("Save To:");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_SAVE_FILE);
	fnfc.filter("Robot Shop Files\t*.xml\n");
	if (fnfc.show() != 0) return;
	c = fnfc.filename();
	RobotShop* shop = new RobotShop();

	Calculate();

	string* strcust = new string(f_customer_choice->text());
	string* strsa = new string(f_salesagent_choice->text());
	string* strshipping = new string(f_shipping_input->value());

	SalesOrder* sorder = new SalesOrder(1, *strsa, *strcust);

	if(items.size() > 0)
	{
		for(std::list<OrderItem*>::const_iterator iterator = items.begin(), end = items.end(); iterator != end; ++iterator) 
		{			
			OrderItem* item = *iterator;
			sorder->addItem(item->getName(), item->getQuantity(), item->getPrice());
		}
	}
	sorder->setShipping(string_to_double(*strshipping));
	shop->AddOrder(sorder);

	shop->serialize(c);
}
void UI_Order::OpenOrder()
{
	const char *c;
	Fl_Native_File_Chooser fnfc;
	fnfc.title("Open:");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	fnfc.filter("Robot Shop Files\t*.xml\n");
	if (fnfc.show() != 0) return;
	c = fnfc.filename();

	// load the file
	RobotShop* shop = new RobotShop();
	shop->deserialize(c);

	SalesOrder* order = NULL;
	list<SalesOrder*> salesOrder = shop->getSalesOrder();
	for(std::list<SalesOrder*>::const_iterator iterator = salesOrder.begin(), end = salesOrder.end(); iterator != end; ++iterator) 
	{			
		order = *iterator;
	}
	/*
	string cust = order->getCustomer();
	f_customer_choice->static_value(strdup(cust.c_str()));
	string sa = order->getSalesAssociate();
	f_salesagent_choice->static_value(strdup(sa.c_str()));
	*/

	double price = order->getTotalPrice();
	string strprice = double_to_string(price);
	f_total_input->static_value(strdup(strprice.c_str()));

	double subtotal = order->getSubtotal();
	string strsubtotal = double_to_string(subtotal);
	f_subtotal_input->static_value(strdup(strsubtotal.c_str()));

	double shipping = order->getShipping();
	string strshipping = double_to_string(shipping);
	f_shipping_input->static_value(strdup(strshipping.c_str()));

	double tax = order->getTax();
	string strtax = double_to_string(tax);
	f_tax_input->static_value(strdup(strtax.c_str()));

	list<OrderItem*> sitems = order->getItems();
	if(sitems.size() > 0)
	{
		for(std::list<OrderItem*>::const_iterator iterator = sitems.begin(), end = sitems.end(); iterator != end; ++iterator) 
		{			
			OrderItem* sitem = *iterator;
			OrderItem* item = new OrderItem(sitem->getName(), sitem->getQuantity(), sitem->getPrice(), sitem->getTotalCost());
			items.push_back(item);
		}
	}

}
