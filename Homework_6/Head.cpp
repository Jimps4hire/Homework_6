#include "StdAfx.h"
#include "Head.h"
using namespace std;

Head::Head(void)
{
}
Head::Head(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_cost)
	: RobotPart(p_name, p_desc, p_type, p_partNo,p_weight,p_cost)
{
}


Head::~Head(void)
{
}
