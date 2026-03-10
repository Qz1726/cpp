#pragma once

#include<iostream>
#include<string>

using namespace std;

class Staff
{
public:
	//构造函数
	Staff(int id,string name,string position);

	//返回职工信息
	int get_id();
	string get_name();
	string get_position();

	//赋值职工信息
	void set_id(int id);
	void set_name(string name);
	void set_position(string position);

	//显示职工信息
	virtual void showInfo() = 0;

	//析构函数
	~Staff();
private:
	int m_StaffId;  //职工编号
	string m_StaffName; //职工姓名
	string m_StaffPosition; // 职工岗位
};

