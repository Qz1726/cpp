#define _CRT_SECURE_NO_WARNINGS 1

#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	IntiOrderFile();
}

//初始化map容器
void OrderFile::IntiOrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << " 文件打开失败!" << endl;
		ifs.close();
		return;
	}

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;
	map<string, string>m;  //用于存放每一条数据中的各个信息
	m_Size = 0;
	
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		//cout << date << " " << interval << " " << stuId << " " << stuName << " " << roomId << " " << status << " " << endl;

		//清空map容器
		m.clear();   //防止第二次读数据时里面有数据  导致打印时会打印多次第一条数据 其他数据也在里面就是打印不到

		//提取字符串
		divideString(date, m);
		divideString(interval, m);
		divideString(stuId, m);
		divideString(stuName, m);
		divideString(roomId, m);
		divideString(status, m);

		//测试  
		//for (map<string, string>::iterator it = m.begin(); it != m.end(); it++)
		//{
		//	cout << (*it).first << " ";
		//}
		//cout << endl;

		//将小map中数据存放到大map中
		m_OrderFile.insert(make_pair(m_Size, m));
		m_Size++;
	}
	ifs.close();

	//测试大容器
	//for (map<int, map<string, string>>::iterator it = m_OrderFile.begin(); it != m_OrderFile.end(); it++)
	//{
	//	cout << "条数:" << (*it).first + 1;
	//	for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)  //mit应该等于for循环里的map小容器
	//	{
	//		cout << (*mit).second << " ";
	//	}
	//	cout << endl;
	//}
}

//拆分key值 与 value值
void OrderFile::divideString(string s,map<string,string>& m)
{
	//日期:1     pos = 4
	int pos = s.find(":");
	string key;
	string value;
	key = s.substr(0, pos); //参数1  起始位置 参数2  要提取的字符数
	value = s.substr(pos + 1, s.size() - key.size() - 1);
	m.insert(make_pair(key, value));
}


//更新预约信息(主要是状态)
void OrderFile::updateOrderFile()
{
	if (m_Size == 0)
	{
		return;
	}
	ofstream ofs;
	//将所有数据重新更新
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0;i < m_Size;i++)
	{
		ofs << "日期:" << m_OrderFile[i]["日期"] << " " << "时间:" << m_OrderFile[i]["时间"] << " " << "学号:" << m_OrderFile[i]["学号"] << " "
			<< "姓名:" << m_OrderFile[i]["姓名"] << " " << "机房:" << m_OrderFile[i]["机房"] << " " << "状态:" << m_OrderFile[i]["状态"] << endl;
	}
	ofs.close();
}



