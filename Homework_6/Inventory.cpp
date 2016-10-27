#include "StdAfx.h"
#include "Inventory.h"


Inventory::Inventory(void)
{
	// name, desc, type, partNo, weight, cost
	// arm
	RobotPart* amr1 = RobotPart::createPart("Arm", "Lynxmotion AL5A Robotic Arm", "RB-Owi-41", 101, 300, 2500);
	armlist.push_back(amr1);
	RobotPart* amr2 = RobotPart::createPart("Arm", "Mover6 6DOF Robot Arm ", "RB-Lyn-842", 102, 400, 2699);
	armlist.push_back(amr2);
	RobotPart* amr3 = RobotPart::createPart("Arm", "Mover4 Robot Arm", "RB-Rbo-85", 103, 350, 1800);
	armlist.push_back(amr3);
	RobotPart* amr4 = RobotPart::createPart("Arm", "MeArm Nuka Robotic Arm", "RB-Hex-54", 104, 200, 1850);
	armlist.push_back(amr4);
	RobotPart* amr5 = RobotPart::createPart("Arm", "Lynxmotion AL5B Robotic Arm", "RB-Com-02", 105, 250, 1950);
	armlist.push_back(amr5);

	// head
	RobotPart* head1 = RobotPart::createPart("Head", "Robot Sputnik WiFi Mobile ", "RB-Drr-10", 201, 80, 1595);
	headlist.push_back(head1);
	RobotPart* head2 = RobotPart::createPart("Head", "Robot Sputnik3 WiFi Mobile  ", "RB-Drr-15", 202, 60, 1750);
	headlist.push_back(head2);
	RobotPart* head3 = RobotPart::createPart("Head", "Robot DRK8080 WiFi Mobile", "RB-Drr-01", 203, 50, 1190);
	headlist.push_back(head3);
	RobotPart* head4 = RobotPart::createPart("Head", "Robot X80 WiFi Mobile", "RB-Drr-09", 204, 70, 1295);
	headlist.push_back(head4);

	// locomotor
	RobotPart* locomotor1 = RobotPart::createPart("Locomotor", "Zumo Tracked Robot ", "RB-Pol-282", 301, 45, 99);
	locomotorlist.push_back(locomotor1);
	RobotPart* locomotor2 = RobotPart::createPart("Locomotor", "Zumo 32U4 Robot ", "RB-Pol-330", 302, 60, 140);
	locomotorlist.push_back(locomotor2);
	RobotPart* locomotor3 = RobotPart::createPart("Locomotor", "Line Following Robot ", "RB-Dig-99", 303, 50, 160);
	locomotorlist.push_back(locomotor3);
	RobotPart* locomotor4 = RobotPart::createPart("Locomotor", "Agent 390 Tracked Robot ", "RB-Sct-935", 304, 50, 389);
	locomotorlist.push_back(locomotor4);

	// torso
	RobotPart* torso1 = RobotPart::createPart("Torso", "Lynxmotion Johnny 5 Torso", "RB-Lyn-366", 401, 20, 550);
	torsolist.push_back(torso1);
	RobotPart* torso2 = RobotPart::createPart("Torso", "Lynxmotion Humanoid Biped Torso", "RB-Lyn-124", 402, 15, 230);
	torsolist.push_back(torso2);
	RobotPart* torso3 = RobotPart::createPart("Torso", "Lynxmotion 209 Biped Torso", "RB-Lyn-196", 403, 10, 150);
	torsolist.push_back(torso3);
	RobotPart* torso4 = RobotPart::createPart("Torso", "Lynxmotion Biped Scout Torso", "RB-Lyn-197", 404, 15, 160);
	torsolist.push_back(torso4);

	// battery
	RobotPart* battery1 = RobotPart::createPart("Battery", "Neato XV NiMH Batteries", "RB-Nto-05", 501, 2, 50);
	batterylist.push_back(battery1);
	RobotPart* battery2 = RobotPart::createPart("Battery", "Roomba Battery NiMH 3500mAH", "RB-Ten-18", 502, 2, 30);
	batterylist.push_back(battery2);
	RobotPart* battery3 = RobotPart::createPart("Battery", "Lithium Polymer Battery", "RB-Spa-672", 503, 1, 10);
	batterylist.push_back(battery3);
	RobotPart* battery4 = RobotPart::createPart("Battery", "Vex 7.2V. 3000mAH NiMh Battery", "RB-Inn-178", 504, 1, 30);
	batterylist.push_back(battery4);
}


Inventory::~Inventory(void)
{
}

list<RobotPart*> Inventory::getArmList()
{
	return armlist;
}
list<RobotPart*> Inventory::getHeadList()
{
	return headlist;
}
list<RobotPart*> Inventory::getBatteryList()
{
	return batterylist;
}
list<RobotPart*> Inventory::getLocomotorList()
{
	return locomotorlist;
}
list<RobotPart*> Inventory::getTorsoList()
{
	return torsolist;
}
RobotPart* Inventory::getPart(string p_name, int p_partNo)
{
	if(p_name == "Arm")
	{
		if(armlist.size() > 0)
		{
			for(list<RobotPart*>::const_iterator iterator = armlist.begin(), end = armlist.end(); iterator != end; ++iterator) 
			{			
				RobotPart* robotPart = *iterator;
				if(robotPart->getName() == p_name && robotPart->getPartNo() == p_partNo)
				{
					return robotPart;
				}
			}
		}
	}
	else if(p_name == "Locomotor")
	{
		if(locomotorlist.size() > 0)
		{
			for(list<RobotPart*>::const_iterator iterator = locomotorlist.begin(), end = locomotorlist.end(); iterator != end; ++iterator) 
			{			
				RobotPart* robotPart = *iterator;
				if(robotPart->getName() == p_name && robotPart->getPartNo() == p_partNo)
				{
					return robotPart;
				}
			}
		}
	}
	else if(p_name == "Head")
	{
		if(headlist.size() > 0)
		{
			for(list<RobotPart*>::const_iterator iterator = headlist.begin(), end = headlist.end(); iterator != end; ++iterator) 
			{			
				RobotPart* robotPart = *iterator;
				if(robotPart->getName() == p_name && robotPart->getPartNo() == p_partNo)
				{
					return robotPart;
				}
			}
		}
	}
	else if(p_name == "Battery")
	{
		if(batterylist.size() > 0)
		{
			for(list<RobotPart*>::const_iterator iterator = batterylist.begin(), end = batterylist.end(); iterator != end; ++iterator) 
			{			
				RobotPart* robotPart = *iterator;
				if(robotPart->getName() == p_name && robotPart->getPartNo() == p_partNo)
				{
					return robotPart;
				}
			}
		}
	}
	else if(p_name == "Torso")
	{
		if(torsolist.size() > 0)
		{
			for(list<RobotPart*>::const_iterator iterator = torsolist.begin(), end = torsolist.end(); iterator != end; ++iterator) 
			{			
				RobotPart* robotPart = *iterator;
				if(robotPart->getName() == p_name && robotPart->getPartNo() == p_partNo)
				{
					return robotPart;
				}
			}
		}
	}
	return NULL;
}

