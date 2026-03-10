#define _CRT_SECURE_NO_WARNINGS 1

#include"SpeechManager.h"
#include<iomanip>
#include<deque>
#include<numeric>
#include<fstream>

//构造函数
speechManager::speechManager()
{
	v.clear();
	m.clear();
	index = 0;
}


//菜单
void speechManager::menu()
{
	cout << "********  1. 开始演讲比赛  ********" << endl;
	cout << "********  2. 查看往届记录  ********" << endl;
	cout << "********  3. 清空比赛记录  ********" << endl;
	cout << "********  0. 退出比赛系统  ********" << endl;
	cout << "***********************************" << endl;

}


//得到首尾迭代器
map<int, speaker>::iterator speechManager::get_m_beg()
{
	return m.begin();
}
map<int, speaker>::iterator speechManager::get_m_end()
{
	return m.end();
}

vector<int>::iterator speechManager::get_v_beg()
{
	return v.begin();
}
vector<int>::iterator speechManager::get_v_end()
{
	return v.end();
}


//创建选手
void speechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++)
	{
		speaker sp;
		string name = "";
		name += nameSeed[i];
		sp.set_name(name);

		//成绩
		for (int j = 0; j < 2; j++)
		{
			sp.set_score(j, 0);
		}
		v.push_back(i + 01); 

		m.insert(make_pair(i + 01, sp));  //第一个索引是01  所以m[1]才是第一个元素
	}
}


	//比赛程序
void speechManager::speakerCompete()
{
	//创建选手
	createSpeaker();

	//第一次比赛
	index = 1;

	//抽签
	speechDraw();
	system("pause");

	//比赛
	cout << "第 " << index << " 轮比赛开始" << endl;
	cout << "比赛结果如下" << endl;
	startCompete();
	cout << "--------------------------------------------" << endl;
	system("pause");

	//显示晋级结果
	showVectory();
	system("pause");

	//第二次比赛
	index = 2;

	//抽签
	speechDraw();
	system("pause");

	//比赛
	cout << "第 " << index << " 轮比赛开始" << endl;
	cout << "比赛结果如下" << endl;
	startCompete();
	cout << "--------------------------------------------" << endl;
	system("pause");

	//显示晋级结果
	showVectory();
	system("pause");

	//保存到文件中
	cout << " 保存到文件中 " << endl;
	saveFile();
}


//抽签
void speechManager::speechDraw()
{
	//将vector中的选手打乱顺序
	random_shuffle(get_v_beg(),get_v_end());

	cout << "--------------------------------------------" << endl;
	cout << "第 " << index << " 轮抽签开始" << endl;
	cout << "抽签结果如下" << endl;
	//显示打乱后的顺序
	for (vector<int>::iterator it =get_v_beg(); it != get_v_end(); it++)
	{
		cout << setw(2) << setfill('0') << *it << "  ";
	}
	cout << endl;
	cout << "--------------------------------------------" << endl;
}


//开始比赛
void speechManager::startCompete()
{
	multimap<double, int, greater<double>> groupScore;  //记录每个小组的得分

	int num = 0;  //记录正在打分的选手 当打完前六个时进行分组 并晋级

	vector<int> vVectory;    //用于统计每组晋级的选手

	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{

		num++;
		//给每个选手打分
		deque<double> d;

		for (int j = 0; j < 12; j++)
		{
			d.push_back((rand() % 401 + 600) / 10.f);     //随机数出来一个600~1000的数 然后除以10 得到60~100的数
		}

		//测试随机数
		//for (deque<double>::iterator it = d.begin(); it != d.end(); it++)
		//{
		//	cout << *it << " ";
		//}
		//cout << endl;

		//从大到小排序 去头去尾取平均作为该选手的成绩
		sort(d.begin(), d.end(), greater<double>());  
		d.pop_back();
		d.pop_front();

		double sum = accumulate(d.begin(), d.end(),0.0f);  //第三个参数为起始累加值
		double avg = sum / 10.f;  //得到该选手的最终成绩

		//给每一个对应的选手打分
		m[*it].set_score(index - 1, avg);

		//将这个选手的得分记录到groupScore中
		groupScore.insert(make_pair(avg, *it)); 

		// 前六个为一组 这一组中进行前三名晋级
		if (num % 6 == 0)
		{
			cout << "第 " << num / 6 << " 小组比赛结果" << endl;
			for (multimap<double, int, greater<double>>::iterator mit = groupScore.begin(); mit != groupScore.end(); mit++)
			{
				cout << "编号-> " << setw(2) << setfill('0') << mit->second << "  姓名-> " << m[mit->second].get_name()
					<< "  成绩-> " << m[mit->second].get_score(index - 1) << endl;
			}

			int count = 0;   //统计这六个选手中的前三名
		
				for (multimap<double, int, greater<double>>::iterator mit2 = groupScore.begin(); mit2 != groupScore.end()
					&& count < 3; mit2++,count++)
			{
				vVectory.push_back(mit2->second);    //将前三名加入到晋级选手容器中
			}
			groupScore.clear();  //清空小组

		}
	}

	//更新v容器 用于存放下一次比赛的选手
	v.clear();
	v = vVectory;

	//测试每个选手的平均成绩
	//for (map<int, speaker>::iterator it = m.begin(); it != m.end(); it++)
	//{
	//	cout << it->second.get_name() << "  " << it->second.get_score(index - 1) << endl;
	//}

	//测试晋级小组中的选手
	//for (vector<int>::iterator it = vVectory.begin(); it != vVectory.end(); it++)
	//{
	//	cout << *it << "  ";
	//}
	//cout << endl;
}


//显示晋级结果
void speechManager::showVectory()
{
	cout << "--------------------------------------------" << endl;
	cout << "第 " << index << " 轮晋级结果如下 " << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号-> " << setw(2) << setfill('0') << *it << "  姓名-> " << m[*it].get_name() << "  成绩-> " << m[*it].get_score(index - 1) << endl;
	}
	cout << "--------------------------------------------" << endl;
}


//保存到文件中
void speechManager::saveFile()
{
	ofstream ofs;
	ofs.open("vectorySpeech.csv", ios::out | ios::app);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		ofs << setw(2) << setfill('0') << *it <<"," << m[*it].get_score(1) << ",";
	}
	ofs << endl;

	ofs.close();
}


//查看往届记录
void speechManager::showAllVectorier()
{
	ifstream ifs;
	ifs.open("vectorySpeech.csv", ios::in);
	int id1;
	double score1;
	int id2;
	double score2;
	int id3;
	double score3;

	int count = 1; //统计第几届
	while (ifs >> id1 && ifs >> score1 && ifs >> id2 && ifs >> score2 && ifs >> id3 && ifs >> score3)
	{
		cout << "第 " << count << " 届  " << "冠军:  编号-> " << id1 << " 成绩-> " << score1
			<< "  亚军:  编号-> " << id2 << " 成绩-> " << score2 << "  季军:  编号-> " << id3 << " 成绩-> " << score3 << endl;
		count++;
	}

	ifs.close();
}


//清空记录
void speechManager::deleteFile()
{
	cout << "确定清空" << endl;
	cout << "1. 确定" << endl;
	cout << "2. 取消" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs;
		ofs.open("vectorySpeech.csv", ios::trunc);
		ofs.close();

		v.clear();
		m.clear();
		index = 0;

	}
	else if (choice == 2)
	{

	}
}


//析构函数
speechManager::~speechManager()
{

}