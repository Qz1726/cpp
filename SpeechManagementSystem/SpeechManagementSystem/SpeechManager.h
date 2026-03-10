#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include"speaker.h"


using namespace std;

class speechManager
{
public:
	//构造函数
	speechManager();

	//菜单
	void menu();

	//得到首尾迭代器
	map<int, speaker>::iterator get_m_beg();
	map<int, speaker>::iterator get_m_end();

	vector<int>::iterator get_v_beg();
	vector<int>::iterator get_v_end();

	//创建选手
	void createSpeaker();

	//比赛流程
	void speakerCompete();

	//抽签
	void speechDraw();

	//开始比赛
	void startCompete();

	//显示晋级结果
	void showVectory();

	//保存到文件中
	void saveFile();

	//查看往届记录
	void showAllVectorier();

	//清空记录
	void deleteFile();

	//析构函数
	~speechManager();

private:
	vector<int> v; //用于记录选手

	map<int, speaker> m; //用于将选手编号与选手匹配

	int index; //记录比赛的轮数
};

