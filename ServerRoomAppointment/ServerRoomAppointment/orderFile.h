#pragma once
#include<iostream>
#include<string>
#include<map>
#include"globalFile.h"
#include<fstream>

using namespace std;

//读取预约文件(order)中的内容

class OrderFile
{
public:
	//构造函数
	OrderFile();

	//初始化map容器
	void IntiOrderFile();

	//拆分key值 与 value值
	void divideString(string s, map<string, string>&m);

	//更新预约信息(主要是状态)
	void updateOrderFile();

	//文件中信息条数
	int m_Size;

	//文件中信息
	map<int, map<string, string>> m_OrderFile;
};


