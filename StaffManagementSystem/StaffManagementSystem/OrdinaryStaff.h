#pragma once


#include"Staff.h"

class OrdinaryStaff :public Staff
{
public:
	//构造函数
	OrdinaryStaff(int id, string name, string position);

	//显示职工信息
	void showInfo();

	//析构函数
	~OrdinaryStaff();
};
