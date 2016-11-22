#pragma once
#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
using namespace System::Xml;

class RobotPart
{
private:
	string name, description, type;
	int partNo;
	double weight, cost;
	bool hide;

protected:
	int quantity;

public:
	RobotPart(void);
	RobotPart(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price);
	~RobotPart(void);
	static RobotPart* createPart(string p_name);
	static RobotPart* createPart(RobotPart* p_part);
	static RobotPart* createPart(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_cost);
	virtual bool addQuantity(int p_quantity);
	void setQuantity(int p_quantity);
	void setHide(bool p_hide);
	bool getHide();
	string getName();
	string getDesc();
	string getType();
	int getPartNo();
	double getWeight();
	double getCost();
	int getQuantity();

	void serialize(XmlElement^ p_elm);
	static RobotPart* deserialize(XmlElement^ p_elm);

};

