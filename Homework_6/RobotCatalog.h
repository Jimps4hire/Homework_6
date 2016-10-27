#pragma once
#include <list>
#include "RobotModel.h"
using namespace std;


class RobotCatalog
{
private:
	list<RobotModel*> list;

public:
	RobotCatalog(void);
	~RobotCatalog(void);

	std::list<RobotModel*> getList();
	void AddtoCatalog(RobotModel* p_robot);
	void serialize(XmlDocument^ p_doc, XmlElement^ p_elm);
	void deserialize(XmlElement^ p_elm);
};

