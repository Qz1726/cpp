#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<string>
#include"Person11.hpp"
#include"template_eg.hpp"

using namespace std;



//            模板

template <typename T>  //声明一个模板
void mySwap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	int a = 10;
	int b = 20;
	//调用模板 两种方式
	//1. 自动类型推导
	mySwap(a, b);
	cout << "a = " << a << " b = " << b << endl;
	double c = 1.1;
	double d = 2.2;

	//2. 显示类型调用
	mySwap<double>(c, d);
	cout << "c = " << c << " d = " << d << endl;
}

template<typename T>
void func()
{
	cout << "func() 的调用" << endl;
}
void test02()
{
	//func(); //没有明确T的数据类型
	func<int>();
}


//模板案例 排序从大到小  用char int 类型测试
template<typename T>
void mySort(T arr[],int len)  //长度通过sizeof计算 而且必须是传进来 
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

//提供打印的模板
template<typename T>
void printArray(T arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test03()
{
	char arr1[] = "baedc";
	int len = sizeof(arr1) / sizeof(arr1[0]);
	mySort(arr1, len);
	printArray(arr1, len);

	int arr2[] = { 3,5,4,1,2 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	mySort(arr2, len2);
	printArray(arr2, len2);

}


//普通函数与模板函数的区别
int myAdd1(int a, int b)
{
	return a + b;
}

template<typename T>
T myAdd2(T a, T b)
{
	return a + b;
}

void test04()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	double d = 1.1;
	cout << myAdd1(a, d) << endl;
	cout << myAdd2(a, b) << endl;
	cout << myAdd2<double>(a, d) << endl;
}


//调用规则
void myPrint(int a, int b)
{
	cout << " 调用普通函数 " << endl;
}

template<typename T>
void myPrint(T a, T b)
{
	cout << " 调用模板函数 " << endl;
}

template<typename T>
void myPrint(T a, T b, T c)
{
	cout << " 调用重载的模板函数 " << endl;
}
void test05()
{
	int a = 10;
	int b = 20;
	myPrint(a, b);
	myPrint<>(a, b);
	myPrint<>(a, b,100);

	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2);
}


//模板的局限性
class Person06
{
public:
	Person06(string name, int age):m_Name(name),m_Age(age)
	{}
	string m_Name;
	int m_Age;
};

template <typename T>
bool myCompare(T& a, T& b)
{
	if (a == b)
		return true;
	else
		return false;
}

//利用具体化的Person版本 会优先调用具体化的
template<> bool myCompare(Person06& p1, Person06& p2)
{
	if ((p1.m_Name == p2.m_Name && (p1.m_Age == p2.m_Age)))
		return true;
	else
		return false;
}

void test06()
{
	int a = 10;
	int b = 20;
	if (myCompare(a, b))
		cout << "a == b" << endl;
	else
		cout << "a != b" << endl;

	Person06 p1("Tom", 10);
	Person06 p2("Tom", 10);
	if (myCompare(p1, p2))
		cout << "p1 == p2" << endl;
	else
		cout << "p1 != p2" << endl;
}


