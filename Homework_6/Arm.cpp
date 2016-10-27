#include "StdAfx.h"
#include "Arm.h"
using namespace std;

Arm::Arm(void)
{
}
Arm::Arm(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_cost)
	: RobotPart(p_name, p_desc,p_type,p_partNo,p_weight,p_cost)
{
}


Arm::~Arm(void)
{
}


bool Arm::addQuantity(int p_quantity)
{
	if(quantity + p_quantity == 2)
	{
		quantity += p_quantity;
		return true;
	}
	else
	{
		return false;
	}
}

