#pragma once

#include"person.h"
#include<vector>
#include"serverRoom.h"
#include"orderFile.h"

//打印预约信息
void printOrder(OrderFile& of, int i);

class Student :public Person
{
public:
	//构造函数
	Student();

	Student(int id, string name, string password);

	//get set 方法
	void set_id(int id);
	int get_id();

	//子菜单
	void opermenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//机房信息
	vector<ServerRoom> vSer;

private:
	int m_id;
};



