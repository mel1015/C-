#include <iostream>
#include <iomanip>
#include "Permanent.h"
using namespace std;

Permanent::Permanent()
	:Employee()
{
	this->monthlyPay = 0;
}

Permanent::Permanent(char type, char* name, int number, int monthlyPay)
	:Employee(type, name, number)
{
	this->monthlyPay = monthlyPay;
}

Permanent::Permanent(const Permanent& other)
	:Employee(other)
{
	this->monthlyPay = other.monthlyPay;
}

Permanent::~Permanent()
{

}

int Permanent::getMonthlyPay()
{
	return this->monthlyPay;
}

void Permanent::setMonthlyPay(int monthlyPay)
{
	this->monthlyPay = monthlyPay;
}

void Permanent::showCommon()
{
	cout << setw(8) << this->getType() << setw(22) << this->getName() << setw(10) << this->getNumber() << setw(10) << this->getWage() << endl;
}

void Permanent::showDetail()
{
	cout << setw(8) << this->getType() << setw(22) << this->getName() << setw(10) << this->getNumber() << setw(15) << this->getMonthlyPay() << endl;
}

int Permanent::getWage()
{
	return this->monthlyPay;
}