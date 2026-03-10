#define _CRT_SECURE_NO_WARNINGS 1

#include"teacher.h"

Teacher::Teacher()
{

}

Teacher::Teacher(int id, string name, string password):Person(name,password)
{
	m_id = id;
}

//set get函数
void Teacher::set_id(int id)
{
	m_id = id;
}
int Teacher::get_id()
{
	return m_id;
}

void Teacher::opermenu()
{
	cout << "  欢迎教师 " << this->get_name() << " 登录" << endl;
	cout << "\t\t --------------------------------" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         1. 查看所有预约        |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         2. 审核预约            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         0. 注销登录            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t --------------------------------" << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录 ! " << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{

		cout << i + 1 << "、";
		printOrder(of, i);

	}
}

//审核预约
void Teacher::verifyOrder()
{
	OrderFile of;

	cout << "带审核机房预约记录如下" << endl;
	int index = 1;  //统计审核中的条数
	vector<int>v;  //记录需要审核的预约记录在文件中的真实位置

	//遍历所有审核中的预约
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_OrderFile[i]["状态"] == "1")
		{
			cout << index << "、";
			index++;
			v.push_back(i);
			printOrder(of, i);
		}
	}

	cout << "请选择要审核的预约记录，0代表返回->" << endl;
	int select = 1;
	while (select)
	{
		cin >> select;
		if (select >= 0 && select <= index)
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1.通过" << endl;
				cout << "2.不通过" << endl;
				int choice = 0;
				while (true)
				{
					cin >> choice;
					if (choice == 1)
					{
						int i = v[select - 1];
						of.m_OrderFile[v[select - 1]]["状态"] = "2";
						cout << "审核完成！" << endl;
						break;
					}
					else if (choice == 2)
					{
						of.m_OrderFile[v[select - 1]]["状态"] = "3";
						cout << "审核完成 !" << endl;
						break;
					}
					cout << "输入有误，请重新输入" << endl;
				}
				
				//保存
				of.updateOrderFile();

				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
	}
}
