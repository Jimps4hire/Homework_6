#pragma once
#include "RobotPart.h"

class Arm : public RobotPart
{
public:
	Arm(void);
	Arm(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price);
	~Arm(void);
	int powerConsumed(int speed);
	bool addQuantity(int quantity);
};

