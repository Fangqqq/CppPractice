#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
#include<ctime>

//������ѡ�֣�ABCDE��10����ί�ֱ�����֣�ȥ����߷ֺ���ͷ֣����ƽ���ֲ���ʾ

//ѡ����
class Person 
{
public:
	Person(string name, int score)
	{
		this->m_Nmae = name;
		this->m_Score = score;
	}

	string m_Nmae;
	int m_Score;//ƽ����
};

//����ѡ�ֲ���ʼ����ֵ
void createPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;
		
		Person p(name, score);

		v.push_back(p);
	}
}

//������
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
		cout <<(*it).m_Nmae << "�ĵ÷�Ϊ:"<<" ";
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;
		sort(d.begin(), d.end());
		//ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();
		//ȡƽ����
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
		cout <<"������"<< (*it).m_Nmae<<"\t" << "���շ���:" << (*it).m_Score << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	//����ѡ��
	vector<Person> v;
	createPerson(v);

	//���
	setScore(v);
	
	//��ʾ���÷�
	showScore(v);

	system("pause");
	return 0;
}