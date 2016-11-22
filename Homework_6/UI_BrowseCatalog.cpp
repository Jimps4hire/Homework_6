#include "StdAfx.h"
#include "UI_BrowseCatalog.h"

extern string int_to_string( int num );

UI_BrowseCatalog* UI_BrowseCatalog::catalog = new UI_BrowseCatalog();

UI_BrowseCatalog::UI_BrowseCatalog(void)
{
}


UI_BrowseCatalog::~UI_BrowseCatalog(void)
{
}
UI_BrowseCatalog* UI_BrowseCatalog::create()
{
	return catalog;
}
void UI_BrowseCatalog::open() {
  if (!function_panel) create_panel();
  
  f_picturebox->show();
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

Fl_Double_Window* UI_BrowseCatalog::create_panel() 
{

  {
	RobotShop* robot = RobotShop::create();
	function_panel = new Fl_Double_Window(443, 402, "Catalog");
    { 
	// robot model
	double price = 0;
	string strType;
	int modelno;
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
				strType = robot->getType();
				modelno = robot->getModelNo();
			}
			const char *cstr = name.c_str();
			item->text = cstr ? strdup(cstr) : 0;
			item->shortcut_ = 0;
			item->callback_ = (Fl_Callback *)UI_BrowseCatalog::robotModel_cb;
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

    { f_type_input = new Fl_Input(10, 50, 120, 20, "Type:");
      f_type_input->tooltip("Type");
      f_type_input->labelfont(1);
      f_type_input->labelsize(11);
      f_type_input->textfont(4);
      f_type_input->textsize(11);
      f_type_input->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      f_type_input->when(FL_WHEN_ENTER_KEY_ALWAYS);
	  const char *cstrType = strType.c_str();
	  f_type_input->static_value(strdup(cstrType));
    } // Fl_Input* f_return_type_input


    { f_price_input = new Fl_Input(145, 50, 120, 20, "Price:");
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

	{
	string strModelno = int_to_string(modelno);
	string strFile = strModelno + ".jpg";
	const char *cstrFile = strFile.c_str();
	f_image = new Fl_JPEG_Image(cstrFile); // Reads the file you have put in the same place as the code.
//	double w = f_image->w();
//	double h = f_image->h();
//	double d = f_image->d();
    f_picturebox = new Fl_Box(20, 80, 200, 200); // Make it the right size, empty for now.
    f_picturebox->image(f_image);    // Display or change the image whenever you like
    f_picturebox->redraw();  
	}

    { Fl_Group* o = new Fl_Group(10, 320, 320, 20);
      { f_panel_ok = new Fl_Return_Button(220, 320, 50, 20, "OK");
        f_panel_ok->tooltip("Create order.");
        f_panel_ok->labelsize(11);
        f_panel_ok->window()->hotspot(f_panel_ok);
      } // Fl_Return_Button* f_panel_ok
      { f_panel_cancel = new Fl_Button(280, 320, 50, 20, "Cancel");
        f_panel_cancel->tooltip("Cancel the order.");
        f_panel_cancel->labelsize(11);
      } // Fl_Button* f_panel_cancel
      { Fl_Box* o = new Fl_Box(10, 320, 205, 20);
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
void UI_BrowseCatalog::robotModel_cb(Fl_Widget* widget, void* userData) 
{
	RobotModel* robot = (RobotModel*)userData;
	double price = robot->getPrice();
	string strPr = to_string((long double)price);
	const char *cstr = strPr.c_str();

	string strType = robot->getType();
	const char *cstrType = strType.c_str();

	UI_BrowseCatalog* catalog = UI_BrowseCatalog::create();
    catalog->f_price_input->static_value(strdup(cstr));
    catalog->f_type_input->static_value(strdup(cstrType));

	int modelno = robot->getModelNo();
	string strModelno = int_to_string(modelno);
	string strFile = strModelno + ".jpg";
	const char *cstrFile = strFile.c_str();

	catalog->f_image = new Fl_JPEG_Image(cstrFile); // Reads the file you have put in the same place as the code.
    catalog->f_picturebox->image(catalog->f_image);    // Display or change the image whenever you like
    catalog->f_picturebox->redraw();  

}
