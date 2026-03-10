#define _CRT_SECURE_NO_WARNINGS 1

#include"StaffManager.h"


//构造函数
StaffManager::StaffManager()
{ 
	// 不能每次打开程序都初始化 否则无法保存上一次的员工
	// 所以要根据情况来初始化
	
	//文件为空时
	ifstream ifs;
	ifs.open("staffFile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件为空" << endl;
		//此时没有内容 初始化属性为空
		staffs = NULL;
		num = 0;
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	//有文件 但内容为空时

	//如果文件为空 利用ifs读取文件中最后一个EOF标志符
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件内容为空" << endl;

		staffs = NULL;
		num = 0;
		fileIsEmpty = true;
		ifs.close();
	}

	//文件有内容时
	// 需要把文件中的内容初始化到staffs中
	// 就需要先知道有几个员工在文件中
	
	//先更新员工人数
	num = get_file_num(); 
	//cout << num << endl;

	//创建staffs
	staffs = new Staff * [num];

	//初始化staffs数组
	init_staffs();
}


//菜单
void StaffManager::menu()
{
	cout << "*********  1. 增加职工信息   *********" << endl;
	cout << "*********  2. 显示职工信息   *********" << endl;
	cout << "*********  3. 删除职工信息   *********" << endl;
	cout << "*********  4. 修改职工信息   *********" << endl;
	cout << "*********  5. 查找职工信息   *********" << endl;
	cout << "*********  6. 按照编号排序   *********" << endl;
	cout << "*********  7. 清空所有文档   *********" << endl;
	cout << "*********  0. 退出管理程序   *********" << endl;
	cout << "**************************************" << endl;

}


//添加职工信息
void StaffManager::addStaff()
{ 
	//添加职工信息 要将员工保存到staffs中 
	//所以每次都需要看原本是否有职工 否则每次重启程序员工都为空

	int len = 0;
	cout << "请输入要添加职工的人数-> ";
	cin >> len;

	if (len > 0)
	{
		//计算新员工个数
		int newNum = len + num;

		//计算新空间大小
		Staff** newstaffs = NULL;
		newstaffs = new Staff * [newNum];

		//如果原来有员工 先拷贝 在释放
		if (staffs != NULL)
		{
			for (int i = 0; i < num; i++)
			{
				newstaffs[i] = staffs[i];
			}
		}

		//添加新数据
		for (int i = 0; i < len; i++)
		{
			cout << "请输入第" << i + 1 << "个职工的编号-> ";
			int id = 0;
			cin >> id;

			cout << "请输入第" << i + 1 << "个职工的姓名-> ";
			string name = "";
			cin >> name;

			cout << "请选择第" << i + 1 << "个职工的岗位-> " << endl;
			cout << "普工" << endl;
			cout << "经理" << endl;
			cout << "老板" << endl;
			string position = "";
			cin >> position;

			Staff* staff = NULL;
			if (position == "普工")
			{
				staff = new OrdinaryStaff(id, name, position);
				newstaffs[num + i] = staff;
			}
			else if (position == "经理")
			{
				staff = new Manager(id, name, position);
				newstaffs[num + i] = staff;
			}
			else if (position == "老板")
			{
				staff = new Boss(id, name, position);
				newstaffs[num + i] = staff;
			}
			else
			{
				cout << "岗位不符合,重新输入" << endl;
				i--;
			}
		}

		//释放原来空间
		delete[] staffs;
		staffs = NULL;
		
		//更新staffs
		staffs = newstaffs;

		//更新人数
		num = newNum;

		//保存到文件中
		saveFile();
	}
	else
	{
		cout << "输入有误" << endl;
	}
}


//保存到文件中
void StaffManager::saveFile()
{
	fstream ofs;
	ofs.open("staffFile.txt", ios::out);
	for (int i = 0; i < num; i++)
	{
		ofs << "职工编号-> " << staffs[i]->get_id() << " 职工姓名-> " << staffs[i]->get_name() << " 职工岗位-> " << staffs[i]->get_position() << endl;
	}
	ofs.close();
}


//返回文件中员工人数
int StaffManager::get_file_num()
{
	ifstream ifs;
	ifs.open("staffFile.txt", ios::in);

	string s1;
	string s2;
	string s3;
	int id = 0;
	string name = "";
	string position = "";

	int num = 0;  //统计文件中员工人数
	while (ifs >> s1 && ifs >> id && ifs >> s2 && ifs >> name && ifs >> s3 && ifs >> position)
	{
		num++;
	}

	ifs.close();
	return num;
}


