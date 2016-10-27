#include "StdAfx.h"
#include "Locomotor.h"
using namespace std;

Locomotor::Locomotor(void)
{
}
Locomotor::Locomotor(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_cost)
	: RobotPart(p_name, p_desc, p_type,p_partNo,p_weight,p_cost)
{
}


Locomotor::~Locomotor(void)
{
}

