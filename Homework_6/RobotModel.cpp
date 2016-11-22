#include "StdAfx.h"
#include "RobotModel.h"
// #include <string>
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
using namespace System::Xml;

RobotModel::RobotModel(string p_name, string p_description, string p_type, int p_modelNO, double p_price, double p_shipping)
	: name(p_name), description(p_description), type(p_type), modelNO(p_modelNO), price(p_price), shipping(p_shipping)
{
	arm = NULL;
	locomotor = NULL;
	head = NULL;
	battery = NULL;
	torso = NULL;
	hide = false;
}


RobotModel::~RobotModel(void)
{
}
int RobotModel::getModelNo()
{
	return modelNO;
}
string RobotModel::getName()
{
	return name;
}
string RobotModel::getType()
{
	return type;
}
double RobotModel::getPrice()
{
	return price;
}
double RobotModel::getShipping()
{
	return shipping;
}
void RobotModel::setHide(bool p_hide)
{
	hide = p_hide;
}
bool RobotModel::getHide()
{
	return hide;
}

bool RobotModel::addPart(RobotPart* p_part, int p_quantity)
{
	if(p_part->getName() == "Arm")
	{
		if(arm == NULL)
		{
			arm = RobotPart::createPart(p_part);
		}
		return arm->addQuantity(p_quantity);
	}
	else if(p_part->getName() == "Locomotor")
	{
		if(locomotor == NULL)
		{
			locomotor = RobotPart::createPart(p_part);
		}
		return locomotor->addQuantity(p_quantity);
	}
	else if(p_part->getName() == "Head")
	{
		if(head == NULL)
		{
			head = RobotPart::createPart(p_part);
		}
		return head->addQuantity(p_quantity);
	}
	else if(p_part->getName() == "Battery")
	{
		if(battery == NULL)
		{
			battery = RobotPart::createPart(p_part);
		}
		return battery->addQuantity(p_quantity);
	}
	else if(p_part->getName() == "Torso")
	{
		if(torso == NULL)
		{
			torso = RobotPart::createPart(p_part);
		}
		return torso->addQuantity(p_quantity);
	}

	return false;
}

void RobotModel::ViewRobot()
{
	cout << name << " | " << /*description << " | " << type << " | " << */
	modelNO << " | " <<  price << " | " <<  shipping <<  endl;

}

