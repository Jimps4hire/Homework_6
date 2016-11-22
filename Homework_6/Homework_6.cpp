// Homework_6.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Homework_6.h"
// All programs include FL/Fl.H
#include <FL/Fl.H>
// Include each “widget” you use
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include "UI_Menu.h"
#include "RobotShop.h"
#include "TestCase.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	const int X = 640;
	const int Y = 480;

	// Instance a new window object
	Fl_Window *win = new Fl_Window(X,Y);

	// Install menu bar
	UI_Menu* menu = new UI_Menu(win);

	// load the file
	RobotShop* robotShop = RobotShop::create();
	robotShop->deserialize("RobotShop.xml");

	// Done defining the new Window
	win->end();
	win->resizable();
	// Make the window visible, passing along any user options
	win->show();
	// Enter the “command loop” waiting for events
	return(Fl::run());
}
int APIENTRY _tWinMain1(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.

	RobotShop* robotShop = RobotShop::create();

	// create robot shop
	TestCase testcase;
	testcase.CreateParts(robotShop);
	testcase.CreateRobots(robotShop);
	testcase.CreateOrder(robotShop);
	testcase.CreateCustomer(robotShop);
	testcase.CreateSalesAssoc(robotShop);

	robotShop->serialize("RobotShop.xml");

	return 0;
}
