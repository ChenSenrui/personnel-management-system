#include"position.h"
//Manager
Manager::Manager(string _name,int _salary) :Employee(_name, "manager"),salary(_salary)
{
}

int Manager::getSalary()
{
	return 12000;
}
void Manager::display()
{
	cout << "姓名:" << name << endl;
	cout << "编号:" << individualEmpNo << endl;
	cout << "职称:" << grade << endl;
	cout << "工资" << getSalary() << endl;
	cout << endl;
}
//Technicain
Technician::Technician(string _name, int _workHourPerMonth ,int _baseWage)
	:Employee(_name,"technician"),workHour(_workHourPerMonth),baseWage(_baseWage)
{
}

int Technician::getSalary()
{
	return(workHour * baseWage);
}
void Technician::display()
{
	cout << "姓名:" << name << endl;
	cout << "编号:" << individualEmpNo << endl;
	cout << "职称:" << grade << endl;
	cout << "每周工时:" << workHour << endl;
	cout << "时薪:" << baseWage << endl;
	cout << "工资" << getSalary() << endl;
	cout << endl;
}
//Salesman
Salesman::Salesman(string _name, int _saleValue, int _baseSalary, double _profitRate)
	:Employee(_name,"salesman"),saleValue(_saleValue),baseSalary(_baseSalary),profitRate(_profitRate)
{
}

int Salesman::getSalary()
{
	return (int)((double)baseSalary + saleValue * profitRate);
}
void Salesman::display()
{
	cout << "姓名:" << name << endl;
	cout << "编号:" << individualEmpNo << endl;
	cout << "职称:" << grade << endl;
	cout << "基准工资" << baseSalary << endl;
	cout << "销售额:" << saleValue << endl;
	cout << "提成率:" << profitRate << endl;
	cout << "工资" << getSalary() << endl;
	cout << endl;
}
//SaleManager
SaleManager::SaleManager(string _name, int _salary, int _saleValue, double _profitRate, double _profitRateControl)
	:Employee(_name,"SaleManager"),Manager(_name,_salary),Salesman(_name,_saleValue,_salary,_profitRate),profitRateControl(_profitRate)
{
	
}

SaleManager::SaleManager(Manager _manager, double _profitRateControl)
	:Employee(_manager),Manager(_manager),profitRateControl(_profitRateControl)//Salesman类直接调用默认参数的构造函数
{
	grade = "SaleManager";
	salary = baseSalary = 8000;
}

SaleManager::SaleManager(Salesman _salesman, double _profitRateControl)
	:Employee(_salesman), Salesman(_salesman), profitRateControl(_profitRateControl)//Salesman类直接调用默认参数的构造函数
{
	grade = "SaleManager";
	salary = baseSalary = 8000;
}


void SaleManager::setControls(vector<Salesman> salesmanlist)
{
	controlList = salesmanlist;
}

void SaleManager::addControl(Salesman salesman)
{
	controlList.push_back(salesman);
}

void SaleManager::showControl()
{
	cout << "销售经理 " << name << " 管理的人员：" << endl;
	for (vector<Salesman>::iterator it = controlList.begin(); it != controlList.end(); it++) {
		it->display();
	}
	cout << endl;
}

int SaleManager::getSalary()
{
	int tmpSalary = salary + saleValue*profitRate;
	int sumSaleValue = 0;
	for (vector<Salesman>::iterator it = controlList.begin(); it != controlList.end(); it++) {
		sumSaleValue += it->getSaleValue();
	}
	tmpSalary += sumSaleValue * profitRateControl;
	return tmpSalary;
}

void SaleManager::display()
{
	cout << "姓名:" << name << endl;
	cout << "编号:" << individualEmpNo << endl;
	cout << "职称:" << grade << endl;
	cout << "基准工资:" << salary << endl;
	cout << "销售额:" << saleValue << endl;
	cout << "提成率:" << profitRate << endl;
	cout << endl;
	showControl();
	cout << "管理人员提成率:" << profitRateControl << endl;
	cout << "工资:" << getSalary()<<endl;
	cout << endl;
}
