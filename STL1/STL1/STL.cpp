#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>

using namespace std;

#include<vector>
#include<deque>
#include<algorithm>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<functional>


void printVector(int val)
{
	cout << val << "  ";
}

//存放内置
void test21()
{
	//创建一个vector对象
	vector<int> v;

	//往里面加数据
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//通过迭代器遍历
	vector<int>::iterator itBegin = v.begin(); //起始迭代器 指向vector第一个元素 
	vector<int>::iterator itEnd = v.end(); //结束迭代器 指向vector最后一个元素的下一个位置

	//遍历
	while (itBegin != itEnd)
	{
		cout << *itBegin << "  ";
		itBegin++;
	}
	cout << endl;

	//第二种
	for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;

	//第三种 利用STL库中的算法
	for_each(v.begin(), v.end(), printVector);
	cout << endl;
}


//存放自定义类型
class Person22
{
public:
	Person22(string name,int age):m_Name(name),m_Age(age)
	{ }


	string m_Name;
	int m_Age;
};

void test22()
{
	vector<Person22> v;

	Person22 p1("aaa", 11);
	Person22 p2("sss", 22);
	Person22 p3("ddd", 33);
	Person22 p4("fff", 44);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);


	//遍历
	for (vector<Person22>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->m_Name << "  " << it->m_Age << endl;
	}

	//存放自定义数据类型 指针
	vector<Person22*> v2;

	Person22 p11("aaa", 11);
	Person22 p22("sss", 22);
	Person22 p33("ddd", 33);
	Person22 p44("fff", 44);

	v2.push_back(&p11);
	v2.push_back(&p22);
	v2.push_back(&p33);
	v2.push_back(&p44);

	//遍历
	for (vector<Person22*>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << (*it)->m_Name << "  " << (*it)->m_Age << endl;

	}

}



//容器嵌套容器
void test23()
{
	vector<vector<int>>v;

	vector<int>v1;
	vector<int>v2;
	vector<int>v3;
	vector<int>v4;

	//向小容器中添加数据
	for (int i = 0; i < 4; i++)
	{
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}

	//将小容器添加到大容器里
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);

	//遍历
	for (vector<vector<int>>::iterator it = v.begin(); it < v.end(); it++)
	{
		//*it 是一个容器 遍历时仍需要迭代器
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
		{
			cout << *vit << "  ";
		}
		cout << endl;
	}

}


//string  容器 构造函数
void test24()
{
	string str;
	const char* s = "hello world";
	string s2(s);
	cout << s2 << endl;
	string s3(s2);
	cout << s3 << endl;
	string s4(2, 'a');
	cout << s4 << endl;
}


//string 赋值
void test25()
{
	string s1;
	s1 = "hello world";
	cout << "s1  " << s1 << endl;
	string s2;
	s2 = s1;
	cout << "s2  " << s2 << endl;
	string s3;
	s3 = 'a';
	cout << "s3  " << s3 << endl;
	string s4;
	s4.assign("hello world");
	cout << "s4  " << s4 << endl;
	string s5;
	s5.assign("hello world", 5);
	cout << "s5  " << s5 << endl;
}



//vector容器

//打印int容器
void printIntVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


//构造函数  以及赋值
void test26()
{
	vector<int> v1;
	vector<int> v2(v1.begin(), v1.end());
	vector<int> v3(5, 7);
	vector<int> v4(v3);

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	printIntVector(v1);

	//赋值
	vector<int> v5;
	v5 = v1;
	printIntVector(v1);

	v3.assign(v1.begin() + 5, v1.end());
	printIntVector(v3);
}


//容量与大小
void test27()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	v1.resize(15);
	cout << v1.capacity() << endl;
	cout << v1.size() << endl;
	printIntVector(v1);
}


