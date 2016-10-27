#include "StdAfx.h"
#include "Customer.h"
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
using namespace System::Xml;


Customer::Customer(string p_name)
	: name(p_name)
{
}


Customer::~Customer(void)
{
}

string Customer::getName()
{
	return name;
}

void Customer::serialize(XmlDocument^ p_doc, XmlElement^ p_elm)
{
	String^ na = gcnew String(name.c_str());
	p_elm->SetAttribute("Name", na);
}
Customer* Customer::deserialize(XmlElement^ p_elm)
{
	String^ attrName = p_elm->GetAttribute("Name");
	string name = msclr::interop::marshal_as<std::string>(attrName);
	return new Customer(name);
}