//将文件中的员工初始化到staffs中
void StaffManager::init_staffs()
{
	ifstream ifs;
	ifs.open("staffFile.txt", ios::in);

	string s1;
	string s2;
	string s3;
	int id = 0;
	string name = "";
	string position = "";
	
	int index = 0;   //索引 将文件中员工记录到staffs中
	while (ifs >> s1 && ifs >> id && ifs >> s2 && ifs >> name && ifs >> s3 && ifs >> position)
	{
		Staff* staff = NULL;
		if (position == "普工")
		{
			staff = new OrdinaryStaff(id, name, position);
			staffs[index] = staff;
		}
		else if (position == "经理")
		{
			staff = new Manager(id, name, position);
			staffs[index] = staff;
		}
		else if (position == "老板")
		{
			staff = new Boss(id, name, position);
			staffs[index] = staff;
		}

		index++;
	}

	ifs.close();
}


//显示职工信息
void StaffManager::showStaff()
{
	for (int i = 0; i < num; i++)
	{
		staffs[i]->showInfo();
	}
}


//判断职工是否在staffs中
bool StaffManager::IsExist(int id)
{
	for (int i = 0; i < num; i++)
	{
		if (id == staffs[i]->get_id())
		{
			return true;
		}
	}
	return false;
}


//删除职工
void StaffManager::delete_staff()
{
	cout << "请选择要删除职工的编号->";
	int id = 0;
	cin >> id;
	if (IsExist(id))
	{
		int index = 0;  //记录这个员工的位置
		for (; index < num; index++)
		{
			if (id == staffs[index]->get_id())
			{
				break;
			}
		}

		//需要将此员工以后的员工 全部覆盖到前一个员工上
		for (; index < num - 1; index++)
		{
			staffs[index] = staffs[index + 1];
		}
		
		num--;

		cout << "删除成功 !" << endl;
	}
	else
	{
		cout << "该员工不存在" << endl;
	}

	saveFile();
}


//修改职工
void StaffManager::alter_staff()
{
	cout << "请选择要修改的职工的编号->";
	int id = 0;
	cin >> id;
	if (IsExist(id))
	{
		int index = 0;  //记录这个员工的位置
		for (; index < num; index++)
		{
			if (id == staffs[index]->get_id())
			{
				break;
			}
		}

		string newName = "";
		string newPosition = "";
		cout << "请输入该员工的新姓名-> ";
		cin >> newName;
		cout << "请输入该员工的新岗位-> ";
		cin >> newPosition;

		//更新职工信息
		Staff* staff = NULL;
		if (newPosition == "普工")
		{
			staff = new OrdinaryStaff(id, newName, newPosition);
		}
		else if (newPosition == "经理")
		{
			staff = new Manager(id, newName, newPosition);
		}
		else if (newPosition == "老板")
		{
			staff = new Boss(id, newName, newPosition);
		}
		else
		{
			cout << "输入有误" << endl;
		}
		staffs[index] = staff;

		cout << "修改完成! " << endl;
	}
	else
	{
		cout << "该员工不存在" << endl;
	}

	saveFile();
}


//查找职工
void StaffManager::find_staff()
{
	cout << "请选择要查找的方式->" << endl;
	cout << "1. 编号" << endl;
	cout << "2. 姓名" << endl;
	int choice = 1;
	cin >> choice;
	int id = 0;
	string name = "";
	int index = 0;
	switch (choice)
	{
	case 1:
		cout << "请输入要查找的员工的编号->";
		cin >> id;
		if (IsExist(id))
		{
			for (index = 0; index < num; index++)
			{
				if (id == staffs[index]->get_id())
				{
					break;
				}
			}

			if (index == num)
			{
				cout << "该员工不存在" << endl;
			}
			else
			{
				cout << "该员工信息如下" << endl;
				staffs[index]->showInfo();
			}
		}
		else
		{
			cout << "输入有误" << endl;
		}
		break;
	case 2:
		cout << "请输入要查找的员工的姓名" << endl;
		cin >> name;

		//遍历所有 防止重名情况出现
		
		for (index = 0; index < num; index++)
		{
			if (name == staffs[index]->get_name())
			{
				cout << "该员工信息如下" << endl;
				staffs[index]->showInfo();
			}
		}
		if (index == num)
		{
			cout << "该员工不存在" << endl;
		}

		break;
	default:
		cout << "输入有误" << endl;
		break;
	}
}


//按编号排序
void StaffManager::sort_staff()
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (staffs[j]->get_id() > staffs[j]->get_id())
			{
				Staff* temp = staffs[j];
				staffs[j] = staffs[j + 1];
				staffs[j + 1] = temp;
				delete temp;
			}
		}
	}
}


//清空所有文档
void StaffManager::delete_file()
{

}


//析构函数
StaffManager::~StaffManager()
{
	if (staffs != NULL)
	{
		delete[] staffs;
		staffs = NULL;
	}
}