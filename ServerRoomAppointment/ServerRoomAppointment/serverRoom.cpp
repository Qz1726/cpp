#define _CRT_SECURE_NO_WARNINGS 1

#include"serverRoom.h"

//构造函数
ServerRoom::ServerRoom()
{ }

ServerRoom::ServerRoom(int id, int maxnum)
{
	m_ComId = id;
	m_MaxMum = maxnum;
}

//get set 方法
void ServerRoom::set_ComId(int id)
{
	m_ComId = id;
}
void ServerRoom::set_MaxNum(int num)
{
	m_MaxMum = num;
}
int ServerRoom::get_ComId()
{
	return m_ComId;
}
int ServerRoom::get_MaxNum()
{
	return m_MaxMum;
}