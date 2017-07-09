#pragma once

class Employee
{
public:
	Employee();
	Employee(char* name, int number, int pay);
	~Employee();

	char* getName();
	void setName(char* name);
	int getNumber();
	void setNumber(int number);
	int getPay();
	void setPay(int pay);
	void showDetail();

private:
	char* name;
	int number;
	int pay;
};