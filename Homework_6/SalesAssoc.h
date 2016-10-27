#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
using namespace System::Xml;

class SalesAssoc
{
private:
	 string name; 
//	 string description, category;
//	 double price, shipping;

public:
	SalesAssoc(string p_name);
	~SalesAssoc(void);
	string getName();

	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	static SalesAssoc* deserialize(XmlElement^ p_elm);

};

