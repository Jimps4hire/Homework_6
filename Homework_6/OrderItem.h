#pragma once
#include <list>
using namespace std;
using namespace System::Xml;

class OrderItem
{
private:
	string name;
	double quantity;
	double price;
	double totalcost;
public:
	OrderItem(void);
	OrderItem(string p_name, double p_quantity, double p_price, double p_totalcost);
	~OrderItem(void);

	void serialize(XmlElement^ p_elm);
	static OrderItem* deserialize(XmlElement^ p_elm);
};

