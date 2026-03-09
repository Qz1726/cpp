#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<ctime>

using namespace std;


class Person1
{
public:
	Person1(string name,int depId):m_Name(name),m_DepId(depId)
	{ }

	string get_name()
	{
		return m_Name;
	}

	int get_depId()
	{
		return m_DepId;
	}
private:
	string m_Name;
	int m_DepId;//(1,策划 2,美术 3. 研发)
};


void createPerson(vector<Person1>& v)
{
	//创建十个员工 随机分配部门
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		string name = "";
		name += nameSeed[i];
		int depId = rand() % 3 + 1;
		Person1 p(name, depId);
		v.push_back(p);
	}
}


//将员工分组
void groupPerson(vector<Person1>& v, multimap<int, Person1>& m)
{
	for (vector<Person1>::iterator it = v.begin(); it != v.end(); it++)
	{
		m.insert(make_pair((*it).get_depId(), (*it)));
	}
}


//打印员工
void showPerson(multimap<int, Person1>& m)
{
	//for (multimap<int, Person1>::iterator it = m.begin(); it != m.end(); it++)
	//{

	//	if ((*it).first == 1)
	//	{
	//		cout << "姓名->  " << (*it).second.get_name() << "部门->  策划部" << endl;
	//	}

	//	else if ((*it).first == 2)
	//	{
	//		cout << "姓名->  " << (*it).second.get_name() << "部门->  美术部" << endl;
	//	}		

	//	else if ((*it).first == 3)
	//	{
	//		cout << "姓名->  " << (*it).second.get_name() << "部门->  研发部" << endl;
	//	}
	//}

	cout << "策划部员工如下" << endl;
	//map容器中已经按key值排好序 所以只需要统计个数以及第一个位置迭代器即可
	//找到key值为1的值并返回迭代器
	multimap<int, Person1>::iterator pos = m.find(1);
	int num = 0;
	for (; pos != m.end() && num < m.count(1); pos++, num++)
	{
		cout << "姓名->  " << (*pos).second.get_name() << "部门->  策划部" << endl;
	}

	cout << "美术部员工如下" << endl;
	pos = m.find(2);
	for (num = 0; pos != m.end() && num < m.count(2); pos++, num++)
	{
		cout << "姓名->  " << (*pos).second.get_name() << "部门->  美术部" << endl;
	}

	cout << "研发部员工如下" << endl;
	pos = m.find(3);
	for (num = 0; pos != m.end() && num < m.count(3); pos++, num++)
	{
		cout << "姓名->  " << (*pos).second.get_name() << "部门->  研发部" << endl;
	}
} 


int main3()
{
	srand((unsigned int)time(NULL));

	vector<Person1> v;  
	multimap<int, Person1> m;
	//创建员工  
	createPerson(v);

	//将员工分组
	groupPerson(v,m);

	//打印员工
	showPerson(m);

	return 0;
}










