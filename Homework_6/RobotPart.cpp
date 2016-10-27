#include "StdAfx.h"
#include "RobotPart.h"
#include "Arm.h"
#include "Battery.h"
#include "Locomotor.h"
#include "Head.h"
#include "Torso.h"
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;

RobotPart::RobotPart(void)
{
	quantity = 0;
}

RobotPart::RobotPart(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_cost)
	: name(p_name), description(p_desc),type(p_type), partNo(p_partNo),weight(p_weight),cost(p_cost)
{
}

RobotPart::~RobotPart(void)
{
}
string RobotPart::getName()
{
	return name;
}
string RobotPart::getType()
{
	return type;
}
int RobotPart::getPartNo()
{
	return partNo;
}
RobotPart* RobotPart::createPart(string p_name)
{
	if(p_name == "Arm")
	{
		return new Arm();
	}
	else if(p_name == "Battery")
	{
		return new Battery();
	}
	else if(p_name == "Locomotor")
	{
		return new Locomotor();
	}
	else if(p_name == "Head")
	{
		return new Head();
	}
	else if(p_name == "Torso")
	{
		return new Torso();
	}
	else
	{
		return NULL;
	}
}
RobotPart* RobotPart::createPart(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_cost)
{
	if(p_name == "Arm")
	{
		return new Arm(p_name, p_desc, p_type, p_partNo, p_weight, p_cost);
	}
	else if(p_name == "Battery")
	{
		return new Battery(p_name, p_desc, p_type, p_partNo, p_weight, p_cost);
	}
	else if(p_name == "Locomotor")
	{
		return new Locomotor(p_name, p_desc, p_type, p_partNo, p_weight, p_cost);
	}
	else if(p_name == "Head")
	{
		return new Head(p_name, p_desc, p_type, p_partNo, p_weight, p_cost);
	}
	else if(p_name == "Torso")
	{
		return new Torso(p_name, p_desc, p_type, p_partNo, p_weight, p_cost);
	}
	else
	{
		return NULL;
	}
}
RobotPart* RobotPart::createPart(RobotPart* p_part)
{
	if(p_part->name == "Arm")
	{
		return new Arm(p_part->name, p_part->description, p_part->type, p_part->partNo, p_part->weight, p_part->cost);
	}
	else if(p_part->name == "Battery")
	{
		return new Battery(p_part->name, p_part->description, p_part->type, p_part->partNo, p_part->weight, p_part->cost);
	}
	else if(p_part->name == "Locomotor")
	{
		return new Locomotor(p_part->name, p_part->description, p_part->type, p_part->partNo, p_part->weight, p_part->cost);
	}
	else if(p_part->name == "Head")
	{
		return new Head(p_part->name, p_part->description, p_part->type, p_part->partNo, p_part->weight, p_part->cost);
	}
	else if(p_part->name == "Torso")
	{
		return new Torso(p_part->name, p_part->description, p_part->type, p_part->partNo, p_part->weight, p_part->cost);
	}
	else
	{
		return NULL;
	}
}


bool RobotPart::addQuantity(int p_quantity)
{
	if(quantity + p_quantity == 1)
	{
		quantity += p_quantity;
		return true;
	}
	else
	{
		return false;
	}
}

void RobotPart::serialize(XmlElement^ p_elm)
{
	String^ nm = gcnew String(name.c_str());
	p_elm->SetAttribute("Name", nm);

	String^ desc = gcnew String(description.c_str());
	p_elm->SetAttribute("Description", desc);

	String^ strtype = gcnew String(type.c_str());
	p_elm->SetAttribute("Type", strtype);

//	string strNo = to_string((long double)partNO);
//	String^ no = gcnew String(strNo.c_str());
	p_elm->SetAttribute("PartNo", Convert::ToString(partNo));

//	string strCo = to_string((long double)cost);
//	String^ Co = gcnew String(strCo.c_str());
	p_elm->SetAttribute("Cost", Convert::ToString(cost));

//	string strWe = to_string((long double)weight);
//	String^ We = gcnew String(strWe.c_str());
	p_elm->SetAttribute("Weight", Convert::ToString(weight));

//	string strQt = to_string((long double)quantity);
//	String^ Qt = gcnew String(strQt.c_str());
	p_elm->SetAttribute("Quantity", Convert::ToString(quantity));

}
RobotPart* RobotPart::deserialize(XmlElement^ p_elm)
{
	String^ attrName = p_elm->GetAttribute("Name");
	std::string name = msclr::interop::marshal_as<std::string>(attrName);

	String^ attrDesc = p_elm->GetAttribute("Description");
	std::string desc = msclr::interop::marshal_as<std::string>(attrDesc);

	String^ attrType = p_elm->GetAttribute("Type");
	std::string type = msclr::interop::marshal_as<std::string>(attrType);

	String^ attrPartNo = p_elm->GetAttribute("PartNo");
	String^ attrWeight = p_elm->GetAttribute("Cost");
	String^ attrCost = p_elm->GetAttribute("Weight");
	String^ attrQty = p_elm->GetAttribute("Quantity");

	RobotPart* part = createPart(name, desc, type, Convert::ToInt32(attrPartNo), 
		Convert::ToSingle(attrWeight), Convert::ToSingle(attrCost));
	part->addQuantity(Convert::ToInt32(attrQty));
	return part;
}

