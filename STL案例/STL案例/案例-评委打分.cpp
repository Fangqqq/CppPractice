#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<ctime>

//有五名选手：ABCDE，10个评委分别对其打分，去除最高分和最低分，算出平均分并显示

//选手类
class Person 
{
public:
	Person(string name, int score)
	{
		this->m_Nmae = name;
		this->m_Score = score;
	}

	string m_Nmae;
	int m_Score;//平均分
};

//创建选手并初始化赋值
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "选手";
		name += nameSeed[i];

		int score = 0;
		
		Person p(name, score);

		v.push_back(p);
	}
}

//随机打分
void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		deque<int>d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;//60-100
			d.push_back(score);
		}
		cout <<(*it).m_Nmae << "的得分为:"<<" ";
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;
		sort(d.begin(), d.end());
		//去除最高分和最低分
		d.pop_back();
		d.pop_front();
		//取平均分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			sum += (*dit);
		}
		int avg = sum / d.size();

		it->m_Score = avg;
	}
}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout <<"姓名："<< (*it).m_Nmae<<"\t" << "最终分数:" << (*it).m_Score << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	//创建选手
	vector<Person> v;
	createPerson(v);

	//打分
	setScore(v);
	
	//显示最后得分
	showScore(v);

	system("pause");
	return 0;
}