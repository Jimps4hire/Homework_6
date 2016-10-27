#pragma once
#include "stdafx.h"
#include <ctime>
#include <time.h>
#include <string>
#include <iostream>
#include "OrderItem.h"

using namespace std;
using namespace System::Xml;

class SalesOrder
{
private:
	int orderNo;
//	time_t date;
	string salesAssoc;
	string customer;
	double totalPrice, subtotal, totalShip, tax;

	list<OrderItem*> list;

public:
	SalesOrder(void);
	SalesOrder(int p_orderNo, string p_salesAssoc, string p_customer);
	SalesOrder(int p_orderNo, string p_salesAssoc, string p_customer, double totalPrice, double subtotal, double totalShip, double tax);
	~SalesOrder(void);

	void addItem(string p_name, int p_quantity, double p_price, double p_shiping);
	void addItem(OrderItem* item);
	void ViewOrderPerSA();

	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	static SalesOrder* deserialize(XmlElement^ p_elm);
};

