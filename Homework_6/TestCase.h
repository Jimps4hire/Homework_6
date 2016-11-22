#pragma once
#include "RobotShop.h"

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Xml;

class TestCase
{
public:
	TestCase(void);
	~TestCase(void);

	void CreateParts(RobotShop* shop);
	void CreateRobots(RobotShop* shop);
	void CreateCustomer(RobotShop* shop);
	void CreateSalesAssoc(RobotShop* shop);
	void CreateOrder(RobotShop* shop);
};