bool RobotModel::addPart(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price, int p_quantity)
{
	if(p_name == "Arm")
	{
		if(arm == NULL)
		{
			arm = RobotPart::createPart(p_name, p_desc, p_type, p_partNo, p_weight, p_price);
		}
		return arm->addQuantity(p_quantity);
	}
	else if(p_name == "Locomotor")
	{
		if(locomotor == NULL)
		{
			locomotor = RobotPart::createPart(p_name, p_desc, p_type, p_partNo, p_weight, p_price);
		}
		return locomotor->addQuantity(p_quantity);
	}
	else if(p_name == "Head")
	{
		if(head == NULL)
		{
			head = RobotPart::createPart(p_name, p_desc, p_type, p_partNo, p_weight, p_price);
		}
		return head->addQuantity(p_quantity);
	}
	else if(p_name == "Battery")
	{
		if(battery == NULL)
		{
			battery = RobotPart::createPart(p_name, p_desc, p_type, p_partNo, p_weight, p_price);
		}
		return battery->addQuantity(p_quantity);
	}
	else if(p_name == "Torso")
	{
		if(torso == NULL)
		{
			torso = RobotPart::createPart(p_name, p_desc, p_type, p_partNo, p_weight, p_price);
		}
		return torso->addQuantity(p_quantity);
	}

	return false;
}
void RobotModel::serialize(XmlDocument^ p_doc, XmlElement^ p_elm)
{
	String^ nm = gcnew String(name.c_str());
	p_elm->SetAttribute("Name", nm);

	String^ ds = gcnew String(description.c_str());
	p_elm->SetAttribute("Description", ds);

	String^ ty = gcnew String(type.c_str());
	p_elm->SetAttribute("Type", ty);

	string strNo = to_string((long double)modelNO);
	String^ no = gcnew String(strNo.c_str());
	p_elm->SetAttribute("ModelNo", no);

	string strPr = to_string((long double)price);
	String^ pr = gcnew String(strPr.c_str());
	p_elm->SetAttribute("Price", pr);

	string strSh = to_string((long double)shipping);
	String^ sh = gcnew String(strSh.c_str());
	p_elm->SetAttribute("Shipping", sh);

	if(hide)
	{
		p_elm->SetAttribute("Hide", "true");
	}
	else
	{
		p_elm->SetAttribute("Hide", "false");
	}

	if(head != NULL)
	{
		XmlElement^ elmPart = p_doc->CreateElement("Head");
		head->serialize(elmPart);
		p_elm->AppendChild(elmPart);
	}

	if(locomotor != NULL)
	{
		XmlElement^ elmPart = p_doc->CreateElement("Locomotor");
		locomotor->serialize(elmPart);
		p_elm->AppendChild(elmPart);
	}

	if(torso != NULL)
	{
		XmlElement^ elmPart = p_doc->CreateElement("Torso");
		torso->serialize(elmPart);
		p_elm->AppendChild(elmPart);
	}

	if(battery != NULL)
	{
		XmlElement^ elmPart = p_doc->CreateElement("Battery");
		battery->serialize(elmPart);
		p_elm->AppendChild(elmPart);
	}

	if(arm != NULL)
	{
		XmlElement^ elmPart = p_doc->CreateElement("Arm");
		arm->serialize(elmPart);
		p_elm->AppendChild(elmPart);
	}
}
//	RobotPart *head, *locomotor, *torso, *battery, *arm;
RobotModel* RobotModel::deserialize(XmlElement^ p_elm)
{
	String^ attrName = p_elm->GetAttribute("Name");
	string name = msclr::interop::marshal_as<std::string>(attrName);
	String^ attrDesc = p_elm->GetAttribute("Description");
	string desc = msclr::interop::marshal_as<std::string>(attrDesc);
	String^ attrType = p_elm->GetAttribute("Type");
	string strtype = msclr::interop::marshal_as<std::string>(attrType);
	String^ attrModelNo = p_elm->GetAttribute("ModelNo");
//	string modelNo = msclr::interop::marshal_as<std::string>(attrModelNo);
	String^ attrPrice = p_elm->GetAttribute("Price");
//	string price = msclr::interop::marshal_as<std::string>(attrPrice);
	String^ attrShipping = p_elm->GetAttribute("Shipping");
	String^ attrHide = p_elm->GetAttribute("Hide");
	std::string hide = msclr::interop::marshal_as<std::string>(attrHide);

	RobotModel* robot = new RobotModel(name, desc, strtype, Convert::ToInt32(attrModelNo), Convert::ToSingle(attrPrice), Convert::ToSingle(attrShipping));
	if(hide == "true")
	{
		robot->setHide(true);
	}

   if ( p_elm->HasChildNodes )
   {
      for ( int i = 0; i < p_elm->ChildNodes->Count; i++ )
      {
		XmlElement^ note = (XmlElement^)p_elm->ChildNodes[ i ];
		if(note->Name == "Arm")
		{
			robot->arm = RobotPart::deserialize(note);
		}
		else if(note->Name == "Locomotor")
		{
			robot->locomotor = RobotPart::deserialize(note);
		}
		else if(note->Name == "Head")
		{
			robot->head = RobotPart::deserialize(note);
		}
		else if(note->Name == "Battery")
		{
			robot->battery = RobotPart::deserialize(note);
		}
		else if(note->Name == "Torso")
		{
			robot->torso = RobotPart::deserialize(note);
		}

	  }
   }
	return robot;
}
