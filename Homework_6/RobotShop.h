#pragma once
#include "Product.h"
#include "SalesOrder.h"
#include "Customer.h"
#include "SalesAssoc.h"

class RobotShop
{
private:
	static RobotShop *robotShop;

	bool fileDirty;
	bool fileOpened;
	Product* product;
	list<SalesOrder*> salesOrders;
	list<Customer*> customers;
	list<SalesAssoc*> salesAssocs;

public:
	RobotShop(void);
	~RobotShop(void);

	static RobotShop* create();
	list<SalesOrder*> getSalesOrder();
	Product* getProduct();
	void AddOrder(SalesOrder* p_order);
	void AddCustomer(Customer* p_customer);
	void AddSalesAssoc(SalesAssoc* p_assoc);

	list<Customer*> GetCustomer();
	list<SalesAssoc*> GetSalesAssocs();
	void ViewCatalog();
	void ViewOrderPerSA();
	void ViewCustomer();
	void ViewSalesAssociate();

	bool IsFileOpen();

	void serialize(string fileName);
	void deserialize(string fileName);
};

