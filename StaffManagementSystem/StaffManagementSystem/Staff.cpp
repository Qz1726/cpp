#define _CRT_SECURE_NO_WARNINGS 1

#include"Staff.h"

//构造函数
Staff::Staff(int id, string name, string position)
{
	m_StaffId = id;
	m_StaffName = name;
	m_StaffPosition = position;
}

//返回职工信息
int Staff::get_id()
{
	return m_StaffId;
}
string Staff::get_name()
{
	return m_StaffName;
}
string Staff::get_position()
{
	return m_StaffPosition;
}

//赋值职工信息
void Staff::set_id(int id)
{
	this->m_StaffId = id;
}
void Staff::set_name(string name)
{
	this->m_StaffName = name;
}
void Staff::set_position(string position)
{
	this->m_StaffPosition = position;
}

//析构函数
Staff::~Staff()
{ }