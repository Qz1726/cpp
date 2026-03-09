#pragma once

#include<iostream>
#include<string>

using namespace std;

template<class T1, class T2>
class Person11
{
public:
	Person11(T1 name, T2 age);

	void showPerson11();

	T1 m_Name;
	T2 m_Age;
};


template<class T1,class T2>
Person11<T1, T2>::Person11(T1 name, T2 age)
{
	m_Name = name;
	m_Age = age;
}

template<class T1,class T2>
void Person11<T1,T2>::showPerson11()
{
	cout << m_Name << "  " << m_Age << endl;
}
