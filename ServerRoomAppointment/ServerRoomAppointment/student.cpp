#define _CRT_SECURE_NO_WARNINGS 1

#include"student.h"
#include<fstream>
#include"globalFile.h"
#include"serverRoom.h"

//全局函数    方便学生和老师调用
//打印预约信息
void printOrder(OrderFile& of, int i)
{
	cout << "日期: 周" << of.m_OrderFile[i]["日期"] << " " << "时间:" << (of.m_OrderFile[i]["时间"] == "1" ? "上午" : "下午") << " "
		<< "学号:" << of.m_OrderFile[i]["学号"] << " " << "姓名:" << of.m_OrderFile[i]["姓名"] << " " << "机房:" << of.m_OrderFile[i]["机房"] << " ";

	//状态有四种  1.审核中 2.预约成功  3.预约失败  4.取消的预约
	string status = "状态:";
	if (of.m_OrderFile[i]["状态"] == "1")
	{
		status += "审核中 ！";
	}
	else if (of.m_OrderFile[i]["状态"] == "2")
	{
		status += "审核通过 ！";
	}
	else if (of.m_OrderFile[i]["状态"] == "3")
	{
		status += "审核失败 ！";
	}
	else if (of.m_OrderFile[i]["状态"] == "4")
	{
		status += "取消的预约 ！";
	}
	cout << status << endl;
}



Student::Student()
{

}

Student::Student(int id, string name, string password) :Person(name, password)
{
	m_id = id;

	//初始化vSer
	ifstream ifs;
	ifs.open(SERVERROOM_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败!" << endl;
		ifs.close();
		return;
	}

	int fid = 0; 
	int fnum = 0;
	while (ifs >> fid && ifs >> fnum)
	{
		ServerRoom s(fid,fnum);
		vSer.push_back(s);
	}

	ifs.close();
}

//get set 方法
void Student::set_id(int id)
{
	m_id = id;
}
int Student::get_id()
{
	return m_id;
}


void Student::opermenu()
{
	cout << "  欢迎学生 " << this->get_name() << " 登录" << endl;
	cout << "\t\t --------------------------------" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         1. 申请预约            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         2. 查看我的预约        |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         3. 查看所有预约        |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         4. 取消预约            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|         0. 注销登录            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t --------------------------------" << endl;
}

//申请预约
void Student::applyOrder()
{
	//输入预约信息
	cout << "请选择预约日期" << endl;
	cout << "1.周一" << endl;
	cout << "2.周二" << endl;
	cout << "3.周三" << endl;
	cout << "4.周四" << endl;
	cout << "5.周五" << endl;
	int date = 0;
	while (true)
	{
		cin >> date;
		if ((date >= 1) && (date <= 5))
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	

	cout << "请选择预约时间" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	int interval = 0;
	while (true)
	{
		cin >> interval;
		if ((interval >= 1) && (interval <= 2))
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	

	cout << "请选择预约的机房" << endl;
	cout << "1. " << vSer[0].get_ComId() << "机房的最大容量->" << vSer[0].get_MaxNum() << endl;   
	cout << "2. " << vSer[1].get_ComId() << "机房的最大容量->" << vSer[1].get_MaxNum() << endl;   
	cout << "3. " << vSer[2].get_ComId() << "机房的最大容量->" << vSer[2].get_MaxNum() << endl;   
	int roomId = 0;
	while (true)
	{
		cin >> roomId;
		if (roomId >= 1 && roomId <= 3)
		{
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	cout << "预约成功，等待审核中！" << endl;

	//保存预约信息
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "日期:" << date << " " << "时间:" << interval << " " << "学号:" << this->get_id() << " " 
		<< "姓名:" << this->get_name() << " " << "机房:" << roomId << " " << "状态:" << 1 <<endl;
	//状态有四种  1.审核中 2.预约成功  3.预约失败  4.取消的预约

	ofs.close();
}

//查看我的预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录 ! " << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;  //属于自己预约的条数
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->get_id() == atoi(of.m_OrderFile[i]["学号"].c_str()))
			//c++中string无法直接转换为int类型 需要先转为c风格的字符串 of.m_OrderFile[i]["stuId"].c_str()  在通过atoi()方法转为int
		{
			cout << index << "、";
			index++;
			printOrder(of,i);
		}
	}

}


//查看所有预约
void Student::showAllOrder()
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
		printOrder(of,i);
		
	}
}

//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	int index = 1;   //记录有多少条可以取消预约的

	vector<int>v;   //v中存放的是打印出来的每一条数据在文件中的真实位置 然后可以根据v的下标找到
	//
	// index         1, 2, 3,   
	// 文件真实位置  0, 4, 7,
	// v中存的数据   0, 4, 7,
	// v下标索引     0, 1, 2,

	cout << "请选择要删除的预约信息，0代表返回" << endl;

	//遍历 找到属于自己的预约 且预约状态是预约成功或者审核中的信息
	for (int i = 0; i < of.m_Size; i++)
	{		
		if (this->get_id() == atoi(of.m_OrderFile[i]["学号"].c_str()))
		{
			if (of.m_OrderFile[i]["状态"] == "1" || of.m_OrderFile[i]["状态"] == "2")
			{
				//输出可以取消的预约的信息
				cout << index << "、";
				printOrder(of, i);
				index++;

				//将文件中真实的数据位置保存
				v.push_back(i);
			}
		}
	}

	//测试
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	//选择要取消的预约信息  只需要将状态改变即可
	int select = 1;
	
	while (select)
	{
		cin >> select;
		if (select == 0)
		{
			break;
		}
		else if (select >= 1 && select <= index)
		{
			//printOrder(of, v[select - 1]);  //测试
			//将状态改为已取消即可
			of.m_OrderFile[v[select - 1]]["状态"] = "4";
			cout << "已取消预约 !" << endl;
			break;
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}

	//更新一下预约信息
	of.updateOrderFile();

}