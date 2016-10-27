#pragma once
#include "RobotPart.h"

class Head : public RobotPart
{

public:
	Head(void);
	Head(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price);
	~Head(void);
};

