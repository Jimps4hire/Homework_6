#include "StdAfx.h"
#include "Battery.h"
using namespace std;

Battery::Battery(void)
{

}
Battery::Battery(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_cost)
	: RobotPart(p_name, p_desc,p_type,p_partNo,p_weight,p_cost)
{
}


Battery::~Battery(void)
{
}


bool Battery::addQuantity(int p_quantity)
{
	if(quantity + p_quantity == 3)
	{
		quantity += p_quantity;
		return true;
	}
	else
	{
		return false;
	}
}
