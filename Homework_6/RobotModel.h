#pragma once
#include "stdafx.h"
#include "RobotPart.h"
#include <string>
#include <iostream>
using namespace std;
using namespace System::Xml;

class RobotModel
{
private:
	string name;
	string description;
	string type;
	int modelNO;
	double price;
	double shipping;
	bool status;
	RobotPart *head, *locomotor, *torso, *battery, *arm;

public:
	RobotModel(string p_name, string p_description, string p_type, int p_modelNO, double p_price, double p_shipping);
	~RobotModel(void);
	int getModelNo();
	string getName();
	double getPrice();
	double getShipping();
	bool addPart(RobotPart* p_part, int p_quantity);
	bool addPart(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price, int p_quantity);
	void ViewRobot();
	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	static RobotModel* deserialize(XmlElement^ p_elm);

};