//插入与删除  以及数据存取
void test28()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}
	v1.insert(v1.begin() + 4, 5);
	printIntVector(v1);
	v1.insert(v1.begin() + 4, 5,5);
	printIntVector(v1);
	v1.erase(v1.begin() + 10);
	printIntVector(v1);
	v1.erase(v1.begin() + 5,v1.begin()+10);
	printIntVector(v1);
	cout << v1.front() <<"  "<< v1.back() << endl;
}



//deque容器

//打印数据
void printIntDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造函数
void test29()
{
	deque<int> d1;    //默认构造
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i + 1);
	}
	printIntDeque(d1);
	deque<int>d2(d1.begin(), d1.end());  
	printIntDeque(d2);

	deque<int>d3(d1);       //拷贝构造
	deque<int>d4(4, 4);
	printIntDeque(d4);
}

//插入与删除
void test30()
{
	deque<int> d1;   
	for (int i = 0; i < 5; i++)
	{
		d1.push_back(i + 1);
	}
	deque<int>::iterator it = d1.begin();
	it++;
	d1.insert(it, 6);
	printIntDeque(d1);

	//d1.erase(it);   //此时it是失效的 需要重新初始化 否则会出现迭代器越界问题

	deque<int>::iterator it2 = d1.begin();
	it2++;
	d1.erase(it2);
	printIntDeque(d1);
}


//栈stack相关操作
void test31()
{
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	cout << s.size() << endl;
	cout << s.top() << endl;
}



//list容器   链表

void printIntList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}


//构造方式  以及赋值和交换
void test32()
{

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printIntList(L1);
	list<int> L2(L1.begin(), L1.end());
	printIntList(L1);
	printIntList(L2);

	list<int>L3;
	L3 = L1;
	printIntList(L3);
	list<int> L4(5, 10);
	L3.swap(L4);
	printIntList(L3);

	//插入与删除
	L1.pop_back();
	printIntList(L1);
	list<int>::iterator it = L1.begin();
	it++;
	it++;
	L1.erase(it);
	printIntList(L1);
}


//反转与排序
bool myConpare(int v1, int v2)
{
	return v1 > v2;  //第一个数比第二个数大  
}


void test33()
{
	list<int>L1;
	L1.push_back(50);
	L1.push_back(30);
	L1.push_back(20);
	L1.push_back(40);
	L1.push_back(10);
	L1.push_back(60);

	printIntList(L1);
	L1.reverse();
	printIntList(L1);

	L1.sort();
	printIntList(L1);
	//降序
	L1.sort(myConpare);
	printIntList(L1);
}


//排序案例
//人有姓名 年龄 身高属性   年龄升序  如果年龄相同 身高降序
class Person34
{
public:
	Person34(string name,int age, int high) :m_Name(name), m_Age(age), m_Height(high)
	{}

	string get_name()
	{
		return m_Name;
	}

	int get_age()
	{
		return m_Age;
	}

	int get_high()
	{
		return m_Height;
	}


private:
	string m_Name;
	int m_Age;
	int m_Height;
};

//创建对象
void createPerson(list<Person34>& L)
{
	string nameSeed = "ABCDEFIGKL";
	for (int i = 0; i < 10; i++)
	{
		string name = "";
		name += nameSeed[i];
		int age = rand() % 6 + 13;
		int height = rand() % 16 + 165;
		Person34 p(name, age, height);
		L.push_back(p);
	}
}

//排序

bool myPersonCampare(Person34 p1, Person34 p2)
{
	//if (p1.get_age() < p2.get_age())
	//{
	//	return true;
	//}
	//else if (p1.get_age() > p2.get_age())
	//{
	//	return false;
	//}
	//else
	//{
	//	if (p1.get_high() > p2.get_high())
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}


	//         优化后
	if (p1.get_age() == p2.get_age())
	{
		return p1.get_high() > p2.get_high();
	}
	else
	{
		return p1.get_age() < p2.get_age();
	}
}


