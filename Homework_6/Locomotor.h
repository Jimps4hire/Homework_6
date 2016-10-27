#pragma once
#include "RobotPart.h"

class Locomotor : public RobotPart
{
private:
	int maxSpeed;

public:
	Locomotor(void);
	Locomotor(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price);
	~Locomotor(void);
	int powerConsumed(int speed);
};

