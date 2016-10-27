#include "StdAfx.h"
#include "SalesOrder.h"
#include <msclr\marshal_cppstd.h>
using namespace std;
using namespace System;
using namespace System::Xml;


SalesOrder::SalesOrder(void)
{
}
SalesOrder::SalesOrder(int p_orderNo, string p_salesAssoc, string p_customer)
	: orderNo(p_orderNo), salesAssoc(p_salesAssoc), customer(p_customer)
{
	totalPrice = 0;
	subtotal = 0;
	totalShip = 0;
	tax = 0;
}
SalesOrder::SalesOrder(int p_orderNo, string p_salesAssoc, string p_customer, double p_totalPrice, double p_subtotal, double p_totalShip, double p_tax)
	: orderNo(p_orderNo), salesAssoc(p_salesAssoc), customer(p_customer), totalPrice(p_totalPrice), subtotal(p_subtotal), totalShip(p_totalShip), tax(p_tax)
{
}
SalesOrder::~SalesOrder(void)
{
}
void SalesOrder::addItem(string p_name, int p_quantity, double p_price, double p_shipping)
{
	subtotal += p_price * p_quantity;
	tax = subtotal * 0.08;
	totalShip += p_shipping;
	totalPrice = subtotal + tax + totalShip;

	OrderItem* item = new OrderItem(p_name, p_quantity, p_price, p_quantity * p_price);
	list.push_back(item);
}
void SalesOrder::addItem(OrderItem* item)
{
	list.push_back(item);
}
	int orderNo;
//	time_t date;
	string salesAssoc;
	string customer;
	double totalPrice, subtotal, totalShip, tax;

void SalesOrder::ViewOrderPerSA()
{
	// SalesAssoc, OrderNo, Customer, subtotal, tax, totalShip, totalPrice
	cout << salesAssoc << " | " << orderNo << " | " << customer << " | " << 
	subtotal << " | " <<  tax << " | " <<  totalShip << " | " << totalPrice << endl;

}

void SalesOrder::serialize(XmlDocument^ p_doc, XmlElement^ p_elm)
{
	string strorno = to_string((long double)orderNo);
	String^ orno = gcnew String(strorno.c_str());
	p_elm->SetAttribute("OrderNo", orno);

	/*
	string strdat = to_string((long double)date);
	String^ dat = gcnew String(strdat.c_str());
	p_elm->SetAttribute("Date", dat);
	*/

	String^ sales = gcnew String(salesAssoc.c_str());
	p_elm->SetAttribute("SalesAssoc", sales);

	String^ cust = gcnew String(customer.c_str());
	p_elm->SetAttribute("Customer", cust);

	string strtoprice = to_string((long double)totalPrice);
	String^ toprice = gcnew String(strtoprice.c_str());
	p_elm->SetAttribute("TotalPrice", toprice);

	string strSubto = to_string((long double)subtotal);
	String^ subto = gcnew String(strSubto.c_str());
	p_elm->SetAttribute("Subtotal", subto);

	string strTosh = to_string((long double)totalShip);
	String^ tosh = gcnew String(strTosh.c_str());
	p_elm->SetAttribute("TotalShip", tosh);

	string strTax = to_string((long double)tax);
	String^ tax = gcnew String(strTax.c_str());
	p_elm->SetAttribute("Tax", tax);

	if(list.size() > 0)
	{
		for(std::list<OrderItem*>::const_iterator iterator = list.begin(), end = list.end(); iterator != end; ++iterator) 
		{			
			XmlElement^ elmItem = p_doc->CreateElement("OrderItem");
			p_elm->AppendChild(elmItem);
			OrderItem* item = *iterator;
			item->serialize(elmItem);
		}
	}

}
//	RobotPart *head, *locomotor, *torso, *battery, *arm;
SalesOrder* SalesOrder::deserialize(XmlElement^ p_elm)
{
	String^ attrOrderNo = p_elm->GetAttribute("OrderNo");
//	String^ attrDate = p_elm->GetAttribute("Date");
//	string dt = msclr::interop::marshal_as<std::string>(attrDate);
	String^ attrSales = p_elm->GetAttribute("SalesAssoc");
	string sales = msclr::interop::marshal_as<std::string>(attrSales);
	String^ attrCust = p_elm->GetAttribute("Customer");
	string cust = msclr::interop::marshal_as<std::string>(attrCust);
	String^ attrTopri = p_elm->GetAttribute("TotalPrice");
	String^ attrSubto = p_elm->GetAttribute("Subtotal");
	String^ attrToSh = p_elm->GetAttribute("TotalShip");
	String^ attrTax = p_elm->GetAttribute("Tax");

	SalesOrder* order = new SalesOrder(Convert::ToInt32(attrOrderNo), sales, cust, Convert::ToSingle(attrTopri), Convert::ToSingle(attrSubto), Convert::ToSingle(attrToSh), Convert::ToSingle(attrTax));

   if ( p_elm->HasChildNodes )
   {
      for ( int i = 0; i < p_elm->ChildNodes->Count; i++ )
      {
		XmlElement^ note = (XmlElement^)p_elm->ChildNodes[ i ];
		OrderItem* item = OrderItem::deserialize(note);
		order->addItem(item);
	  }
   }
	return order;
}
