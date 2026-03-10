#define _CRT_SECURE_NO_WARNINGS 1

#include"SpeechManager.h"
#include<iomanip>
#include<ctime>

using namespace std;

int main()
{
	speechManager sm;

	srand((unsigned int)time(NULL));
	//测试选手创建
	//for (map<int, speaker>::iterator it = sm.get_m_beg(); it != sm.get_m_end(); it++)
	//{
	//	cout << setw(2) << setfill('0') << it->first << "  " << it->second.get_name() << "  " << it->second.get_score(0) << endl;
	//}

	//for (vector<int>::iterator it = sm.v.begin(); it != sm.v.end(); it++)
	//{
	//	cout << setw(2) << setfill('0') << *it << "  ";
	//}
	//cout << endl;

	int choice = 1;
	while (choice)
	{
		sm.menu();
		cout << "请输入你的选择->";
		cin >> choice;

		switch (choice)
		{
		case 1:  //开始比赛
			sm.speakerCompete();
			system("pause");
			system("cls");
			break;
		case 2:  //查看往届记录
			sm.showAllVectorier();
			system("pause");
			system("cls");
			break;
		case 3:  //清空记录
			sm.deleteFile();
			system("pause");
			system("cls");
			break;
		case 0:  //退出系统
			cout << "退出演讲比赛管理系统, 欢迎下次使用!" << endl;
			return 0;
			break;
		default:
			break;
		}
	}


	return 0;
}