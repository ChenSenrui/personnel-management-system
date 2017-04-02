#pragma once
#include "Employee.h"
#include<vector>

class Manager : virtual public Employee
{
public:
	Manager(string _name = "", int salary =12000);
	virtual int getSalary();
	virtual void display();
protected:
	int salary;
};

class Technician :virtual public Employee
{
public:
	Technician(string _name = "", int _workHour = 0,int baseWage = 260);
	virtual int getSalary();
	virtual void display();
protected:
	int workHour;//每周工作时间
	int baseWage;//每小时工资
};

class Salesman :virtual public Employee
{
public:
	Salesman(string _name = "", int _saleValue=0, int _baseSalary = 2000, double _profitRate = 0.05);
	virtual int getSalary();
	virtual void display();
	int getSaleValue()const { return saleValue; }
protected:
	int saleValue;//销售额
	int baseSalary;//基准工资
	double profitRate;//分红率
};

class SaleManager :public Manager, public Salesman
{
public:
	SaleManager(string _name, int _salary, int _saleValue, double _profitRate, double _profitRateControl);
	SaleManager(Manager _manager, double _profitRateControl = 0.04);//从经理中选拔
	SaleManager(Salesman _salesman, double _profitRateControl=0.04);//从销售员中选拔
	void setControls(vector<Salesman> salesmanlist);//将销售人员表存入
	void addControl(Salesman salesman);
	void showControl();
	virtual int getSalary();
	virtual void display();
private:
	vector<Salesman> controlList;//管理的人员
	double profitRateControl;
};
