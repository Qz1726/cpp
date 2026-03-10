#pragma once

#include<iostream>

using namespace std;

class speaker
{
public:
	string get_name();
	double get_score(int index);

	void set_name(string name);
	void set_score(int index, double score);
private:
	string m_Name;
	double m_Score[2];  //记录两次比赛的成绩 用double防止成绩相同
};
