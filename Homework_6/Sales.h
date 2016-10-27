#pragma once
#include <list>
#include "SalesOrder.h"
using namespace std;

class Sales
{
private:
	list<SalesOrder*> list;

public:
	Sales(void);
	~Sales(void);
};

