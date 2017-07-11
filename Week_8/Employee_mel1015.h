#pragma once

class Employee
{
private:
	char* name;
	int number;
	int pay;

public:
	Employee();
	Employee(char* name, int number, int pay);
	Employee(const Employee& other);
	Employee& operator=(const Employee& other);
	~Employee();

	char* getName();
	void setName(char* name);
	int getNumber();
	void setNumber(int number);
	int getPay();
	void setPay(int pay);
	void showDetail();
};