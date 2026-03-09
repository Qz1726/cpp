#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include<iostream>
#include<string>

using namespace std;

template<class T>
class myArr
{
public:
	//构造函数
	myArr(int capacity)
	{
		//cout << "有参构造" << endl;
		m_Arr = new T[capacity];
		m_Capacity = capacity;
		m_Num = 0;
	}

	//拷贝构造
	myArr(myArr& arr)
	{
		//cout << "拷贝构造" << endl;
		m_Capacity = arr.m_Capacity;
		m_Num = arr.m_Num;
		//堆区的数据要进行深拷贝
		m_Arr = new T[arr.m_Capacity];

		//还要将原来的数据拷贝到新数组
		for (int i = 0; i < m_Num; i++)
		{
			m_Arr[i] = arr[i];
		}
	}

	//重载= 防止浅拷贝
	myArr& operator=(myArr& arr)
	{
		//cout << "=重载" << endl;
		if (m_Arr != NULL)
		{
			delete[] m_Arr;
			m_Arr = NULL;
			m_Capacity = 0;
			m_Num = 0;
		}

		m_Capacity = arr.m_Capacity;
		m_Num = arr.m_Num;
		//堆区的数据要进行深拷贝
		m_Arr = new T[arr.m_Capacity];

		//还要将原来的数据拷贝到新数组
		for (int i = 0; i < m_Num; i++)
		{
			m_Arr[i] = arr[i];
		}
		return *this;
	}

	//析构函数
	~myArr()
	{
		//cout << "析构函数" << endl; 
		if (m_Arr != NULL)
		{
			delete[] m_Arr;
			m_Arr = NULL;
		}
	}

	//尾插法
	void pushBack(T obj)
	{
		//判断是否满
		if (m_Num == m_Capacity)
		{
			return;
		}
		m_Arr[m_Num] = obj;
		m_Num++;
	}

	//尾删法 让其访问不到最后一个元素 逻辑上的删除
	void popBack()
	{
		if (m_Num == 0)
		{
			return;
		}
		m_Num--;
	}

	//通过下标访问 因为是自己创建的数组 所以要重载[]
	T& operator[](int index) //函数调用要作为左值存在 arr1[1] = 19  要返回T&
	{
		return m_Arr[index];
	}

	int get_Capacity()
	{
		return m_Capacity;
	}

	int get_Num()
	{
		return m_Num;
	}

private:
	T* m_Arr;
	int m_Capacity;
	int m_Num;
};





