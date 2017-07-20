#include<iostream>
#include<iomanip>
#include"Temporary.h"
using namespace std;

Temporary::Temporary()
	:Employee()
{
	this->hourlyPay = 0;
	this->time = 0;
}

Temporary::Temporary(char type, char* name, int number, int hourlyPay, int time)
	:Employee(type, name, number)
{
	this->hourlyPay = hourlyPay;
	this->time = time;
}

Temporary::Temporary(const Temporary& other)
	:Employee(other)
{
	this->hourlyPay = other.hourlyPay;
	this->time = other.time;
}

Temporary::~Temporary()
{

}

int Temporary::getHourlyPay()
{
	return this->hourlyPay;
}

void Temporary::setHourlyPay(int hourlyPay)
{
	this->hourlyPay = hourlyPay;
}

int Temporary::getTime()
{
	return this->time;
}

void Temporary::setTime(int time)
{
	this->time = time;
}

void Temporary::showCommon()
{
	cout << setw(8) << this->getType() << setw(22) << this->getName() << setw(10) << this->getNumber() << setw(10) << this->getWage() << endl;
}

void Temporary::showDetail()
{
	cout << setw(8) << this->getType() << setw(22) << this->getName() << setw(10) << this->getNumber() << setw(15) << this->getHourlyPay() << setw(8) << this->getTime() << endl;
}

int Temporary::getWage()
{
	return this->hourlyPay;
}
