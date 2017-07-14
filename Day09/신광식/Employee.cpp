#include <iostream>
#include "Employee.h"
using namespace std;

Employee::Employee()
{
	this->type = NULL;
	this->name = nullptr;
	this->number = 0;
	this->Prev_Object = nullptr;
	this->Next_Object = nullptr;
}

Employee::Employee(char type, char* name, int number)
	: Employee()
{
	if (this->name != nullptr)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->type = type;
	this->number = number;
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

	this->type = other.type;
	this->number = other.number;
	this->Prev_Object = other.Prev_Object;
	this->Next_Object = other.Next_Object;
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

		this->type = other.type;
		this->number = other.number;
		this->Prev_Object = other.Prev_Object;
		this->Next_Object = other.Next_Object;
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

char Employee::getType()
{
	return this->type;
}

void Employee::setType(char type)
{
	this->type = toupper(type);
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

Employee* Employee::getPrev_Object()
{
	return this->Prev_Object;
}

void Employee::setPrev_Object(Employee* ptr)
{
	this->Prev_Object = ptr;
}

Employee* Employee::getNext_Object()
{
	return this->Next_Object;
}

void Employee::setNext_Object(Employee* ptr)
{
	this->Next_Object = ptr;
}