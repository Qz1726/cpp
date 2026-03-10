#define _CRT_SECURE_NO_WARNINGS 1

#include"OrdinaryStaff.h"

//构造函数
OrdinaryStaff::OrdinaryStaff(int id, string name, string position):Staff(id,name,position)
{ }

//显示职工信息
void OrdinaryStaff::showInfo()
{ 
	cout << "职工编号->  " << this->get_id() << "\t职工姓名->  " << this->get_name() << "\t职工岗位->  " << this->get_position()
		<< "\t职责->  完成经理交代的任务" << endl;
}

//析构函数
OrdinaryStaff::~OrdinaryStaff()
{ 

}