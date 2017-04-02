#include"position.h"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
	vector<Manager> ManagerList;
	vector<Technician> TechnicianList;
	vector<Salesman> SalesmanList;
	ManagerList.push_back(Manager("Qiu Yong"));
	TechnicianList.push_back(Technician("Li Guolin", 4 * 60));
	TechnicianList.push_back(Technician("Zhang youhong", 4 * 53));
	TechnicianList.push_back(Technician("Su Ning", 4 * 50, 450));
	SalesmanList.push_back(Salesman("Cu Chulain", 5000));
	SalesmanList.push_back(Salesman("Arthur", 8000,2500));
	SalesmanList.push_back(Salesman("Gilgamesh", 16000, 2500, 0.1));
	//剩余的销售员略去
	//测试SaleManager
	SaleManager m1(ManagerList[0]);
	m1.setControls(SalesmanList);
	m1.display();


	return 0;
}
