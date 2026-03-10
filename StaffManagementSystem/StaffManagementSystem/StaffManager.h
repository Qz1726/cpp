#pragma once

#include<iostream>
#include<fstream>
#include"OrdinaryStaff.h"
#include"Manager.h"
#include"Boss.h"

using namespace std;

class StaffManager
{
public:
	//构造函数
	StaffManager();

	//菜单
	void menu();

	//添加职工信息
	void addStaff();

	//保存到文件中
	void saveFile();

	//返回文件中员工人数
	int get_file_num();

	//将文件中的员工初始化到staffs中
	void init_staffs();

	//显示职工信息
	void showStaff();

	//判断职工是否在staffs中
	bool IsExist(int id);

	//删除职工
	void delete_staff();

	//修改职工
	void alter_staff();

	//查找职工
	void find_staff();

	//按编号排序
	void sort_staff();

	//清空所有文档
	void delete_file();

	//析构函数
	~StaffManager();

private:
	Staff** staffs;   //存放员工
	int num;          //统计staffs中人数
	bool fileIsEmpty; //文件是否为空

};

