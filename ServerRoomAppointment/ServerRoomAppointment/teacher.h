#pragma once

#include"person.h"
#include"orderFile.h"
#include"student.h"

class Teacher:public Person
{
public:
	//构造函数
	Teacher();

	Teacher(int id, string name, string password);

	//set get函数
	void set_id(int id);
	int get_id();

	void opermenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void verifyOrder();

private:
	int m_id;  //职工编号
};