void mySort(list<Person34>& L)
{
	//年龄升序  如果年龄相同 身高降序
	//对于自定义类型排序 需要写一个回调函数或仿函数
	L.sort(myPersonCampare);
}


void test34()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	list<Person34>L; 

	//创建对象
	createPerson(L);

	for (list<Person34>::iterator it = L.begin(); it != L.end(); it++)
	{
		//*it  是一个Person34 不是一个Person34*  所以用.方式访问
		cout << (*it).get_name() << "  " << (*it).get_age() << "  " << (*it).get_high() << endl;
	}


	//排序
	mySort(L);
	cout << "---------------------------------" << endl;
	for (list<Person34>::iterator it = L.begin(); it != L.end(); it++)
	{
		//*it  是一个Person34 不是一个Person34*  所以用.方式访问
		cout << (*it).get_name() << "  " << (*it).get_age() << "  " << (*it).get_high() << endl;
	}
}


//set容器
void printIntSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

class Person35
{
public:
	Person35(string name, int age)
	{
		m_Name = name;
		m_Age = age;
	}

	//必须重载<才可以存放到set中  重载>不可以

	//或者利用仿函数
	bool operator<(const Person35& p)const
	{
		return this->m_Age < p.m_Age;
	}

	string m_Name;
	int m_Age;
};

//构造函数  赋值
void test35()
{
	set<Person35> s;
	s.insert(Person35("A", 19));
	s.insert(Person35("C", 16));
	s.insert(Person35("B", 13));
	for (set<Person35>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << (*it).m_Name << "  " << (*it).m_Age << endl;
	}
	cout << endl;
}

//set排序
class myIntCompare
{
public:
	bool operator()(int v1,int v2)const //要加上const
	{
		return v1 > v2;
	}
};


void test36()
{
	set<int, myIntCompare> s1;
	s1.insert(4);
	s1.insert(1);
	s1.insert(6);
	s1.insert(3);
	s1.insert(2);
	s1.insert(5);
	for (set<int, myIntCompare>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}



//map容器
void printIntMap(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).second << endl;
	}
	cout << endl;
}

void test37()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(5, 30));
	m.insert(pair<int, int>(3, 40));
	//printIntMap(m);

	map<int,int>::iterator it = m.find(3);
	if (it != m.end())
	{
		cout << "找到了该元素 " << endl;
	}
	else
	{
		cout << "找不到" << endl;
	}

}



//                函数对象
class MyAdd
{
public:
	MyAdd()
	{
		count = 0;
	}
	int operator()(int v1, int v2)
	{
		count++;
		return v1 + v2;
	}
	int count;
};


void test38()
{
	MyAdd myAdd;
	cout << myAdd(1, 2) << endl;
	cout << myAdd(1, 2) << endl;
	cout << myAdd.count << endl;
}


//谓词
//一元谓词  
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test39()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}

	//查找是否有大于5的数字
	//GreaterFive()  匿名函数的写法
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterFive());  //可以转到定义看返回值什么类型
	if (pos != v.end())
	{
		cout << *pos << endl;
	}
	else
	{
		cout << "找不到" << endl;
	}

}


//内建函数对象
void test40()
{
	plus<int>p;
	cout << p(10, 20) << endl;

	//降序排列vector
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(30);
	v.push_back(20);

	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}

	
	//逻辑非
	vector<bool>v2;
	v2.push_back(true);
	v2.push_back(false);
	v2.push_back(true);

}



//        算法
void print01(int val)
{
	cout << val << " ";
}

class Print02
{
public:
	Print02()
	{
		count = 0;
	}

	void operator()(int& val)
	{
		count++;
		cout << val << " ";
	}
	int count;
};

void test41()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}

	for_each(v.begin(), v.end(), print01);
	cout << endl;
	Print02 p;
	for_each(v.begin(), v.end(), ref(p));   //for_each 默认是值传递 传递的是p的副本p1   而p.count仍为0  所以需要传入引用
	cout << endl;

	for_each(v.begin(), v.end(), ref(p));
	cout << endl;

	for_each(v.begin(), v.end(), ref(p));

	cout << p.count << endl;
}

