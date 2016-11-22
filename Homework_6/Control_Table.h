#pragma once
#include "stdafx.h"
#include <list>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Table_Row.H>
using namespace std;
using namespace System::Xml;

class Control_Table : public Fl_Table_Row
{
private:
    Fl_Color cell_bgcolor;				// color of cell's bg color
    Fl_Color cell_fgcolor;				// color of cell's fg color
//	DrawCellCallback * drawcellCallback;
	string header[5];
	string data[10][5];

protected:
    void draw_cell(TableContext context,  		// table cell drawing
    		   int R=0, int C=0, int X=0, int Y=0, int W=0, int H=0);
    static void event_callback(Fl_Widget*, void*);
    void event_callback2();				// callback for table events

public:
    Control_Table(int x, int y, int w, int h, /*DrawCellCallback * p_drawcellCallback,*/ const char *l=0) : Fl_Table_Row(x,y,w,h,l)
    {
        cell_bgcolor = FL_WHITE;
        cell_fgcolor = FL_BLACK;
        callback(&event_callback, (void*)this);
//		drawcellCallback = p_drawcellCallback;
	end();
    }
    ~Control_Table() { }
    Fl_Color GetCellFGColor() const { return(cell_fgcolor); }
    Fl_Color GetCellBGColor() const { return(cell_bgcolor); }
    void SetCellFGColor(Fl_Color val) { cell_fgcolor = val; }
    void SetCellBGColor(Fl_Color val) { cell_bgcolor = val; }
	void setHeader(int col, string text)
	{
		header[col] = text;
	}
	void setData(int row, int col, string text)
	{
		data[row][col] = text;
	}
};

