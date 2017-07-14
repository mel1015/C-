#include<iostream>
#include<iomanip>
#include"Sales.h"
using namespace std;

Sales::Sales()
	:Permanent()
{
	this->sales = 0;
}

Sales::Sales(char type, char* name, int number, int monthlyPay, int sales)
	:Permanent(type, name, number, monthlyPay)
{
	this->sales = sales;
}

Sales::Sales(const Sales& other)
	:Permanent(other)
{
	this->sales = other.sales;
}

Sales::~Sales()
{

}
int Sales::getSales()
{
	return this->sales;
}
void Sales::setSales(int sales)
{
	this->sales = sales;
}

void Sales::showCommon()
{
	cout << setw(8) << this->getType() << setw(22) << this->getName() << setw(10) << this->getNumber() << setw(10) << this->getWage() << endl;
}

void Sales::showDetail()
{
	cout << setw(8) << this->getType() << setw(22) << this->getName() << setw(10) << this->getNumber() << setw(15) << this->getMonthlyPay() << setw(15) << this->getSales() << endl;
}

int Sales::getWage()
{
	return this->getMonthlyPay() + (this->sales * 0.3);
}
