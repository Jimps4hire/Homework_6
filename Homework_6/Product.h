#pragma once
#include "stdafx.h"
#include <string>
#include <list>
#include <iostream>
#include "RobotModel.h"

using namespace std;

class Product
{
private:
	list<RobotModel*> list;
//	string name, description, category;
//	double price, shipping;

public:
	Product(void);
	~Product(void);

	std::list<RobotModel*> getList();
	void AddtoProduct(RobotModel* p_robot);
	RobotModel* GetRobotModel(int modelNo);
	void ViewCatalog();
	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	void deserialize(XmlElement^ p_elm);
};

