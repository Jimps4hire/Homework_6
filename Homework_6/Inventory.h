#pragma once
#include "stdafx.h"
#include <list>
#include "RobotPart.h"
using namespace std;
using namespace System::Xml;

class Inventory
{
	list<RobotPart*> armlist;
	list<RobotPart*> headlist;
	list<RobotPart*> batterylist;
	list<RobotPart*> locomotorlist;
	list<RobotPart*> torsolist;

public:
	Inventory(void);
	~Inventory(void);

	list<RobotPart*> getArmList();
	list<RobotPart*> getHeadList();
	list<RobotPart*> getBatteryList();
	list<RobotPart*> getLocomotorList();
	list<RobotPart*> getTorsoList();
//	void createParts(void);
	void addPart(RobotPart* p_part);
	RobotPart* getPart(string p_name, int p_partNo);
	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	static Inventory* deserialize(XmlElement^ p_elm);
};

