#pragma once

#include"Staff.h"

class Manager :public Staff
{
public:
	//构造函数
	Manager(int id, string name, string position);
	
	//显示职工信息
	void showInfo();

	//析构函数
	~Manager();

};