//transform
class Transform
{
public:
	int operator()(int val)
	{
		return val;
	}
};

void test42()
{
	vector<int>v;

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i + 1);
	}

	vector<int> vTarget;

	vTarget.resize(v.size());   //必须要提前开辟空间
	transform(v.begin(), v.end(), vTarget.begin(), Transform());

	for_each(vTarget.begin(), vTarget.end(), Print02());

}

//  find  操作自定义数据类型
class Person43
{
public:
	Person43(string name,int age):m_Name(name),m_Age(age)
	{ }

	//重载==
	bool operator==(const Person43& p)  
	{
		if ((this->m_Name == p.m_Name) && (this->m_Age == p.m_Age))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string m_Name;
	int m_Age;
};

//年龄大于7  谓词
class Greater20
{
public:
	bool operator()(Person43& p)
	{
		if (p.m_Age > 7)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

void test43()
{
	vector<Person43>v;
	Person43 p1("aaa", 9);
	Person43 p2("bbb", 6);
	Person43 p3("ccc", 7);
	Person43 p4("ddd", 8);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	Person43 pp("ccc", 6);
	
	vector<Person43>::iterator it = find(v.begin(), v.end(), pp);
	if (it != v.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "找不到" << endl;
	}

	//查找年龄大于7的人
	it = find_if(v.begin(), v.end(), Greater20());
	if (it != v.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "找不到" << endl;
	}

}

//adjacent_find   查找相邻重复元素
void test44()
{
	vector<int>v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	v.push_back(1);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it != v.end())
	{
		cout << "找到了" << *it <<endl;
	}
	else
	{
		cout << "找不到" << endl;
	}

}

//binery_search  二分查找

void test45()
{
	vector<int>v;

	for (int i = 10; i > 0; i--)
	{
		v.push_back(i);
	}

	if (binary_search(v.begin(), v.end(), 4,greater<int>()))
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << " 找不到" << endl;
	}

}

//排序   洗牌算法
void test46()
{
	vector<int>v;

	for (int i = 10; i > 0; i--)
	{
		v.push_back(i);
	}

	//rrandom_shuffle
	//random_shuffle(v.begin(), v.end());

	//for_each(v.begin(), v.end(), Print02());

	vector<int>v2;

	for (int i = 15; i > 4; i--)
	{
		v2.push_back(i);
	}
	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	vector<int>v3;
	v3.resize(v.size() + v2.size());  


	//merge
	//merge(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	//for_each(v3.begin(), v3.end(), Print02());


	//set_intersectiom   交集的预设大小为最坏情况 两个容器中一个大容器包含一个小容器
	v3.resize(min(v.size(), v2.size()));   
	vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	//for_each(v3.begin(), itEnd, Print02());

	//set_union   并集  并集预设大小  最坏情况 两个容器一个元素都不相同
	v3.resize(v.size() + v2.size());
	itEnd = set_union(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	//for_each(v3.begin(), itEnd, Print02());

	//set_differecnce
	v3.resize(max(v.size(), v2.size()));
	itEnd = set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
	for_each(v3.begin(), itEnd, Print02());
	cout << endl;

	itEnd = set_difference(v2.begin(), v2.end(), v.begin(), v.end(), v3.begin());
	for_each(v3.begin(), itEnd, Print02());

}






int main()
{
	srand((unsigned int)time(NULL));

	//test21();

	//test22();

	//test23();
	
	//test24();
	
	//test25();

	//test26();

	//test27();

	//test28();

	//test29();

	//test30();

	//test31();

	//test32();

	//test33();

	//test34();

	//test35();

	//test36();

	//test37();

	//test38();

	//test39();

	//test40();

	//test41();

	//test42();

	//test43();

	//test44();

	//test45();

	test46();





	return 0;
}



