#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
using namespace System::Xml;

class Customer
{
private:
	string name;

public:
	Customer(string p_name);
	~Customer(void);
	string getName();

	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	static Customer* deserialize(XmlElement^ p_elm);
};

