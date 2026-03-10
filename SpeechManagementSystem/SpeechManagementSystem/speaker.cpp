#define _CRT_SECURE_NO_WARNINGS 1

#include"speaker.h"

string speaker::get_name()
{
	return m_Name;
}
double speaker::get_score(int index)
{
	return m_Score[index];
}

void speaker::set_name(string name)
{
	m_Name = name;
}
void speaker::set_score(int index,double score)
{
	m_Score[index] = score;
}

