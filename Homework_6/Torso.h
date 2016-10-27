#pragma once
#include "RobotPart.h"

class Torso : public RobotPart
{
private:
	int batCmpartmt;

public:
	Torso(void);
	Torso(string p_name, string p_desc, string p_type, int p_partNo, double p_weight, double p_price);
	~Torso(void);
};

