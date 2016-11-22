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
void Inventory::addPart(RobotPart* p_part)
{
	string name = p_part->getName();
	if(name == "Arm")
	{
		armlist.push_back(p_part);
	}
	else if(name == "Locomotor")
	{
		locomotorlist.push_back(p_part);
	}
	else if(name == "Head")
	{
		headlist.push_back(p_part);
	}
	else if(name == "Battery")
	{
		batterylist.push_back(p_part);
	}
	else if(name == "Torso")
	{
		torsolist.push_back(p_part);
	}
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
	Inventory* inventory = new Inventory();
	if ( p_elm->HasChildNodes )
	{
		for ( int i = 0; i < p_elm->ChildNodes->Count; i++ )
		{
			XmlElement^ note = (XmlElement^)p_elm->ChildNodes[ i ];
			if(note->Name == "Arms")
			{
				for ( int j = 0; j < note->ChildNodes->Count; j++ )
				{
					XmlElement^ child = (XmlElement^)note->ChildNodes[ j ];
					RobotPart* part = RobotPart::deserialize(child);
					inventory->armlist.push_back(part);
				}
			}
			else if(note->Name == "Locomotors")
			{
				for ( int j = 0; j < note->ChildNodes->Count; j++ )
				{
					XmlElement^ child = (XmlElement^)note->ChildNodes[ j ];
					RobotPart* part = RobotPart::deserialize(child);
					inventory->locomotorlist.push_back(part);
				}
			}
			else if(note->Name == "Heads")
			{
				for ( int j = 0; j < note->ChildNodes->Count; j++ )
				{
					XmlElement^ child = (XmlElement^)note->ChildNodes[ j ];
					RobotPart* part = RobotPart::deserialize(child);
					inventory->headlist.push_back(part);
				}
			}
			else if(note->Name == "Batterys")
			{
				for ( int j = 0; j < note->ChildNodes->Count; j++ )
				{
					XmlElement^ child = (XmlElement^)note->ChildNodes[ j ];
					RobotPart* part = RobotPart::deserialize(child);
					inventory->batterylist.push_back(part);
				}
			}
			else if(note->Name == "Torsos")
			{
				for ( int j = 0; j < note->ChildNodes->Count; j++ )
				{
					XmlElement^ child = (XmlElement^)note->ChildNodes[ j ];
					RobotPart* part = RobotPart::deserialize(child);
					inventory->torsolist.push_back(part);
				}
			}

		}
	}
	return inventory;
}

