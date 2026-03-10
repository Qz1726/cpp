#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>

using namespace std;

//基类
class Person
{
public:
	//构造函数
	Person();

	Person(string name, string password);

	//纯虚函数 
	virtual void opermenu() = 0;


	//set get 函数
	void set_name(string name);
	void set_password(string password);
	string get_name();
	string get_password();
private:
	string m_Name;
	string m_Password;
};