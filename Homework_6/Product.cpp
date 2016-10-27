#include "StdAfx.h"
#include <string>
#include "Product.h"
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Xml;

Product::Product(void)
{
}


Product::~Product(void)
{
}


std::list<RobotModel*> Product::getList()
{
	return list;
}


void Product::AddtoProduct(RobotModel* p_robot)
{
	list.push_back(p_robot);
}
RobotModel* Product::GetRobotModel(int modelNo)
{
	if(list.size() > 0)
	{
		for(std::list<RobotModel*>::const_iterator iterator = list.begin(), end = list.end(); iterator != end; ++iterator) 
		{			
			RobotModel* robot = *iterator;
			if(robot->getModelNo() == modelNo)
			{
				return robot;
			}
		}
	}
	return NULL;
}

void Product::ViewCatalog()
{
	cout << "Name" << " | " << /*"Description" << " | " << "Type" << " | " << */
	"ModelNO" << " | " <<  "Price" << " | " <<  "Shiping" << endl;

	if(list.size() > 0)
	{
		for(std::list<RobotModel*>::const_iterator iterator = list.begin(), end = list.end(); iterator != end; ++iterator) 
		{			
			RobotModel* robot = *iterator;
			robot->ViewRobot();
		}
	}
}


void Product::serialize(XmlDocument^ p_doc, XmlElement^ p_elm)
{
	if(list.size() > 0)
	{
		XmlElement^ elm = p_doc->CreateElement("Catalog");
        p_elm->AppendChild(elm);

		for(std::list<RobotModel*>::const_iterator iterator = list.begin(), end = list.end(); iterator != end; ++iterator) 
		{			
			XmlElement^ elmRobot = p_doc->CreateElement("Robot");
			elm->AppendChild(elmRobot);
			RobotModel* robot = *iterator;
			robot->serialize(p_doc, elmRobot);
		}
	}
}
void Product::deserialize(XmlElement^ p_elm)
{
	if(list.size() > 0)
	{
		list.clear();
	}

	if ( p_elm->HasChildNodes )
	{
		for ( int i = 0; i < p_elm->ChildNodes->Count; i++ )
		{
			XmlElement^ note = (XmlElement^)p_elm->ChildNodes[ i ];
			RobotModel* robot = RobotModel::deserialize(note);
			list.push_back(robot);
		}
	}
}