//类模板与函数模板的区别
//类模板的模板参数列表可以有默认参数类型
template <class NameType,class AgeType = int>  //类模板的模板参数列表可以有默认参数类型
class Person07
{
public:
	Person07(NameType name, AgeType age)
	{
		m_Name = name;
		m_Age = age;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test07()
{
	Person07<string> p1("Tom", 999); //默认参数 模板参数列表写一个参数就可以了
}


//类模板成员函数创建时机

//类模板对象做函数参数
template<class T1,class T2>
class Person08
{
public:
	Person08(T1 name,T2 age):m_Name(name),m_Age(age)
	{}
	
	void showPerson08()
	{
		cout << m_Name << "  " << m_Age << endl;
	}

	T1 m_Name;
	T2 m_Age;
};

// 1. 指定传入类型的参数
void printPerson08(Person08<string,int>& p)
{
	p.showPerson08();
}

// 2. 参数模板化
template<typename T1,typename T2>
void printPerson082(Person08<T1, T2>& p)
{
	p.showPerson08();
}

// 3.整个类模板化
template<typename T>
void printPerson083(T& p)
{
	p.showPerson08();
}

void test08()
{
	Person08<string, int> p1("张三", 12);
	//对象做函数参数 所以需要调用一个函数 传入p1
	printPerson08(p1);
	printPerson082(p1);
	printPerson083(p1);
}


//类模板与继承
template<class T>
class Base
{
};

class Son :public Base<int> //子类在声明时需要指定类型才能不报错 但就失去了模板的通用性
{};

template<class T1, class T2 >
class Son2 :public Base<T2>
{
public:
	Son2()
	{
		cout << "Son2 的构造函数 " << endl;
	}
	T1 obj;
};

void test09()
{
	Son2<int, char>s;
}


//类模板成员函数在类外实现
template<class T1,class T2>
class Person10
{
public:
	Person10(T1 name, T2 age);

	void showPerson10();

	T1 m_Name;
	T2 m_Age;
};

//类外实现成员函数
template<class T1,class T2>
Person10<T1,T2>::Person10(T1 name, T2 age)
{
	m_Name = name;
	m_Age = age;
}

template<class T1, class T2>
void Person10<T1, T2>::showPerson10()// 没有参数也需要加上<T1,T2>  不加就是普通函数的类外实现
{
	cout << m_Name << "  " << m_Age << endl;
}


// 类模板分开两个文件(.h .cpp)编写出错原因以及解决方案
//  1.包含.cpp 文件 (不常用)
//  2.将.h .cpp文件合并到.hpp文件中
void test11()
{
	Person11<string, int>  p("张三", 11);
	p.showPerson11();
}


//类模板与友元
template<class T1, class T2> // Point是一个模板所以提前声明
class Point; //因为printPoint2中参数有Point类 所以要让编译器提前知道Point类 

//类外实现
template<class T1, class T2> //因为参数中有Point<T1,T2> 所以要写
void printPoint2(Point<T1,T2>& p)
{
	cout << "这个点的坐标是 " << p.m_x << "，" << p.m_y << endl;
}

template<class T1,class T2>
class Point
{
	//全局函数写在访问权限上面
	//类内实现全局函数 通过友元
	friend void printPoint(Point<T1,T2> &p)
	{
		cout << "这个点的坐标是 " << p.m_x << "，" << p.m_y << endl;
	}

	//全局函数通过 类外实现
	//首先加上 <> 证明是类模板全局函数 否则是普通全局函数,会出现无法解析的外部命令的错误
	// 函数实现时不需要加 <>
	// 因为要提前让编译器知道 所以函数实现要写在声明前面 
	friend void printPoint2<>(Point<T1,T2>& p);

public:
	Point(T1 x,T2 y):m_x(x),m_y(y)
	{ }

private:
	T1 m_x;
	T2 m_y;
};

void test12()
{
	//类内实现并调用
	Point<int, int>p(1, 2);
	printPoint(p);

	//类外实现并调用
	Point<int, int>p2(3, 4);
	printPoint2(p2);
}


//案例测试

//提供打印
template<class T>
void printIntT(myArr<T>& arr)
{
	for (int i = 0; i < arr.get_Num(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test13()
{
	myArr<int>arr1(5);
	myArr<int>arr2(arr1);
	myArr<int>arr3(10);
	arr3 = arr1;

	for (int i = 0; i < arr1.get_Capacity(); i++)
	{
		arr1.pushBack(i + 1);
	}
	printIntT(arr1);
}

//
//int main()
//{
	//模板基础
	//test01();
	
	//模板案例
	//test03();

	//普通函数与模板函数的区别
	//test04();

	//调用规则
	//test05();

	//局限性
	//test06();

	//类模板与函数模板的区别
	//test07();

	//类模板做函数参数
	//test08();

	//类模板与继承
	//test09();

	//类模板成员函数在类外实现
	
	//类模板分文件编写的问题及解决方案
	//test11();

	//类模板与友元
	//test12();

	//案例测试
//	test13();
//
//	return 0;
//}
