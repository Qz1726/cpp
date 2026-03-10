#pragma once

#include<iostream>

using namespace std;

class ServerRoom
{
public:
	//构造函数
	ServerRoom();

	ServerRoom(int id, int maxnum);

	//get set 方法
	void set_ComId(int id);
	void set_MaxNum(int num);
	int get_ComId();
	int get_MaxNum();
private:
	int m_ComId;  // 机房号

	int m_MaxMum;  // 机房最大容量

};
