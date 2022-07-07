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
招聘10个员工进入公司后，需要指定员工在哪个部门
随机分配员工的部门和工资
通过multimap进行信息插入，key部门编号和value员工
分部门显示员工信息
*/

//员工类
class Worker
{

public:
	string m_Name;
	int m_Salary;
};

//创建员工
void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];
		worker.m_Salary = rand() % 10001 + 10000;//10000-20000

		v.push_back(worker);
	}
}

//员工分组
void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int depId = rand() % 3;//0 1 2 部门号
		//将员工插入分组
		m.insert(make_pair(depId, *it));
	}
}

//按照分组显示员工信息
void showWorker(multimap<int, Worker>& m)
{
	cout << "策划部门:" << endl;
	multimap<int, Worker>::iterator pos = m.find(productmanager);
	int count = m.count(productmanager);
	int index = 0;
	for (;pos!=m.end()&&index<count;pos++,index++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------" << endl;
	cout<<"前端部门:"<<endl;
	pos = m.find(backendcoder);
	count = m.count(backendcoder);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
	}

	cout << "------------------------------"  << endl;
	cout << "后端部门:" << endl;
	pos = m.find(frontendcoder);
	count = m.count(frontendcoder);
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << "\t" << "工资：" << pos->second.m_Salary << endl;
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));
	//创建员工
	vector<Worker> vWorker;
	createWorker(vWorker);

	//员工分组
	multimap<int, Worker> mWorker;
	setGroup(vWorker, mWorker);

	//分组显示员工
	showWorker(mWorker);
	
	return 0;
}