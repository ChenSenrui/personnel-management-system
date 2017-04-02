#include "Employee.h"

using namespace std;
Employee::Employee(string _name, string _grade) : grade(_grade), name(_name)
{
	//改进：利用一个set来维护员工编号，保证了编号的唯一性
	while (usedNumber.count(++countOfEmployee));
	individualEmpNo = countOfEmployee;
	usedNumber.insert(countOfEmployee);
}

void Employee::setName(string name1) { name = name1; }


int Employee::setNumber(int num) 
{
	if (usedNumber.count(num))return 1;
	usedNumber.insert(num);
	individualEmpNo = num;
}


void Employee::setGrade(string grade1) { grade = grade1; }
int Employee::countOfEmployee = 0;
set<int> Employee::usedNumber;

Employee::~Employee()
{
}

istream & operator >> (istream & input, Employee & emp)
{
	cout << "请输入员工的姓名、编号(0表示不变)、职称、工资。" << endl;//提示
	int tmp;
	input >> emp.name >> tmp >> emp.grade;
	if (tmp)emp.individualEmpNo = tmp;
	return input;
}

ostream & operator<<(ostream & output, Employee & emp)
{
	output << "姓名:" << emp.name << endl;
	output << "编号:" << emp.individualEmpNo << endl;
	output << "职称:" << emp.grade << endl;
	output << "月薪:" << emp.getSalary() << endl;
	output << endl;
	return output;
}
