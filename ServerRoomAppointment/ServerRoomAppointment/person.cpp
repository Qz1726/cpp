#define _CRT_SECURE_NO_WARNINGS 1

#include"person.h"

//构造函数
Person::Person()
{

}

Person::Person(string name, string password)
{
	m_Name = name;
	m_Password = password;
}

// get set函数
void Person::set_name(string name)
{
	m_Name = name;
}
void Person::set_password(string password)
{
	m_Password = password;
}
string Person::get_name()
{
	return m_Name;
}
string Person::get_password()
{
	return m_Password;
}