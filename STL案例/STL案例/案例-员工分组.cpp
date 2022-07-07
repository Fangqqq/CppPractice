#include <iostream>
using namespace std;
#include<vector>
#include<string>
#include<ctime>
#include<map>

#define productmanager 0
#define frontendcoder 1
#define backendcoder 2



/*
��Ƹ10��Ա�����빫˾����Ҫָ��Ա�����ĸ�����
�������Ա���Ĳ��ź͹���
ͨ��multimap������Ϣ���룬key���ű�ź�valueԱ��
�ֲ�����ʾԱ����Ϣ
*/

//Ա����
class Worker
{

public:
	string m_Name;
	int m_Salary;
};

//����Ա��
void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10001 + 10000;//10000-20000

		v.push_back(worker);
	}
}

//Ա������
void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int depId = rand() % 3;//0 1 2 ���ź�
		//��Ա���������
		m.insert(make_pair(depId, *it));
	}
}

//���շ�����ʾԱ����Ϣ
void showWorker(multimap<int, Worker>& m)
{
	cout << "�߻�����:" << endl;
	multimap<int, Worker>::iterator pos = m.find(productmanager);
	int count = m.count(productmanager);
	int index = 0;
	for (;pos!=m.end()&&index<count;pos++,index++)
	{
		cout << "������" << pos->second.m_Name << "\t" << "���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------" << endl;
	cout<<"ǰ�˲���:"<<endl;
	pos = m.find(backendcoder);
	count = m.count(backendcoder);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << "\t" << "���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------"  << endl;
	cout << "��˲���:" << endl;
	pos = m.find(frontendcoder);
	count = m.count(frontendcoder);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << "\t" << "���ʣ�" << pos->second.m_Salary << endl;
	}
}

int main()
{
	//���������
	srand((unsigned int)time(NULL));
	//����Ա��
	vector<Worker> vWorker;
	createWorker(vWorker);

	//Ա������
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);

	//������ʾԱ��
	showWorker(mWorker);
	
	return 0;
}