#include "StdAfx.h"
#include "Inventory.h"


Inventory::Inventory(void)
{
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
void Inventory::serialize(XmlDocument^ p_doc, XmlElement^ p_elm)
{
	XmlElement^ elmParts = p_doc->CreateElement("Parts");
	p_elm->AppendChild(elmParts);

	// arms
	if(armlist.size() > 0)
	{
		XmlElement^ elmArms = p_doc->CreateElement("Arms");
		elmParts->AppendChild(elmArms);
		for(list<RobotPart*>::const_iterator iterator = armlist.begin(), end = armlist.end(); iterator != end; ++iterator) 
		{			
			RobotPart* robotPart = *iterator;
			XmlElement^ elmArm = p_doc->CreateElement("Arm");
			robotPart->serialize(elmArm);
			elmArms->AppendChild(elmArm);
		}
	}

	// locomoters
	if(locomotorlist.size() > 0)
	{
		XmlElement^ elmLocomotors = p_doc->CreateElement("Locomotors");
		elmParts->AppendChild(elmLocomotors);
		for(list<RobotPart*>::const_iterator iterator = locomotorlist.begin(), end = locomotorlist.end(); iterator != end; ++iterator) 
		{			
			RobotPart* robotPart = *iterator;
			XmlElement^ elmLocomotor = p_doc->CreateElement("Locomotor");
			robotPart->serialize(elmLocomotor);
			elmLocomotors->AppendChild(elmLocomotor);
		}
	}

	// heads
	if(headlist.size() > 0)
	{
		XmlElement^ elmHeads = p_doc->CreateElement("Heads");
		elmParts->AppendChild(elmHeads);
		for(list<RobotPart*>::const_iterator iterator = headlist.begin(), end = headlist.end(); iterator != end; ++iterator) 
		{			
			RobotPart* robotPart = *iterator;
			XmlElement^ elmHead = p_doc->CreateElement("Head");
			robotPart->serialize(elmHead);
			elmHeads->AppendChild(elmHead);
		}
	}

	// batterys
	if(batterylist.size() > 0)
	{
		XmlElement^ elmBatterys = p_doc->CreateElement("Batterys");
		elmParts->AppendChild(elmBatterys);
		for(list<RobotPart*>::const_iterator iterator = batterylist.begin(), end = batterylist.end(); iterator != end; ++iterator) 
		{			
			RobotPart* robotPart = *iterator;
			XmlElement^ elmBattery = p_doc->CreateElement("Battery");
			robotPart->serialize(elmBattery);
			elmBatterys->AppendChild(elmBattery);
		}
	}

	if(torsolist.size() > 0)
	{
		XmlElement^ elmTorsos = p_doc->CreateElement("Torsos");
		elmParts->AppendChild(elmTorsos);
		for(list<RobotPart*>::const_iterator iterator = torsolist.begin(), end = torsolist.end(); iterator != end; ++iterator) 
		{			
			RobotPart* robotPart = *iterator;
			XmlElement^ elmTorso = p_doc->CreateElement("Torso");
			robotPart->serialize(elmTorso);
			elmTorsos->AppendChild(elmTorso);
		}
	}

}
Inventory* Inventory::deserialize(XmlElement^ p_elm)
{
	Inventory* inventory;
	return inventory;
}

