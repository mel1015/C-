#pragma once

class Employee
{
private:
	char type;
	char* name;
	int number;
	Employee* Prev_Object;
	Employee* Next_Object;

public:
	Employee();
	Employee(char type, char* name, int number);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	virtual ~Employee();

	char getType();
	void setType(char type);
	char* getName();
	void setName(char* name);
	int getNumber();
	void setNumber(int number);
	Employee* getPrev_Object();
	void setPrev_Object(Employee* ptr);
	Employee* getNext_Object();
	void setNext_Object(Employee* ptr);

	virtual void showCommon() = 0;
	virtual void showDetail() = 0;
	virtual int getWage() = 0;
};