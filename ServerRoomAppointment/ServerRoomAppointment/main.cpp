#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"admin.h"

using namespace std;


//管理员子菜单界面以及各个功能接口
void adminMenu(Person* admin)
{
	//将父类指针强制转换为子类指针
	Admin* adm = (Admin*) admin;

	int choice = 1;
	while (choice)
	{
		//显示菜单
		admin->opermenu();

		cout << "请输入你的选择->";
		cin >> choice;
		switch (choice)
		{
		case 1: // 添加账号
			adm->addAccount();
			system("pause");
			system("cls");
			break;
		case 2: // 查看账号
			adm->showAccount();
			system("pause");
			system("cls");
			break;
		case 3: // 查看机房
			adm->showServerRoom();
			system("pause");
			system("cls");
			break;
		case 4: // 清空预约
			adm->clearOrder();
			system("pause");
			system("cls");
			break;
		case 0: // 注销登录
			delete adm;   //堆区内存手动释放
			return;
		default:
			cout << "输入有误 ! 重新输入 " << endl;
			break;
		}
	}

}


//学生子菜单界面以及各个功能接口
void studentMenu(Person* student)
{
	//将父类指针强制转换为子类指针 方便调用
	Student* stu =(Student*) student;

	int choice = 1;
	while (choice)
	{
		student->opermenu();
		cout << "请输入你的选择->";
		cin >> choice;

		switch (choice)
		{
		case 1: 
			//申请预约
			stu->applyOrder();
			system("pause");
			system("cls");
			break;
		case 2:
			//查看我的预约
			stu->showMyOrder();
			system("pause");
			system("cls");
			break;
		case 3:
			//查看所有预约
			stu->showAllOrder();
			system("pause");
			system("cls");
			break;
		case 4:
			//取消预约
			stu->cancelOrder();
			system("pause");
			system("cls");
			break;
		case 0:
			//注销登录
			delete stu;   //手动释放堆区空间
			return;
		default:
			break;
		}
	}
}


//老师子菜单界面以及各个功能接口
void teacherMenu(Person* teacher)
{
	//将父类指针强制转换为子类指针 方便调用
	Teacher* tea = (Teacher*)teacher;

	int choice = 1;
	while (choice)
	{
		teacher->opermenu();
		cout << "请输入你的选择->";
		cin >> choice;
		switch (choice)
		{
		case 1:
			//显示所有预约
			tea->showAllOrder();
			system("pause");
			system("cls");
			break;
		case 2:
			//审核预约
			tea->verifyOrder();
			system("pause");
			system("cls");
			break;
		case 0:
			delete tea;
			return;
		default:
			break;
		}
	}



}


//登录验证

//       需要打开的文件名    身份类型
void logIn(string fileName,int type)
{
	//父类指针指向子类对象
	Person* person = NULL;

	//打开文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	
	//判断是否打开成功
	if (!ifs.is_open())
	{
		cout << " 文件打开失败 !" << endl;
		ifs.close();
		return;
	}

	//接收信息
	int id = 0;
	string name;
	string pwd;

	//判断学生还是老师 给出不同的提示
	if (type == 1)
	{
		cout << "请输入学号->";
		cin >> id;
	}

	else if (type == 2)
	{
		cout << "请输入职工号->";
		cin >> id;
	}

	//输入姓名和密码
	cout << "请输入用户名->";
	cin >> name;
	cout << "请输入密码->";
	cin >> pwd;

	//验证信息
	if (type == 1)
	{
		//学生信息验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "学生验证通过" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//老师信息验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			if (id == fid && name == fname && pwd == fpwd)
			{
				cout << "老师验证通过" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员信息验证
		string fname;
		string fpwd;
		if(ifs >> fname && ifs >> fpwd)
		{
			if (name == fname && pwd == fpwd)
			{
				cout << "管理员验证通过" << endl;
				system("pause");
				system("cls");
				person = new Admin(name, pwd);
				adminMenu(person);
				return;
			}
		}
	}
	
	cout << "验证登录失败 !" << endl;
	
	
}


int main()
{
	int choice = 1;

	while (choice)
	{
		cout << "请选择你的身份->" << endl;
		cout << "\t\t --------------------------" << endl;
		cout << "\t\t|                          |" << endl;
		cout << "\t\t|       1. 学  生          |" << endl;
		cout << "\t\t|                          |" << endl;
		cout << "\t\t|       2. 老  师          |" << endl;
		cout << "\t\t|                          |" << endl;
		cout << "\t\t|       3. 管理员          |" << endl;
		cout << "\t\t|                          |" << endl;
		cout << "\t\t|       0. 退  出          |" << endl;
		cout << "\t\t|                          |" << endl;
		cout << "\t\t --------------------------" << endl;
		cout << "输入你的选择->";

		cin >> choice;
		switch (choice)
		{
		case 1:
			logIn(STUDENT_FILE, 1);
			system("pause");
			system("cls");
			break;
		case 2:
			logIn(TEACHER_FILE, 2);
			system("pause");
			system("cls");
			break;
		case 3:
			logIn(ADMIN_FILE, 3);
			system("pause");
			system("cls");
			break;
		case 0:
			cout << " 欢迎下次使用 ! " << endl;
			return 0;
			break;
		default:
			cout << "选择有误，请重新选择 !";
			system("pause");
			system("cls");
			break;
		}
	}
	
	return 0;
}




