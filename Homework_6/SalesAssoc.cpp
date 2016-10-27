#include "StdAfx.h"
#include "SalesAssoc.h"
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
using namespace System::Xml;


SalesAssoc::SalesAssoc(string p_name)
	: name(p_name)
{
}


SalesAssoc::~SalesAssoc(void)
{
}
string SalesAssoc::getName()
{
	return name;
}

void SalesAssoc::serialize(XmlDocument^ p_doc, XmlElement^ p_elm)
{
	String^ na = gcnew String(name.c_str());
	p_elm->SetAttribute("Name", na);
}
SalesAssoc* SalesAssoc::deserialize(XmlElement^ p_elm)
{
	String^ attrName = p_elm->GetAttribute("Name");
	string name = msclr::interop::marshal_as<std::string>(attrName);
	return new SalesAssoc(name);
}
