#define _CRT_SECURE_NO_WARNINGS 1

#include"admin.h"
#include<fstream>
#include"globalFile.h"
#include<algorithm>

//构造函数
Admin::Admin()
{}

Admin::Admin(string name, string password):Person(name,password)
{
	//有参构造中 初始化容器(将文件中数据读到容器中)
	intiVector();
	//cout << "学生人数->" << vStu.size() << endl;
	//cout << "老师人数->" << vTea.size() << endl;

	//初始化机房信息
	ifstream ifs;
	ifs.open(SERVERROOM_FILE, ios::in);

	int id = 0;
	int maxNum = 0;
	while (ifs >> id && ifs >> maxNum)
	{
		ServerRoom s(id, maxNum);
		vSer.push_back(s);
	}



}

//初始化容器
void Admin::intiVector()
{
	//先清空容器
	vStu.clear();
	vTea.clear();

	//先打开学生文件
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败 !" << endl;
		return;
	}

	int id = 0;
	string name;
	string pwd;

	while (ifs >> id && ifs >> name && ifs >> pwd)
	{
		Student s(id, name, pwd);
		vStu.push_back(s);
	}

	ifs.close();


	//初始化老师容器
	ifs.open(TEACHER_FILE, ios::in);

	//判断文件是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败 !" << endl;
		return;
	}

	while (ifs >> id && ifs >> name && ifs >> pwd)
	{
		Teacher s(id, name, pwd);
		vTea.push_back(s);
	}

	ifs.close();
}


//管理员菜单
void Admin::opermenu()
{
	cout << "  欢迎管理员 " << this->get_name() << " 登录" << endl;
	cout << "\t\t ----------------------------"  << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|       1. 添加账号          |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|       2. 查看账号          |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|       3. 查看机房          |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|       4. 清空预约          |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t|       0. 注销登录          |" << endl;
	cout << "\t\t|                            |" << endl;
	cout << "\t\t ----------------------------"  << endl;
}

//添加账号
void Admin::addAccount()
{
	cout << "请选择要添加账户的类型" << endl;
	cout << "1.学生" << endl;
	cout << "2.老师" << endl;

	//接收信息
	int id = 0;
	string name;
	string pwd;
	ofstream ofs;
	string fileName;  //不同职业打开不同文件

	int select = 0;
	
	//确定添加账户的类型
	while (1)
	{
		cin >> select;

		if (select == 1)
		{
			fileName = STUDENT_FILE;
			while (1)
			{
				cout << "请输入学号->";
				cin >> id;

				//判断是否重复
				if (checkRepeat(id, 1))
				{
					cout << "该学生已经存在，请重新输入" << endl;
				}
				else
				{
					break;
				}
			}
			break;
		}

		else if (select == 2)
		{
			fileName = TEACHER_FILE;
			while (1)
			{
				cout << "请输入职工号->";
				cin >> id;

				//判断是否重复
				if (checkRepeat(id, 2))
				{
					cout << "该老师已经存在，请重新输入" << endl;
				}
				else
				{
					break;
				}
				
			}
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

	//打开文件
	ofs.open(fileName, ios::out | ios::app);

	//提示输入用户名和密码
	cout << "请输入你的用户名->";
	cin >> name;
	cout << "请输入你的密码->";
	cin >> pwd;
	
	//存到文件中 并关闭文件
	ofs << id << " " << name << " " << pwd << endl;
	ofs.close();

	//将添加的新加到容器中
	if (select == 1)  //刚刚添加的是学生
	{
		Student s(id, name, pwd);
		vStu.push_back(s);
	}
	else
	{
		Teacher t(id, name, pwd);
		vTea.push_back(t);
	}

}

//判断学生老师是否重复  true 代表有重复     
//新添加的要加到容器中 否则还是会有重复
bool Admin::checkRepeat(int id, int type)
//               id 代表账号  type代表类型 1 -> 学生 2 -> 老师
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->get_id())
			{
				return true;
			}
		}
	}
	else if(type == 2)
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->get_id())
			{
				return true;
			}
		}
	}

	return false;
}

//打印学生信息
void printStudent(Student& s)
{
	
	cout << "学号-> " << s.get_id() << " 姓名-> " << s.get_name() << " 密码-> " << s.get_password() << endl;
	
}

//打印老师信息
void printTeacher(Teacher& t)
{
	cout << "职工号-> " << t.get_id() << " 姓名-> " << t.get_name() << " 密码-> " << t.get_password() << endl;
}

//查看账号
void Admin::showAccount()
{
	cout << "请选择要查看的选项->" << endl;
	cout << "1. 查看所有学生 " << endl;
	cout << "2. 查看所有老师 " << endl;

	int select = 1;
	
	while (select)
	{
		cin >> select;
		if (select == 1)
		{
			//for_each 中第三个参数只需要传函数名即可   对应函数不需要遍历 只需要有一个参数
			//成员函数默认已经有一个参数了 所以必须用全局函数或者静态成员函数
			for_each(vStu.begin(), vStu.end(), printStudent);
			break;
		}
		else if (select == 2)
		{
			for_each(vTea.begin(), vTea.end(), printTeacher);
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

}

//打印机房信息
void printServerRoom(ServerRoom& s)
{
	cout << "机房编号-> " << s.get_ComId() << "  机房最大容量-> " << s.get_MaxNum() << endl;
}

//查看机房
void Admin::showServerRoom()
{
	cout << "机房信息如下" << endl;
	for_each(vSer.begin(), vSer.end(), printServerRoom);
}

//清空预约
void Admin::clearOrder()
{
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);  //trunc用来清空文件
	cout << "清空成功!" << endl;
	ofs.close();
}