#include <iostream>
#include <iomanip>
#include "Employee.h"
using namespace std;

Employee::Employee()
{
	this->name = nullptr;
	this->number = 0;
	this->pay = 0;
}

Employee::Employee(char* name, int number, int pay)
	: Employee()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->number = number;
	this->pay = pay;
}

Employee::Employee(const Employee& other)
	: Employee()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);

	this->number = other.number;
	this->pay = other.pay;
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		if (this->name != nullptr)
		{
			delete[] this->name;
			this->name = nullptr;
		}
		this->name = new char[strlen(other.name) + 1];
		strcpy_s(this->name, strlen(other.name) + 1, other.name);

		this->number = other.number;
		this->pay = other.pay;
	}

	return *this;
}

Employee::~Employee()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		name = nullptr;
	}
}

char* Employee::getName()
{
	return this->name;
}

void Employee::setName(char* name)
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

int Employee::getNumber()
{
	return this->number;
}

void Employee::setNumber(int number)
{
	this->number = number;
}

int Employee::getPay()
{
	return this->pay;
}

void Employee::setPay(int pay)
{
	this->pay = pay;
}

void Employee::showDetail()
{
	cout << setw(22) << this->name << setw(10) << this->number << setw(8) << this->pay << endl;

}