#define _CRT_SECURE_NO_WARNINGS 1

#include"Manager.h"

//构造函数
Manager::Manager(int id, string name, string position):Staff(id,name,position)
{ }

//显示职工信息
void Manager::showInfo()
{ 
	cout << "职工编号->  " << this->get_id() << "\t职工姓名->  " << this->get_name() << "\t职工岗位->  " << this->get_position()
		<< "\t职责->  完成老板交代的任务并下发任务给员工" << endl;
}

//析构函数
Manager::~Manager()
{ }