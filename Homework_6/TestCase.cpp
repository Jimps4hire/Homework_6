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
	order1->addItem("SuperDroid HD2-S", 2, 32000.00);
	order1->addItem("Autonomous Robot", 1, 13831);
	order1->setShipping(500);
	shop->AddOrder(order1);

	// Order 2
	SalesOrder* order2 = new SalesOrder(1001, "SteveW", "Karen Sears");
	order2->addItem("SuperDroid HD2", 3, 10110.00);
	order2->setShipping(500);
	shop->AddOrder(order2);

}
void TestCase::CreateParts(RobotShop* shop)
{
	Inventory* inv = shop->GetInventory();
	
	// name, desc, type, partNo, weight, cost
	// arm
	RobotPart* amr1 = RobotPart::createPart("Arm", "Lynxmotion AL5A Robotic Arm", "RB-Owi-41", 101, 300, 2500);
	inv->addPart(amr1);
	RobotPart* amr2 = RobotPart::createPart("Arm", "Mover6 6DOF Robot Arm ", "RB-Lyn-842", 102, 400, 2699);
	inv->addPart(amr2);
	RobotPart* amr3 = RobotPart::createPart("Arm", "Mover4 Robot Arm", "RB-Rbo-85", 103, 350, 1800);
	inv->addPart(amr3);
	RobotPart* amr4 = RobotPart::createPart("Arm", "MeArm Nuka Robotic Arm", "RB-Hex-54", 104, 200, 1850);
	inv->addPart(amr4);
	RobotPart* amr5 = RobotPart::createPart("Arm", "Lynxmotion AL5B Robotic Arm", "RB-Com-02", 105, 250, 1950);
	inv->addPart(amr5);

	// head
	RobotPart* head1 = RobotPart::createPart("Head", "Robot Sputnik WiFi Mobile ", "RB-Drr-10", 201, 80, 1595);
	inv->addPart(head1);
	RobotPart* head2 = RobotPart::createPart("Head", "Robot Sputnik3 WiFi Mobile  ", "RB-Drr-15", 202, 60, 1750);
	inv->addPart(head2);
	RobotPart* head3 = RobotPart::createPart("Head", "Robot DRK8080 WiFi Mobile", "RB-Drr-01", 203, 50, 1190);
	inv->addPart(head3);
	RobotPart* head4 = RobotPart::createPart("Head", "Robot X80 WiFi Mobile", "RB-Drr-09", 204, 70, 1295);
	inv->addPart(head4);

	// locomotor
	RobotPart* locomotor1 = RobotPart::createPart("Locomotor", "Zumo Tracked Robot ", "RB-Pol-282", 301, 45, 99);
	inv->addPart(locomotor1);
	RobotPart* locomotor2 = RobotPart::createPart("Locomotor", "Zumo 32U4 Robot ", "RB-Pol-330", 302, 60, 140);
	inv->addPart(locomotor2);
	RobotPart* locomotor3 = RobotPart::createPart("Locomotor", "Line Following Robot ", "RB-Dig-99", 303, 50, 160);
	inv->addPart(locomotor3);
	RobotPart* locomotor4 = RobotPart::createPart("Locomotor", "Agent 390 Tracked Robot ", "RB-Sct-935", 304, 50, 389);
	inv->addPart(locomotor4);

	// torso
	RobotPart* torso1 = RobotPart::createPart("Torso", "Lynxmotion Johnny 5 Torso", "RB-Lyn-366", 401, 20, 550);
	inv->addPart(torso1);
	RobotPart* torso2 = RobotPart::createPart("Torso", "Lynxmotion Humanoid Biped Torso", "RB-Lyn-124", 402, 15, 230);
	inv->addPart(torso2);
	RobotPart* torso3 = RobotPart::createPart("Torso", "Lynxmotion 209 Biped Torso", "RB-Lyn-196", 403, 10, 150);
	inv->addPart(torso3);
	RobotPart* torso4 = RobotPart::createPart("Torso", "Lynxmotion Biped Scout Torso", "RB-Lyn-197", 404, 15, 160);
	inv->addPart(torso4);

	// battery
	RobotPart* battery1 = RobotPart::createPart("Battery", "Neato XV NiMH Batteries", "RB-Nto-05", 501, 2, 50);
	inv->addPart(battery1);
	RobotPart* battery2 = RobotPart::createPart("Battery", "Roomba Battery NiMH 3500mAH", "RB-Ten-18", 502, 2, 30);
	inv->addPart(battery2);
	RobotPart* battery3 = RobotPart::createPart("Battery", "Lithium Polymer Battery", "RB-Spa-672", 503, 1, 10);
	inv->addPart(battery3);
	RobotPart* battery4 = RobotPart::createPart("Battery", "Vex 7.2V. 3000mAH NiMh Battery", "RB-Inn-178", 504, 1, 30);
	inv->addPart(battery4);
}
void TestCase::CreateRobots(RobotShop* shop)
{
//	Inventory* inv = new Inventory();
	Inventory* inv = shop->GetInventory();
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

}