#pragma once
#include "stdafx.h"
#include <list>
#include "RobotPart.h"
using namespace std;

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
	RobotPart* getPart(string p_name, int p_partNo);
};

