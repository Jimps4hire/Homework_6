#include "StdAfx.h"
#include "OrderItem.h"
#include <msclr\marshal_cppstd.h>


using namespace std;
using namespace System;


OrderItem::OrderItem(void)
{
}
OrderItem::OrderItem(string p_name, int p_quantity, double p_price, double p_totalcost)
	: name(p_name), quantity(p_quantity), price(p_price), totalcost(p_totalcost)
{
}


OrderItem::~OrderItem(void)
{
}
	string name;
	int quantity;
	double price;
	double totalcost;
void OrderItem::serialize(XmlElement^ p_elm)
{
	String^ nm = gcnew String(name.c_str());
	p_elm->SetAttribute("Name", nm);

	p_elm->SetAttribute("Quantity", Convert::ToString(quantity));

	p_elm->SetAttribute("Price", Convert::ToString(price));

	p_elm->SetAttribute("TotalCost", Convert::ToString(totalcost));
}
OrderItem* OrderItem::deserialize(XmlElement^ p_elm)
{
	String^ attrName = p_elm->GetAttribute("Name");
	std::string name = msclr::interop::marshal_as<std::string>(attrName);

	String^ attrQty = p_elm->GetAttribute("Quantity");
	String^ attrPrice = p_elm->GetAttribute("Price");
	String^ attrCost = p_elm->GetAttribute("TotalCost");

	return new OrderItem(name, Convert::ToInt32(attrQty), Convert::ToSingle(attrPrice), Convert::ToSingle(attrCost));
}

