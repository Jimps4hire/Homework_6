#include "StdAfx.h"
#include "RobotShop.h"

using namespace std;
using namespace System;
using namespace System::IO;
using namespace System::Xml;

RobotShop* RobotShop::robotShop = new RobotShop();

RobotShop::RobotShop(void)
{
	product = new Product();
	fileDirty = false;
	fileOpened = false;
}

RobotShop::~RobotShop(void)
{
}
RobotShop* RobotShop::create()
{
	return robotShop;
}
Product* RobotShop::getProduct()
{
	return product;
}
void RobotShop::AddOrder(SalesOrder* p_order)
{
	salesOrders.push_back(p_order);
}

void RobotShop::AddCustomer(Customer* p_customer)
{
	customers.push_back(p_customer);
}
void RobotShop::AddSalesAssoc(SalesAssoc* p_assoc)
{
	salesAssocs.push_back(p_assoc);
}
void RobotShop::ViewCatalog()
{
	product->ViewCatalog();

}
void RobotShop::ViewCustomer()
{
	cout << "Customer" << endl;
	if(customers.size() > 0)
	{
		for(std::list<Customer*>::const_iterator iterator = customers.begin(), end = customers.end(); iterator != end; ++iterator) 
		{			
			Customer* cust = *iterator;
			cout << cust->getName() << endl;
		}
	}
}
void RobotShop::ViewSalesAssociate()
{
	cout << "SalesAssoc" << endl;
	if(salesAssocs.size() > 0)
	{
		for(std::list<SalesAssoc*>::const_iterator iterator = salesAssocs.begin(), end = salesAssocs.end(); iterator != end; ++iterator) 
		{			
			SalesAssoc* sales = *iterator;
			cout << sales->getName() << endl;
		}
	}
}
void RobotShop::ViewOrderPerSA()
{
	// SalesAssoc, OrderNo, Customer, subtotal, tax, totalShip, totalPrice
	cout << "SalesAssoc" << " | " << "OrderNo" << " | " << "Customer" << " | " << 
	"Subtotal" << " | " <<  "Tax" << " | " <<  "Shiping" << " | " << "TotalPrice" << endl;

	if(salesOrders.size() > 0)
	{
		for(std::list<SalesOrder*>::const_iterator iterator = salesOrders.begin(), end = salesOrders.end(); iterator != end; ++iterator) 
		{			
			SalesOrder* order = *iterator;
			order->ViewOrderPerSA();
		}
	}
}
bool RobotShop::IsFileOpen()
{
	return fileOpened;
}

void RobotShop::serialize(string fileName)
{
	XmlDocument^ doc = gcnew XmlDocument();
	XmlElement^ elmShop = doc->CreateElement("RobotShop");
	doc->AppendChild(elmShop);
	XmlElement^ elm = doc->CreateElement("Root");
	elmShop->AppendChild(elm);

	// product
	product->serialize(doc, elm);

	// sales orders
	if(salesOrders.size() > 0)
	{
		XmlElement^ elmSO = doc->CreateElement("SalesOrders");
        elm->AppendChild(elmSO);

		for(std::list<SalesOrder*>::const_iterator iterator = salesOrders.begin(), end = salesOrders.end(); iterator != end; ++iterator) 
		{			
			XmlElement^ elmOrder = doc->CreateElement("SalesOrder");
			elmSO->AppendChild(elmOrder);
			SalesOrder* order = *iterator;
			order->serialize(doc, elmOrder);
		}
	}

	// customers
	if(customers.size() > 0)
	{
		XmlElement^ elmCU = doc->CreateElement("Customers");
        elm->AppendChild(elmCU);

		for(std::list<Customer*>::const_iterator iterator = customers.begin(), end = customers.end(); iterator != end; ++iterator) 
		{			
			XmlElement^ elmCust = doc->CreateElement("Customer");
			elmCU->AppendChild(elmCust);
			Customer* customer = *iterator;
			customer->serialize(doc, elmCust);
		}
	}

	// sales associates
	if(salesAssocs.size() > 0)
	{
		XmlElement^ elmSA = doc->CreateElement("SalesAssocs");
        elm->AppendChild(elmSA);

		for(std::list<SalesAssoc*>::const_iterator iterator = salesAssocs.begin(), end = salesAssocs.end(); iterator != end; ++iterator) 
		{			
			XmlElement^ elmAssoc = doc->CreateElement("SalesAssoc");
			elmSA->AppendChild(elmAssoc);
			SalesAssoc* SalesAssoc = *iterator;
			SalesAssoc->serialize(doc, elmAssoc);
		}
	}

	String^ file = gcnew String(fileName.c_str());
	doc->Save(file);  // "RobotShop.xml"
}
void RobotShop::deserialize(string fileName)
{
	fileOpened = true;

	XmlDocument^ doc = gcnew XmlDocument;
//    doc->LoadXml("RobotShop.xml");
	String^ file = gcnew String(fileName.c_str());
    doc->Load(file);
	XmlElement^ firstChild = (XmlElement^)doc->DocumentElement->FirstChild;
	if(firstChild->HasChildNodes)
	{
		for ( int i = 0; i < firstChild->ChildNodes->Count; i++ )
		{
			XmlElement^ note = (XmlElement^)firstChild->ChildNodes[ i ];
            if (note->Name == "Catalog")
            {
				product->deserialize(note);
			}
	        else if (note->Name == "Customers")
            {
				if ( note->HasChildNodes )
				{
					for ( int i = 0; i < note->ChildNodes->Count; i++ )
					{
						XmlElement^ noteChild = (XmlElement^)note->ChildNodes[ i ];
						Customer* customer = Customer::deserialize(noteChild);
						customers.push_back(customer);
					}
				}
			}
	        else if (note->Name == "SalesAssocs")
            {
				if ( note->HasChildNodes )
				{
					for ( int i = 0; i < note->ChildNodes->Count; i++ )
					{
						XmlElement^ noteChild = (XmlElement^)note->ChildNodes[ i ];
						SalesAssoc* salesAssoc = SalesAssoc::deserialize(noteChild);
						salesAssocs.push_back(salesAssoc);
					}
				}
			}
	        else if (note->Name == "SalesOrders")
            {
				if ( note->HasChildNodes )
				{
					for ( int i = 0; i < note->ChildNodes->Count; i++ )
					{
						XmlElement^ noteChild = (XmlElement^)note->ChildNodes[ i ];
						SalesOrder* order = SalesOrder::deserialize(noteChild);
						salesOrders.push_back(order);
					}
				}
			}
		}
	}
	/*
	XmlElement^ firstChild = (XmlElement^)doc->FirstChild;
	if ( firstChild->HasChildNodes )
	{
		for ( int i = 0; i < firstChild->ChildNodes->Count; i++ )
		{
			XmlElement^ note = (XmlElement^)firstChild->ChildNodes[ i ];
            if (note->Name == "Catalog")
            {
				product->deserialize(note);
			}
		}
	}
	*/
}

