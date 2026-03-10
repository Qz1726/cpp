#pragma once
#include"person.h"
#include<vector>
#include"student.h"
#include"teacher.h"
#include"serverRoom.h"

class Admin :public Person
{
public:
	//构造函数
	Admin();

	Admin(string name, string password);

	//管理员菜单
	void opermenu();

	//添加账号
	void addAccount();

	//查看账号
	void showAccount();

	//查看机房
	void showServerRoom();

	//清空预约
	void clearOrder();


	//判断学生老师是否有重复
	bool checkRepeat(int id, int type);



	//初始化容器
	void intiVector();

	//学生容器
	vector<Student> vStu;

	//老师容器
	vector<Teacher> vTea;

	//机房容器
	vector<ServerRoom> vSer;

};