#include "StdAfx.h"
#include <string>
#include "RobotCatalog.h"
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Xml;

RobotCatalog::RobotCatalog(void)
{
}


RobotCatalog::~RobotCatalog(void)
{
}


std::list<RobotModel*> RobotCatalog::getList()
{
	return list;
}


void RobotCatalog::AddtoCatalog(RobotModel* p_robot)
{
	list.push_back(p_robot);
}


void RobotCatalog::serialize(XmlDocument^ p_doc, XmlElement^ p_elm)
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
void RobotCatalog::deserialize(XmlElement^ p_elm)
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