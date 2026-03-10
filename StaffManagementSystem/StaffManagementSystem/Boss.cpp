#define _CRT_SECURE_NO_WARNINGS 1

#include"Boss.h"

//构造函数
Boss::Boss(int id, string name, string position):Staff(id,name,position)
{ }

//显示职工信息
void Boss::showInfo()
{
	cout << "职工编号->  " << this->get_id() << "\t职工姓名->  " << this->get_name() << "\t职工岗位->  " << this->get_position()
		<< "\t职责->  管理公司所有事务" << endl;
}

//析构函数
Boss::~Boss()
{ }