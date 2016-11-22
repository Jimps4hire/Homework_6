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
	double totalPrice, subtotal, totalShip, tax/*, quantity*/;

	list<OrderItem*> items;

public:
	SalesOrder(void);
	SalesOrder(int p_orderNo, string p_salesAssoc, string p_customer);
	SalesOrder(int p_orderNo, string p_salesAssoc, string p_customer, double p_totalPrice, double p_subtotal, double p_totalShip, double p_tax/*, double p_quantity*/);
	~SalesOrder(void);

	string getCustomer()
	{
		return customer;
	}
	string getSalesAssociate()
	{
		return salesAssoc;
	}
	double getTotalPrice()
	{
		return totalPrice;
	}
	double getSubtotal()
	{
		return subtotal;
	}
	double getShipping()
	{
		return totalShip;
	}
	double getTax()
	{
		return tax;
	}
	void setShipping(double p_shiping);
	void addItem(string p_name, double p_quantity, double p_price/*, double p_shiping*/);
	void addItem(OrderItem* item);
	list<OrderItem*> getItems();
	void ViewOrderPerSA();
	void calculate();

	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	static SalesOrder* deserialize(XmlElement^ p_elm);
};

