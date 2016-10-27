#include "StdAfx.h"
#include "TestCase.h"
#include "RobotModel.h"
#include "Inventory.h"
#include "Product.h"
#include "SalesOrder.h"
#include "Customer.h"
#include "SalesAssoc.h"
using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Xml;


TestCase::TestCase(void)
{
}


TestCase::~TestCase(void)
{
}
void TestCase::CreateCustomer(RobotShop* shop)
{
	// John Smith
	Customer* customer1 = new Customer("John Smith");
	shop->AddCustomer(customer1);

	// Karen Sears
	Customer* customer2 = new Customer("Karen Sears");
	shop->AddCustomer(customer2);
}
void TestCase::CreateSalesAssoc(RobotShop* shop)
{
	// SteveW
	SalesAssoc* assoc1 = new SalesAssoc("SteveW");
	shop->AddSalesAssoc(assoc1);

	// DickersonT
	SalesAssoc* assoc2 = new SalesAssoc("DickersonT");
	shop->AddSalesAssoc(assoc2);
}
void TestCase::CreateOrder(RobotShop* shop)
{
	// Order 1
	SalesOrder* order1 = new SalesOrder(1000, "SteveW", "John Smith");
	order1->addItem("SuperDroid HD2-S", 2, 32000.00, 500);
	order1->addItem("Autonomous Robot", 1, 13831, 500);
	shop->AddOrder(order1);

	// Order 2
	SalesOrder* order2 = new SalesOrder(1001, "SteveW", "Karen Sears");
	order2->addItem("SuperDroid HD2", 3, 10110.00, 500);
	shop->AddOrder(order2);

}
void TestCase::CreateCategory(RobotShop* shop)
{
	Inventory* inv = new Inventory();
	Product* product = shop->getProduct();

	// Robot 1
	RobotModel* robot1 = new RobotModel("SuperDroid HD2-S", "SuperDroid HD2-S Mastiff Tactical Robot", "RB-Sdr-81", 101, 32000.00, 500 );
	RobotPart* part = inv->getPart("Arm", 101);
	robot1->addPart(part, 1);

	part = inv->getPart("Head", 201);
	robot1->addPart(part, 1);

	part = inv->getPart("Locomotor", 301);
	robot1->addPart(part, 1);

	part = inv->getPart("Torso", 401);
	robot1->addPart(part, 1);

	part = inv->getPart("Battery", 501);
	robot1->addPart(part, 2);
	product->AddtoProduct(robot1);

	// Robot 2
	RobotModel* robot2 = new RobotModel("SuperDroid HD2", "SuperDroid HD2 Robot ", "RB-Sdr-64", 102, 10110.00, 500  );
	part = inv->getPart("Arm", 102);
	robot2->addPart(part, 2);

	part = inv->getPart("Head", 202);
	robot2->addPart(part, 1);

	part = inv->getPart("Locomotor", 302);
	robot2->addPart(part, 1);

	part = inv->getPart("Torso", 402);
	robot2->addPart(part, 1);

	part = inv->getPart("Battery", 502);
	robot2->addPart(part, 2);
	product->AddtoProduct(robot2);

	// Robot 3
	RobotModel* robot3 = new RobotModel("High Mobility Robot", "Guardian All Terrain High Mobility Robot", "RB-Rtk-02", 103, 36735.00, 500 );
	part = inv->getPart("Arm", 103);
	robot3->addPart(part, 2);

	part = inv->getPart("Head", 203);
	robot3->addPart(part, 1);

	part = inv->getPart("Locomotor", 303);
	robot3->addPart(part, 1);

	part = inv->getPart("Torso", 403);
	robot3->addPart(part, 1);

	part = inv->getPart("Battery", 503);
	robot3->addPart(part, 2);
	product->AddtoProduct(robot3);

	// Robot 4
	RobotModel* robot4 = new RobotModel("Autonomous Robot", "Summit XL 4WD Autonomous Robot", "RB-Rtk-04", 104, 13831, 500 );
	part = inv->getPart("Arm", 104);
	robot4->addPart(part, 2);

	part = inv->getPart("Head", 204);
	robot4->addPart(part, 1);

	part = inv->getPart("Locomotor", 304);
	robot4->addPart(part, 1);

	part = inv->getPart("Torso", 404);
	robot4->addPart(part, 1);

	part = inv->getPart("Battery", 504);
	robot4->addPart(part, 3);
	product->AddtoProduct(robot4);

//	catalog->serialize(p_doc, p_elm);

}