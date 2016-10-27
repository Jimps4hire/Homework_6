#pragma once
#include "RobotPart.h"

class Battery : public RobotPart
{
private:
	double energy;
	double maxPower;

public:
	Battery(void);
	Battery(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price);
	~Battery(void);
	bool addQuantity(int quantity);
};

