#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<ctime>
#include<algorithm>

using namespace std;


class Contanstant
{
	friend void rate(vector<Contanstant>& v);
	friend void showConstantant(vector<Contanstant>& v);
public:
	Contanstant(string name,int grade) :m_Name(name),m_Grade(grade)
	{}
private:
	string m_Name;
	int m_Grade;
};


//创建选手
void createPlayer(vector<Contanstant>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];
		
		int grade = 0;
		Contanstant contanstant(name, grade);
		v.push_back(contanstant);
	}

}


void rate(vector<Contanstant>& v)
{
	for (vector<Contanstant>::iterator it = v.begin(); it != v.end(); it++)
	{
		//创建十次随机数并存入deque中
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int grade = rand() % 41 + 60;
			d.push_back(grade);
		}

		//排序并去除最高最低 求平均值
		sort(d.begin(), d.end());
		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (int i = 0; i < d.size(); i++)
		{
			sum += d[i];
		}
		int avg = sum / d.size();

		//存入vector容器中
		it->m_Grade = avg;
	}
}


//打印输出
void showConstantant(vector<Contanstant>& v)
{
	for (vector<Contanstant>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it).m_Name << "   " << (*it).m_Grade << endl;
	}
}





int main2()
{
	//随机数种子 确保每次随机数不同
	srand((unsigned int)time(NULL));

	vector<Contanstant>v;
	//创建五名选手
	createPlayer(v);

	//打分
	rate(v);

	//输出打印
	showConstantant(v);

	return 0;
}