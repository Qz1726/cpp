#pragma once

#include"Staff.h"

class Boss : public Staff
{
public:
	//构造函数
	Boss(int id, string name, string position);

	//显示职工信息
	void showInfo();

	//析构函数
	~Boss();
};

