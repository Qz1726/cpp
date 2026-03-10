#define _CRT_SECURE_NO_WARNINGS 1

#include"StaffManager.h"
#include"Manager.h"
#include"Boss.h"

int main()
{
	//测试抽象职工类
	//Staff* staff = NULL;
	//staff = new OrdinaryStaff(1, "张三", "普工");
	//staff->showInfo();
	//delete staff;

	//staff = new Manager(2, "李四", "经理");
	//staff->showInfo();
	//delete staff;

	//staff = new Boss(3, "王五", "老板");
	//staff->showInfo();
	//delete staff;
	
	StaffManager sm;
	int choice = 1;
	while (choice)
	{
		sm.menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			sm.addStaff();
			system("pause");
			system("cls");
			break;
		case 2:
			sm.showStaff();
			system("pause");
			system("cls");
			break;
		case 3:
			sm.delete_staff();
			system("pause");
			system("cls");
			break;
		case 4:
			sm.alter_staff();
			system("pause");
			system("cls");
			break;
		case 5:
			sm.find_staff();
			system("pause");
			system("cls");
			break;
		case 6:
			sm.sort_staff();
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "清空文档" << endl;
			system("pause");
			system("cls");
			break;
		case 0:
			cout << "退出管理程序，欢迎下次使用! " << endl;
			return 0;
		default:
			cout << "输出有误，请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
