#pragma once
#include<string>
#include<iostream>
#include<set>
using namespace std;
class Employee
{
public:
	Employee(string _name="", string _grade="");
	virtual ~Employee();
	virtual int getSalary() = 0; //纯虚函数
	virtual void display() = 0;

	void setName(string name1);
	int setNumber(int num);//若返回值非0 说明设置失败
	void setGrade(string grade1);

	int getNumber()const { return individualEmpNo; }
	string getName()const { return name; }
	string getGrade()const { return grade; }

	friend istream& operator >> (istream& input, Employee& emp);
	friend ostream& operator << (ostream& output, Employee& emp);
protected:
	string name;
	int individualEmpNo;
	string grade;
private:
	static int countOfEmployee;//静态数据成员，自动得到新员工的编号
	static set<int> usedNumber;//已经被占用的编号
};
